/*Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n positions*/


#include <stdio.h>
#define SIZE 32
unsigned rightrot(unsigned, int);
void print_ninary(unsigned);


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
    int n;
    printf("Enter x (decimal):");
    scanf("%u",&x);
    printf("Enter number of bits n:");
    scanf("%d",&n);

    printf("x          ="); print_binary(x);

    unsigned result = rightrot(x,n);

    printf("R          ="); print_binary(result);
    return 0;

}



unsigned rightrot(unsigned x, int n)
{
	if( n >= SIZE) n = n % SIZE;

	unsigned right_bits,left_bits;

	right_bits = x >> n;
	left_bits =(x & ((1U << n)-1)) << (SIZE - n);

	printf("right_bits ="); print_binary(right_bits);
	printf("left_bits  ="); print_binary(left_bits);


	return right_bits ^ left_bits;

	
}


/* 
  Enter x (decimal):111111111111111                                                                                   
Enter number of bits n:5
x          =0001 0010 0100 1110 1111 0001 1100 0111 
right_bits =0000 0000 1001 0010 0111 0111 1000 1110 
left_bits  =0011 1000 0000 0000 0000 0000 0000 0000 
R          =0011 1000 1001 0010 0111 0111 1000 1110 
*/

