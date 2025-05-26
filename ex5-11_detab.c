/*Modify the program entab and detab (written as exercises in Chapter 1)
to accept a list of tab stops as arguments. Use the default tab settings
if there are no arguments.*/

/* detab's primary job is to replace tab characters (\t) with the appropriate number of spaces to expand them to their correct column position*/
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_TAB 4
#define MAX_ARGUMENTS 100

int get_next_tab_column(int, int [], int, int);

int main(int argc, char *argv[])
{
    int i;
    char c;
    int current_col = 1;
    int spaces_required = 0;
    int tab[MAX_ARGUMENTS];
    int next_tab_stop;

    for (i = 1; i < argc && i < MAX_ARGUMENTS; i++)
    {
        tab[i-1] = atoi(argv[i]);

    }

    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            current_col = 1;
            putchar('\n');
        }

        else if (c == '\t')
        {
           

            // First, check if there's a custom stop strictly after current_col
            next_tab_stop = get_next_tab_column(current_col, tab, argc - 1, DEFAULT_TAB);

            if (next_tab_stop == current_col && current_col != 1) { // Current column is a tab stop (not column 1)
                // We need to find the *next* tab stop from this position.
                // Easiest is to search from current_col + 1
                next_tab_stop = get_next_tab_column(current_col + 1, tab, argc - 1, DEFAULT_TAB);
            }

            spaces_required = next_tab_stop - current_col + 1;

            // Ensure a tab always prints at least one space if it moved
            // (e.g., if current_col = 1, get_next_tab_column returns 5, spaces_to_add = 4. Correct)
            // (e.g., if current_col = 5, get_next_tab_column(5+1) returns 10, spaces_to_add = 10-5 = 5. Correct)
            if (spaces_required <= 0) { // Should ideally not happen now, but good for robustness
                spaces_required = 1; // Fallback: always add at least one space for a tab.
            }

            for (int j = 0; j < spaces_required; j++)
            {
                putchar(' ');
            }
            current_col = next_tab_stop;

        }
        else
        {
            
            putchar(c);
            current_col++;
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