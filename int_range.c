#include <stdio.h>

int main()
{
	int dpos32 = (-2147483648 > 0); /* false on C99, but TRUE on C90! (converted to unsigned) */
	int hpos32 = (0x80000000 > 0); /* use -ansi option to see the difference */
	int htmin32 = 0x80000000;
	printf("%d\n", htmin32);
	printf("%d\n", dpos32);
	printf("%d\n", hpos32);
}