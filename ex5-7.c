/* Rewrite readlines to store lines in an array supplied by main, rather than calling alloc to maintain storage. How much faster is the program?*/

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /*max lines to be sorted*/
#define MAXLEN 1000 /*max length of any input line */
#define MAXSTORAGE 100000

char* lineptr[MAXLINES]; /*pointers to text lines */

int readlines(char* lineptr[], char *,int nlines);
void writelines(char* lineptr[], int nlines);
int get_line(char*, int);

void qsort(char* lineptr[], int left, int right);

/*sort input lines*/
int main()
{
	char storage[MAXSTORAGE];
	int nlines; /*number of input lines read */

	if ((nlines = readlines(lineptr,storage, MAXLINES)) >= 0)
	{
		qsort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	}
	else
	{
		printf("error: input too big to sort\n");
		return 1;
	}
	return 0;
}

/*readlines: read input lines */
int readlines(char* lineptr[],char *storage, int maxlines)
{
	int i, len, nlines, temp;
	char *p, line[MAXLEN];
	int current_p = 0;

	nlines = 0;
	while ((len = get_line(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (current_p + len )> MAXSTORAGE)
			return -1;
		else
		{
			line[len] = '\0'; /*delete new line*/
			temp = current_p;
			i = 0;
			while (len >= 0)
			{
				storage[current_p++] = line[i++];
				len--;

			}
			lineptr[nlines++] = storage + temp;
		}
	return nlines;
}

/* writelines: write output lines */
void writelines(char* lineptr[], int nlines)
{
	int i;
	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);

}

int get_line(char *line, int max)
{
	int c, i;
	i = 0;
	while ((c = getchar()) != EOF && c != '\n' && i < max)
		line[i++] = c;
	line[i] = '\0';
	return i;
}

/* qsort: sort v[left]....v[right] into increasing order */
void qsort(char* v[], int left, int right)
{
	int i, last;
	void swap(char* v[], int i, int j);
	if (left >= right) /*do nothing if array contains fewer than two elements*/
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

/*swap: interchange v[i] and v[j] */
void swap(char* v[], int i, int j)
{
	char* temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

