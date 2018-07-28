#include <stdio.h>

int ismult32(unsigned x);

int main()
{
	int L1 = 3;
	void *ptr = &&L1;
	if (1)
		goto *L1; // goto *L1 is no different than goto L1
	// computed goto is best used when indexing a static jump table array,
	// in which case it computes the address to go to
	goto L2;
L1:
	printf("Hello\n");
	printf("Goodbye\n");
	printf("%d\n", L1); // refers to variable L1 (no collision with label L1
L2:	
	printf("%d\n", ismult32(96));
	
	return 0;
}

int ismult32(unsigned x)
{
	return !(x & 0x1f); // Simply indicates whether bits 0 to 4 are cleared
	// if they are, then the number is a multiple of 32
}
