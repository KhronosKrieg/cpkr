/* Define a macro swap(t,x,y) that interchanges two arguments of type t. (Block structure will help.) */

#define swap(t,x,y)  do { \
	t temp  = x;          \
	x = y;                \
	y = temp;             \
} while(0);
	

#include <stdio.h>

int main()
{
	int x=2, y =3;
	swap(int, x, y);
	printf("x: %d, y: %d \n",x,y);
	return 0;
}
