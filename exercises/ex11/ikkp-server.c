#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

int listener_d = 0;

void error(char *msg) {
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(1);
}

void handle_shutdown(int sig) {
	if (listener_d) {
		close(listener_d);
	}

	fprintf(stderr, "Bye!\n");
	exit(0);
}

int open_listener_socket() {
	int s = socket(PF_INET, SOCK_STREAM, 0);
	if (s == -1) {
		error("Can't open socket");
	}

	return s;
}

int open_client_socket() {
	static struct sockaddr_storage client_address;
	static unsigned int address_size = sizeof(client_address);
	int s;

	if ((s = accept(listener_d, (struct sockaddr *)&client_address, &address_size)) == -1) {
		error("Can't open client socket");
	}

	return s;
}

void bind_to_port(int socket, int port) {
	struct sockaddr_in name;
	name.sin_family = PF_INET;
	name.sin_port = (in_port_t)htons(port);
	name.sin_addr.s_addr = htonl(INADDR_ANY);
	int reuse = 1;

	if (setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int)) == -1) {
		error("Can't set the reuse option on the socket");
	}

	if (bind(socket, (struct sockaddr *)&name, sizeof(name)) == -1) {
		error("Can't bind to socket");
	}
}

int say(int socket, char *s) {
	int result = send(socket, s, strlen(s), 0);
	if (result == -1) {
		// don't call error()
		// don't want to stop server if there's a problem with just one client
		fprintf(stderr, "%s: %s\n", "Error talking to the client", strerror(errno));
	}
	return result;
}

int read_in(int socket, char *buf, int len) {
	char *s = buf;
	int slen = len;
	int c = recv(socket, s, slen, 0);
	// keep reading until no more chars or reach '\n'
	while ((c > 0) && (s[c-1] != '\n')) {
		s += c;
		slen -= c;
		c = recv(socket, s, slen, 0);
	}
	if (c < 0) {
		// in case there's an error
		return c;
	} else if (c == 0) {
		// nothing read, so send an empty string
		buf[0] = '\0';
	} else {
		// replace '\r' with '\0'
		s[c-1]='\0';
	}
	return len - slen;
}

int catch_signal(int sig, void (*handler)(int)) {
	struct sigaction action;
	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	return sigaction(sig, &action, NULL);
}

int main(int argc, char *argv[]) {
	if (catch_signal(SIGINT, handle_shutdown) == -1) {
		// call handle_shutdown() if ctrl-c is hit
		error("Can't set the interrupt handler");
	}
	listener_d = open_listener_socket();
	bind_to_port(listener_d, 30000);

	if (listen(listener_d, 10) == -1) { // set listen queue len to 10
		error("Can't listen");
	}

	struct sockaddr_storage client_addr;
	unsigned int address_size = sizeof(client_addr);

	puts("Waiting for connection");
	char buf[255];

	while (1) {
		// int connect_d = open_client_socket();
		int connect_d = accept(listener_d, (struct sockaddr *)&client_addr, &address_size);

		if (connect_d == 1) {
			error("Can't open seconday socket");
		}

		if (!fork()) {
			close(listener_d);
			


		if (say(connect_d, "Internet Knock-Knock Protocol Server\r\nVersion 1.0\r\nKnock! Knock!\r\n> ") != -1) {
			read_in(connect_d, buf, sizeof(buf));
			if (strncasecmp("Who's there?", buf, 12)) {
				say(connect_d, "You should say 'Who's there?'!'");
			} else {
				if (say(connect_d, "Oscar\r\n> ") != -1) {
					read_in(connect_d, buf, sizeof(buf));
					if (strncasecmp("Oscar who?", buf, 10)) {
						say(connect_d, "You should say 'Oscar who?'!\r\n");
					} else {
						say(connect_d, "Oscar silly question, you get a silly answer\r\n");
					}
				}
			}
		}
		close(connect_d); // close socket
		exit(0);
		}
		close(connect_d);
	}
	return 0;
}


