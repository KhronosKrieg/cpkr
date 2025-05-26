/*Modify the program entab and detab (written as exercises in Chapter 1)
to accept a list of tab stops as arguments. Use the default tab settings
if there are no arguments.*/

/* entab's primary job is to replace spaces with tabs*/
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_TAB 4
#define MAX_ARGUMENTS 100

int get_next_tab_column(int, int [], int, int);

int main(int argc, char *argv[])
{
    int i;
    char c;
    int spaces_buffered = 0;
    int current_col = 1;
    int temp_col;
    int tabs_required = 0;
    int spaces_required = 0;
    int spaces_required_to_next_tab_stop = 0;
    int tab[MAX_ARGUMENTS];
    int next_tab_stop;

    for (i = 1; i < argc && i < MAX_ARGUMENTS; i++)
    {
        tab[i-1] = atoi(argv[i]);

    }

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            current_col++;
            spaces_buffered++;
        }

        else if (c == '\n')
        {
            while (spaces_buffered-- > 0) putchar(' ');
            current_col = 1;
            putchar('\n');
        }

        else if (c == '\t')
        {
            while (spaces_buffered-- > 0) {
                putchar(' ');
            }
            putchar('\t'); // Output the actual input tab character
            current_col = get_next_tab_column(current_col, tab, argc - 1, DEFAULT_TAB);
            spaces_buffered = 0;

        }
        else
        {
            temp_col = current_col - spaces_buffered;

            while (spaces_buffered > 0)
            {
                next_tab_stop = get_next_tab_column(temp_col - 1, tab, argc - 1, DEFAULT_TAB);
                spaces_required_to_next_tab_stop = next_tab_stop - ((temp_col - 1));
                if (spaces_buffered >= spaces_required_to_next_tab_stop && spaces_required_to_next_tab_stop > 0)
                {
                    tabs_required++;
                    spaces_buffered -= spaces_required_to_next_tab_stop;
                    temp_col += spaces_required_to_next_tab_stop;
                }
                else
                {
                    spaces_required = spaces_buffered;
                    spaces_buffered = 0;
                }

               
            }
            while (tabs_required-- > 0) putchar('\t');
            while (spaces_required-- > 0) printf(" ");
            putchar(c);
            current_col++;

            spaces_buffered = 0;
            spaces_required = 0;
            tabs_required = 0;
        }
    }

    return 0;
}

int get_next_tab_column(int current_column, int custom_stops_array[], int num_custom_stops, int default_tab_size)
{
    int i;

    for (i = 0; i < num_custom_stops; i++)
    {
        if (custom_stops_array[i] > current_column)
            return custom_stops_array[i];
    }

    return ((current_column - 1) / default_tab_size + 1) * default_tab_size + 1;
}