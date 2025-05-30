#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define MAXLINES 5000     /*Max #lines to be sorted*/
char* lineptr[MAXLINES];  /*pointers to text lines*/
#define ALLOCSIZE 10000 /*size of availabel space*/


#define MAXLEN 1000 /*max length of any input line */
#define MAXSTORAGE 100000

int readlines(char* lineptr[], int nlines);
void writelines(char* lineptr[], int nlines);

void qsort(void* [], int , int , int (*)(void*, void*));
int numcmp(char*, char*);

static char allocbuf[ALLOCSIZE];/*storage for alloc*/
static char* allocp = allocbuf; /*next free position*/

char* alloc(int);
char* lineptr[MAXLINES]; /*pointers to text lines */





int main(int argc, char *argv[])
{
    int nlines;               /* number of input lines read*/
    int numeric = 0;          /* 1 if numeric sort */

    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort((void**)lineptr, 0, nlines - 1, (int (*)(void*, void*))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);

        return 0;

    }
    else
    {
        printf("input is too big to sort\n");
        return 1;

    }

}


/*qsort : sort v[left] ... v[right] into increasing order*/

void qsort(void* v[], int left, int right, int(*comp)(void*, void*))
{
    int i, last;
    
    void swap(void* v[], int, int);

    if (left >= right) /*do nothing if array contains fewer than two elemtents*/
        return;
    swap(v, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++)
    {
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    }
    swap(v, left, last);
    qsort(v, left, last - 1, comp);
    qsort(v, last + 1, right, comp);
}


/*numcmp: compare s1 and s2 numerically*/

int numcmp(char* s1, char* s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

void swap(void* v[], int i, int j)
{
    void* temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/*readlines: read input lines */
int readlines(char* lineptr[], int maxlines)
{
    int len, nlines;
    char* p, line[MAXLEN];

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len + 1)) == NULL)
            return -1;
        else
        {
            line[len] = '\0'; /*delete new line*/
            strcpy(p, line);
            lineptr[nlines++] = p;
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

int get_line(char* line, int max)
{
    int c, i;
    i = 0;
    while ((c = getchar()) != EOF && c != '\n' && i < max)
        line[i++] = c;
    line[i] = '\0';
    return i;
}

char* alloc(int n) /*return pointer to n characters*/
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp - n; /* old p*/
    }
    else
        return 0;
}
