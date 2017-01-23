/*
 * Program for testing different optimizations.
 *
 * 1. Using the optimization flag -O2 removes movl $5, -4(%rbp) from the assembly.
 */

#include <stdio.h>

int main() {
	int x = 5; // Can't find the corresponding assembly code??

	/*
	 * 2. printf
	 *
	 * without optimitazion, printing x does:
	 * subq $16, %rsp : subtract 16 from %rsp to move stack pointer
	 * later, addq $16, %rsp is called to move the stack pointer back
	 * leaq L_.str(%rip), %rdi
	 * multiple movl instructions and a movb instruction
	 * callq _printf
	 * includes a section for strings where "%i" is stored
	 * using optimization decreases the number of movl instructions and does not move the stack pointer
	 */
	// printf("%d", x);
	
	/*
	 * 3. Add
	 * Optimization moves the stack pointer around a lot less.
	 * The un-optimized assembly does a lot of modification to the stack pointer register.
	 */
	int y = x + 1;
	printf("%d", y);
}

