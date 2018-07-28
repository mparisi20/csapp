#include <stdio.h>

int sum(int, int);
int greaterthan10(int x);
int shift_left2_rightn(int, int);
unsigned float2bit(float);
double bit2double(unsigned, unsigned);

int main()
{
	char c = -1;
	unsigned a = (unsigned) c; // Sign extension! Only depends on source signedness
	printf("%u\n", a);
	
	unsigned char uc = 255;
	int b = (int) uc; // Zero extension!
	printf("%u\n", b);
	
	// conclude that the choice of zero or sign extension depends on the 
	// type of the source, not the destination.
	
	printf("%d\n", 0xFF); // C compiler treats the literal 0xFF as an int with value 0x000000FF 
	// it just pads it with zeros until the number is 32-bit
	
	// Bit representations of floating point type
	float f = 0.11;
	printf("%f ... %u\n", f, float2bit(f)); // the float2bit function shows you the bit pattern of f
	// never try to printf a floating point number using any format specifier besides %f, %e, or %g
	
	union {
		struct {
			short a;
			int b;
			short c;
		} internal1;
		struct {
			double d;
		} internal2;
	} u1;
	
	union {
		struct {
			short a;
			short b;
			int c;
		} internal1;
		struct {
			double d;
		} internal2;
	} u2;
	
	printf("sizeof(u1) = %d\n", sizeof(u1));
	printf("sizeof(u2) = %d\n", sizeof(u2));
	
	// u2 and u1 are functionally equivalent, but u1 takes up twice the memory
	// due to the misalignment of the members of its internal1 struct.
	// In contrast, u2 declares its members in such a way that no padding is necessary
	// to align a, b, c, and d simultaneously.
	
	struct {
		int a;
		int b;
		char c;
	} s1[2];
	printf("\nsizeof(s1) = %d\n", sizeof(s1));
	
	// padding is put at the end of each element of s1 so that subsequent elements are aligned
	
	int fun(int x, int *p);
	int (*fp)(int, int *);
	fp = fun;
	int y = 1;
	int result = fp(3, &y); // no need to use *... fp is known to be a function pointer and x86 jumps to its address
	
	
	
	
	return 0;
}

int fun(int x, int *p)
{
	return 0;
}
	
	

unsigned float2bit(float f)
{
	union {
		float f;
		unsigned u;
	} temp;
	temp.f = f;
	return temp.u; // return the bit representation of f (same 4 bytes of memory, but interpreted as unsigned)
}

double bit2double(unsigned lsdword, unsigned msdword) // argument names reflect little-endianness
{
	union {
		unsigned a[2];
		double d;
	} temp;
	temp.a[0] = lsdword; // define the bit pattern
	temp.a[1] = msdword; // from the arguments
	return temp.d; // return that bit pattern interpreted as a double
}

int accum = 0;

int sum(int x, int y)
{
	int t = x + y;
	accum += t;
	return t;
}

int greaterthan10(int x)
{
	return (x > 10) ? 1 : 0; // this demonstrates the setg and movzbl opcodes
}

int shift_left2_rightn(int x, int n)
{
	x <<= 2; // opcode is shll
	x >>= n; // opcode is sarl
	return x;
}