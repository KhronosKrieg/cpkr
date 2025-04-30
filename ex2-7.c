/* Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.*/


#include <stdio.h>

void print_binary(unsigned);
unsigned invert(unsigned,int,int);

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
    unsigned x;
    int p,n;
    printf("Enter x (decimal):");
    scanf("%u",&x);
    printf("Enter position p(0 based from right):");
    scanf("%u",&p);
    printf("Enter number of bits n:");
    scanf("%d",&n);
  
 
    printf("x          ="); print_binary(x);
  

    unsigned result = invert(x,p,n);

    printf("R          ="); print_binary(result);

    return 0;

}


unsigned invert(unsigned x, int p, int n)
{
	unsigned mask;

	mask = ((1U << n) -1) << (p - n +1);

	return x ^ mask;//XOR
}
