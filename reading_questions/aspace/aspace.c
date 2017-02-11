/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int global;

void print_addr() {
	int local = 5;
	printf ("Address of local in function is %p\n", &local);
}

int main ()
{
    int local = 5;
    void *p = malloc(128);
	void *p2 = malloc(128);
    printf ("Address of main is %p\n", main);
    printf ("Address of global is %p\n", &global);
    printf ("Address of local is %p\n", &local);
    print_addr();
    printf ("Address of p is %p\n", p);
	printf ("Address of p2 is %p\n", p2);

	void *p3 = malloc(31);
	void *p4 = malloc(31);
    
	printf ("Address of p3 is %p\n", p3);
	printf ("Address of p4 is %p\n", p4);


    return 0;
}
