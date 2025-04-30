/* 0Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged. */


#include <stdio.h>

void print_binary(unsigned);
unsigned setbits(unsigned, int, int, unsigned);

void print_binary(unsigned num)
{
	for(int i = sizeof(unsigned) * 8 -1 ; i>=0 ;i--)
	{
		printf("%d",(num >> i) & 1);
		if (i % 4 == 0 ) printf(" ");
	}
	printf("\n");
}

int main()
{
	unsigned x,y;
	int p,n;
	printf("Enter x (decimal):");
	scanf("%u",&x);
	printf("Enter position p(0 based from right):");
	scanf("%u",&p);
	printf("Enter number of bits n:");
	scanf("%d",&n);
	printf("Enter y (decimal):");
	scanf("%u",&y);

	printf("\nBefore:\n");
	printf("x          ="); print_binary(x);
	printf("y          ="); print_binary(y);

	unsigned result = setbits(x,p,n,y);

	printf("R          ="); print_binary(result);
	
	return 0;

}

unsigned setbits(unsigned x, int p, int n, unsigned  y)
{
	unsigned  mask, y_bits;
	printf("1          ="); print_binary(1);
    printf("1U<<n      =");print_binary(1U<<n);
	printf("(1U<<n) -1 ="); print_binary((1U<<n) - 1);
	mask  =(1U << n) - 1 ;
	y_bits = (y & mask);
	y_bits = y_bits << (p-n+1);
    printf("r          =");
    print_binary(y_bits);
	x =( ( ~(((1 << n) - 1) << (p-n+1))) & x );
	printf("x          =");
	print_binary(x);

	return x | y_bits;



}

