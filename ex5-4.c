/*Write the function strend(s,t), which returns 1 if the string t occurs at the end of the string s, and zero otherwise.*/

#include <stdio.h>
#include <string.h>

int str_end(char *, char *);
void getstr(char *);

int str_end(char *s, char *t)
{
	int len_s, len_t;
	
	len_s = strlen(s);
	len_t = strlen(t);

	if (len_t > len_s) return 0;
      
	//move pointer to potential starting position of t within s
	s += len_s - len_t;

	while(*s != '\0' && *t != '\0')
	{
		if(*s != *t) return 0;
		s++;
		t++;
	}

	return (*t == '\0')?1:0;
    
}

int main()
{
    char s[100], t[100];
    printf("enter first char:");
    getstr(s);
    printf("enter second char:");
    getstr(t);
    printf("result: %d\n",str_end(s, t));
}

void getstr(char *s)
{
    int c;
    while((c = getchar())!='\n')
        *s++ = c;
    *s = '\0';
}
                                                                                                                  
                                                                                                                  
                  
