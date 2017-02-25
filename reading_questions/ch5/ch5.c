/*
 * Exercises for ch5 or TOS
 */

#include <stdio.h>

/*
 * Code for question 2
 * Two's complement of 12 using XOR ^
 */
void twos_complement(int num) {
	// flip all the bits: -1 is a bunch of 1s
	// then add 1
	num = (num ^ -1) + 1;
	printf("%i", num);
}

/*
 * Code for question 5
 * Flips the case of all letters in the string
 */
void change_case(char *string, int len) {
	for (int i = 0; i < len; i++) {
		string[i] ^= 32;
	}
}

int main() {
	twos_complement(12);
	char str[] = "hello";
	change_case(str, 5);
	printf("%s",str);
	return 0;
}
