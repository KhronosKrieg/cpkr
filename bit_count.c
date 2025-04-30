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
	int b;
	for(b = 0; x!= 0; x>>=1)
	{
		if(x & 01) b++;
		//print_binary(x);
	}

	return b;
}
