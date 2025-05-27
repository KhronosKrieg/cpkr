/* Write the program tail, which prints the last n lines of its input. By default, 
n is set to 10, let us say, but it can be changed by an optional argument so that
tail -n 
prints the last n lines. The program should behave rationally no matter how unreasonable
the input or the value of n. Write the program so it makes the best use of available 
storage; lines should be stored as in the sorting program of Section 5.6, not in a 
two-dimensional array of fixed size.*/



#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT 10
#define MAXLEN 1000
#define MAXLINES 100
#define MAXSTORAGE 10000

int readlines(char *[], char[], int, int);
int get_line(char *, int);

int main(int argc, char* argv[])
{
    int i, num, nlines, starting_index, val;
    char *str, *endptr;
    int num_lines_to_print = DEFAULT;
    char *lineptr[MAXLINES];
    char linestorage[MAXSTORAGE];

    if (argc == 2)
    {
        if (*argv[1] == '-')
        {
            str = argv[1] + 1;
            val = strtol(str, &endptr, 10);
            if (endptr == str)
            {
                fprintf(stderr, "Error: No digits found after '-'. Using default (%d).\n", DEFAULT);
            }
            else if (*endptr != '\0')
            {
                fprintf(stderr, "Error: Invalid characters '%s' after number. Using default (%d).\n", endptr, DEFAULT);
            }
            else if (val <= 0) 
            { 
                fprintf(stderr, "Error: Number of lines must be positive. Using default (%d).\n", DEFAULT);
            }
            else 
            {
                num_lines_to_print = (int)val; // Valid number, cast to int
            }
        }
        else
        {
            fprintf(stderr, "Usage: %s [-n]\n", argv[0]);
            return 1; // Indicate error

        }

    }
    else if (argc > 2) 
    {
        // Too many arguments
        fprintf(stderr, "Usage: %s [-n]\n", argv[0]);
        return 1; // Indicate error
    }

    if ((nlines = readlines(lineptr, linestorage, MAXLINES, MAXSTORAGE)) >= 0)
    {
        

        if (nlines <= num_lines_to_print)
        {
            //print all lines
            starting_index = 0;
            for (i = 0; i < nlines; i++)
            {
                printf("%s\n", lineptr[i]);
            }
        }
        else
        {
            starting_index = nlines - num_lines_to_print;
            for (i = starting_index; i < nlines; i++)
            {
                printf("%s\n", lineptr[i]);
            }
        }


    }


}


int readlines(char *lineptr[], char linestorage[], int maxlines, int maxstorage)
{
    int len, nlines;
    char line[MAXLEN];
    int i, temp, current_p = 0;

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0 && line[len] == '\0')
        if (nlines >= maxlines || (current_p + len) > maxstorage)
            return -1;
        else
        {
            //line[len] = '\0'; /*seperator between line strings*/
            temp = current_p;
            
            strcpy(linestorage + temp, line);
            current_p += (len + 1);
            lineptr[nlines++] = linestorage + temp;
        }
    return nlines;

}

int get_line(char* line, int maxlen)
{
    int c, i;
    i = 0;
    while ((c = getchar()) != EOF && i < maxlen)
    {
        if (c != '\n') line[i++] = c;
        else break;
    }

    line[i] = '\0';
    return i;
}
