/*Add the option -f to fold upper and lower case together, so that case distinctions are not made during sorting; for example, a and A compare equal..*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
 
#define MAXLINES 5000     /*Max #lines to be sorted*/ 
#define ALLOCSIZE 10000 /*size of availabel space*/

#define MAXLEN 1000 /*max length of any input line */
#define MAXSTORAGE 100000

int readlines(char* lineptr[], int nlines);
void writelines(char* lineptr[], int nlines, int reverse);
//void fold(char* [], int ,char *[]);

void qsort(void* [], int , int , int (*)(void*, void*));
int numcmp(char*, char*);
int my_string_compare(char*, char*);

static char allocbuf[ALLOCSIZE];/*storage for alloc*/
static char* allocp = allocbuf; /*next free position*/

char* alloc(int);
char* lineptr[MAXLINES]; /*pointers to text lines */
int fold_case_enabled = 0;
int directory_order_enabled = 0;

// Helper function to determine if a character is relevant for directory order
// (i.e., a letter, number, or blank)
static int is_relevant_char(char c) {
    return isalnum((unsigned char)c) || isspace((unsigned char)c);
}

int main(int argc, char *argv[])
{
    int nlines, i;               /* number of input lines read*/
    int numeric = 0;          /* 1 if numeric sort */
    int reverse = 0;          /* 1 if reverse sort */
    char *temp;
    char *temp_lineptr[MAXLINES];
    
    i = 1;
    while (--argc > 0)
    {
        temp = argv[i];
        if (*temp == '-')
        {
            while (*temp++ != '\0')
            {
                if (*temp == 'n') numeric = 1;
                else if (*temp == 'r') reverse = 1;
                else if (*temp == 'f') fold_case_enabled = 1;
                else if (*temp == 'd') directory_order_enabled = 1;
            }
        }
        i++;

    }
       
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        
        qsort((void**)lineptr, 0, nlines - 1, (int (*)(void*, void*))(numeric ? numcmp : my_string_compare));
        writelines(lineptr, nlines, reverse);

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
void writelines(char* lineptr[], int nlines, int reverse)
{
    int i;
    if (reverse)
    {
        for (i = nlines - 1; i >= 0; i--)
            printf("%s\n", lineptr[i]);
    }
    else
    {
        for (i = 0; i < nlines; i++)
            printf("%s\n", lineptr[i]);
    }
}



int my_string_compare(void* vp1, void* vp2) {
    char* s1 = (char*)vp1;
    char* s2 = (char*)vp2;

    // Pointers to iterate through the strings, potentially skipping characters
    char* p1 = s1;
    char* p2 = s2;

    // Loop until one of the strings ends
    while (*p1 != '\0' && *p2 != '\0') {
        // If directory order is enabled, skip non-relevant characters
        if (directory_order_enabled) {
            while (*p1 != '\0' && !is_relevant_char(*p1)) {
                p1++;
            }
            while (*p2 != '\0' && !is_relevant_char(*p2)) {
                p2++;
            }
        }

        // If both strings have effectively ended (after skipping non-relevant chars)
        if (*p1 == '\0' && *p2 == '\0') {
            return 0; // They are equal
        }
        // If one string ended (or only has non-relevant chars left)
        if (*p1 == '\0') return -1; // s1 is "shorter"
        if (*p2 == '\0') return 1;  // s2 is "shorter"

        // Get characters for comparison
        char c1 = *p1;
        char c2 = *p2;

        // Apply case-folding if enabled
        if (fold_case_enabled) {
            c1 = tolower((unsigned char)c1);
            c2 = tolower((unsigned char)c2);
        }

        // Compare the (potentially filtered and case-folded) characters
        if (c1 != c2) {
            return c1 - c2; // Return the difference
        }

        // Move to the next characters in both strings
        p1++;
        p2++;
    }

    // Handle remaining characters if one string was longer after the loop
    // This final check covers cases where one string might have relevant characters
    // remaining after the loop, or if the loop exited because of a null terminator
    // that was encountered after skipping non-relevant characters.
    if (directory_order_enabled) {
        while (*p1 != '\0' && !is_relevant_char(*p1)) p1++;
        while (*p2 != '\0' && !is_relevant_char(*p2)) p2++;
    }

    // If fold_case_enabled, compare the remaining characters (which might be null)
    if (fold_case_enabled) {
        return tolower((unsigned char)*p1) - tolower((unsigned char)*p2);
    }
    else {
        // Otherwise, use standard string comparison for remaining parts
        return strcmp(p1, p2);
    }
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

