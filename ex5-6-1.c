/* Rewrite appropriate programs from earlier chapters and exercises with pointers
instead of array indexing. Good possibilities include getline (Chapters 1 and 4), atoi, itoa,
and their variants (Chapters 2, 3, and 4), reverse (Chapter 3), and strindex and getop
(Chapter 4).*/

#include <stdio.h>
#define MAXLINE 1000

int get_line(char *);


int main()
{
	char line[MAXLINE];
	int len;
	while((len = get_line(line))>0)
		printf("%s\n",line);
}

int get_line(char *line)
{
	int c;
	char *start = line;
	while((c = getchar())!=EOF && c!='\n'&& (line - start)<MAXLINE -1)
		*line++ = c;
	*line = '\0';
	return line -start;

}
