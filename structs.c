#include <stdio.h>

#define XMAX	200
#define	YMAX	150

struct point makepoint(int, int, int, int, int);

struct point {
	int x;
	int y;
	int z;
	int a;
	int b;
};

struct rect {
	struct point pt1;
	struct point pt2;
};

int main()
{
	struct rect screen;
	struct point middle;
	
	screen.pt1 = makepoint(1, 2, 3, 4, 5);
	screen.pt2 = makepoint(XMAX, YMAX, 4, 5, 6);
	middle = makepoint((screen.pt1.x + screen.pt2.x)/2,
						(screen.pt1.y + screen.pt2.y)/2, 0, 0, 0);
	printf("midpoint: (%d,%d)\n", middle.x, middle.y);
	
	struct point origin, *pp;
	pp = &origin;
	int a  = (*pp).x;
	a = pp->x;
	
	
	return 0;
}

/* makepoint: make a point from x and y components */
struct point makepoint(int x, int y, int z, int a, int b)
{
	struct point temp;
	
	temp.x = x;
	temp.y = y;
	temp.z = z;
	temp.a = a;
	temp.b = b;
	return temp;
}
