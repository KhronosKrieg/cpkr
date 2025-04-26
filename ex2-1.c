/* write a program to determine the ranges of char, short, int and long variables both signed and 
unsigned , by printing appropriate values from standard headers and by direct computation. Harder if 
you compute them. Determine the ranges of the various floating-point types.*/

#include <stdio.h>
#include <limits.h>
#include <float.h>


 int main()
 {
   char a='a',b='b';
    
   printf("From limits.h:\n");
   printf("Signed int: min = %d, max = %d\n",INT_MIN, INT_MAX);
   printf("Unsigned int: max = %u \n",UINT_MAX);
   printf("Signed char: min y= %c, max = %c\n",CHAR_MIN,CHAR_MAX);
   printf("Unsigned char:max=%uc \n",UCHAR_MAX);
       
   printf("Signed short: min= %hd, max = %hd\n",SHRT_MIN,SHRT_MAX);
   printf("Unsigned short:max=%uhd \n",USHRT_MAX);
        
   printf("Signed long: min= %ld, max = %ld\n",LONG_MIN,LONG_MAX);
   printf("Unsigned long:max=%ul \n",ULONG_MAX);

  /*compute ranges for int*/
   
   printf("\nComputed:\n");
   
   unsigned int u = 0;
   while((++u)!=0); //overflows to 0
   printf("Computed unsigned int max = %u\n", --u);

   int si = 1;
   int max = 1;
   while((max << 1)>0)
   {
     max = max << 1;
   }
   printf("Computed signed int max = %d\n",max+(max - 1));
   printf("Computed signed in min = %d\n", -1*(max+(max-1))-1);
   printf("si value: %d\n",si);

   printf("size of (char) = %d\n",sizeof(char));
   printf("size of (int) = %d\n",sizeof(int));
   printf("size of (short) = %d\n", sizeof(short));
   printf("size of (long) = %d\n",sizeof(long));
   printf("size of (unsigned int) = %d\n",sizeof(unsigned int));
   printf("size of (unsigned char) = %d\n",sizeof(unsigned char));
   printf("size of (signed int) = %d\n", sizeof(signed int));
   printf("Address of a:%p, in unsigned integer format:%u\n",(void *)&a,&a);
   printf("Address of b:%p, in unsigned integer format:%u\n",(void *)&b,&b);
   printf("size of char:%td\n",(&b-&a));//ptrdiff_t, signed
  }


