/* In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x. Explain why. Use this observation to write a faster version of bitcount.*/



#include <stdio.h>

void print_binary(unsigned);
int bitcount(unsigned);

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

    printf("x          ="); print_binary(x);

    int  result = bitcount(x);

    printf("R          =%d",result);
    return 0;

}


int bitcount(unsigned x)
{
/* x & (x-1) deletes the right most bit, so until complete x becomes zero that many 1's will get deleted*/
    int b;
    for(b = 0; x!= 0;x =  x&(x-1))
    {
        b++;
    }

    return b;
}

