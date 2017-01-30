/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

/*
 * Exercise 2 questions:
 * 1. This program is intended to create an array of length 5
 * 	  with all values set to 42 (this is done by calling foo()).
 * 	  Calling bar() is then supposed to create another array of
 * 	  length 5, where values are the index number.
 * 	  Then, the values of the array created by foo() are supposed
 * 	  to be printed in order of index (so 5 '42's should print).
 *
 * 2. Compliling creates a warning that the return value of foo()
 * 	  is a pointer to the local variable named array. This means
 * 	  that the value of the address of the array is being returned.
 *
 * 3. Each on its own line, 0, 1510002322, 0, 0, 0 are printed.
 * 	  In foo, 'return array' returns the int value of the pointer
 * 	  to the local array variable. In main(), this is assigned to
 * 	  int *array. Thus, when array[i] is printed, the large number
 * 	  is actually the address of the 0th element from the local
 * 	  array in foo(). The other printed numbers are 0 because
 * 	  none of them have been set to anything.
 *
 * 4. Commenting out the print statements causes the addresses of
 * 	  the local arrays to be printed. Both of these addresses are
 * 	  the same hex value. Then the same 5 numbers (0s and the large
 * 	  int) are still printed.
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
	/*
	 * 1. Original code is supposed to create an array of len 5,
	 * 	  set all values to 42, then return the array's pointer.
	 */
    int i;
    int array[SIZE];
	
	// this prints the address of array
    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
	array[i] = 42;
    }

    return array;
}

void bar() {
    int i;
    int array[SIZE];

	// this prints the address of array
    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
	array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
	printf("%d\n", array[i]);
    }

    return 0;
}
