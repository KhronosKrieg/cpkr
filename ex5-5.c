/*Write versions of the library functions strncpy, strncat, and strncmp, which operate on at most the first n characters of their argument strings. For example, strncpy(s,t,n) copies at most n characters of t to s.*/

#include <stdio.h>
#include <string.h>

char *strn_cpy(char *, const char *, int );
char *strn_cat(char *, const char *,int);
int  strn_cmp(const char *, const char *,int );
void getstr(char *);


int main()
{
	int n;
    char s[100], s1[100];
	const char ct[100],s2[100],ct2[100];;
    printf("enter first char:");
    getstr(s);
    printf("enter second char:");
    getstr((char *)ct);
	printf("enter string 1 to compare:");
    getstr((char *)s2);
    printf("enter string 2 to compare:");
    getstr((char *)ct2);
	printf("enter n:");
	scanf("%d",&n);
	strn_cat(s,ct,n);
    printf("string_concat result:%s\n",s);
	strn_cpy(s1,ct,n);
	printf("string copy result:%s\n",s1);
	printf("string compare result: %d\n",strn_cmp(s2,ct2,n));
}

char *strn_cat(char *s,const char *t, int n)
{
	char *original_s = s; // Store the original pointer
	int i;

	while(*s !='\0')
		s++;

	for(i=0;(i<n && *t!='\0');s++,t++, i++)
		*s = *t;
	*s='\0';
	return original_s;

}

void getstr(char *s)
{
    int c;
    while((c = getchar())!='\n')
        *s++ = c;
    *s = '\0';
}


char *strn_cpy(char *s, const char *t, int n)
{
	char *original_s = s;
	while(n >0  && *t!='\0')
	{
		*s = *t;
		s++;
		t++;
		n--;
	}
	*s = '\0';
	return original_s;
}

int strn_cmp(const char *s, const char *t,int  n)
{
	while(n>0 && *s!= 0 && *s == *t)
	{
		//if(*s != *t) return 0;
		s++;
		t++;
		n--;
	}
	// If n became 0 or both strings reached null terminators simultaneously,
    // the first n characters (or fewer) were equal.
    if (n == 0 || (*s == '\0' && *t == '\0')) {
        return 0; // Strings are equal up to n characters or their end
	}
	else
		return (unsigned char)*s - (unsigned char)*t;
}

