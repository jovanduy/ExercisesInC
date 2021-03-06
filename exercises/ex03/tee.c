/*
 * Implementation of UNIX's tee command:
 * write what is read from stdin to stdout
 * and any files specified as command line args
 *
 * Usage (if compiled into file tee): ./tee <file_name>
 *
 * author: @jovanduy
 *
 * Exercise questions:
 * 3) Googling things and HFC Ch. 3 were both pretty helpful.
 *    Using the tutorialspoint.com website was pretty useful
 *    in figuring out how to use different functions. I've 
 *    found that it is VERY important to code incrementally
 *    and test after doing every single small thing. Next time,
 *    I will make sure not to write a bunch of code, only to
 *    try executing it to find that nothing actually works.
 *    Another thing that slowed me down was figuring out how
 *    to loop through n files.
 *
 * 4) There are some stackoverflow solutions for how to 
 *    implement tee, but all of them use a bunch of
 *    functions that I have never seen before (such as
 *    dup2). Also they used fork() or popen().
 *
 *    More professional implementations such as the ones listed
 *    in the Lecture 07 on the class website actually did not
 *    use too many functions I had never seen. Furthermore,
 *    they used a bunch of structs, which I'm not sure how to
 *    use properly quite yet (note: my implementation was
 *    written in very early Februrary, which was before we
 *    learned about structs).
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/*
 * Processes the command arguments.
 * int argc: number of args
 * char *argv[]: the args themselves
 * *append: store value if append flag is on
 */
void process_args(int argc, char *argv[], int *append) {
	char ch;
	while ((ch = getopt(argc, argv, "a")) != EOF) {
		switch(ch) {
			case 'a':
				*append = 1;
				break;
			default:
				fprintf(stderr, "Unknown option: '%s'\n", optarg);
				exit(-1);
		}
	}
}

int main(int argc, char *argv[]) {
	char buff[100];
	int append = 0;
	int num_files = 0;

	// process the arguments and set argc and argv to skip over flags
	process_args(argc, argv, &append);
	argc -= optind;
	argv += optind;
	num_files = argc;

	// open all files
	FILE *fp[num_files];

	for (int i = 0; i < num_files; i++) {
		fp[i] = fopen(argv[i], append ? "a" : "w");
		if (fp[i] == NULL) {
			puts("error: could not open a file");
		}
	}

	while (scanf("%s", buff) > 0) {
		// write to all the files
		for (int i = 0; i < num_files; i++) {
			if (fprintf(fp[i], "%s\n", buff) < 0) {
				puts("error writing to a file");
				return 1;
			}
		}
		// print to stdout
		printf("%s\n", buff);
	}

	// close files
	for (int i = 0; i < num_files; i++) {
		fclose(fp[i]);
	}

	return 0;
}
