#include <stdio.h>

int switch_eg(int, int);

int main()
{
	printf("%d\n", switch_eg(5, 100));
	return 0;
}

int switch_eg(int x, int n) {
	int result = x;
	switch (n) {	
	case 100:
		result *= 13;
		break;
	case 102:
		result += 10;
		/* Fall through */
	case 103:
		result += 11;
		break;
	case 104:
	case 106:
		result *= result;
		break;
	default:
		result = 0;
	}	
	return result;
}
