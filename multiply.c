#include <stdio.h>

int div16(int);
int fastdiv16(int);

int main()
{
	char a = 127;
	char b = 127;
	char c = a*b; 
	// c is truncated to 1, because the true result is placed in %eax
	// but only %al (the lowest 8 bits of %eax), is moved into variable c
	printf("%d\n", c);
	printf("%d\n", div16(-100));
	printf("%d\n", fastdiv16(-100));
	return 0;
}

int tmult_ok(int x, int y)
{
	long long pll = (long long) x * y; // cast x to long long before multiplying by y
	return pll == (int) pll; // see if casting pll to an int changes the value
	// if they are equal, then no overflow has occurred
}

int div16(int x)
{
	return x/16;
}

int fastdiv16(int x)
{
	int bias = (x >> 31) & 0xF;
	return (x + bias) >> 4;
}