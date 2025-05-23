/*Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to
achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank
 would suffice to reach a tab stop, which should be given preference?*/

/* entab's primary job is to replace spaces with tabs*/
#include <stdio.h>
#define TAB 4

int main()
{
    int c,  i, j;
    int current_col = 1; /*Tracks current column position*/
    int spaces_buffered = 0; /*counts consecutive spaces read*/
    int tabs_to_output = 0;
    int spaces_to_output = 0;
    int num_tabs_possible = 0;
    int num_spaces_remaining = 0;
    int temp_col;
    int spaces_to_next_tab_stop = 0;
    int spaces_needed_for_tab;
    int temp_col_for_flush;

    
    while ((c = getchar()) != EOF)
    {
       

        if (c == ' ')
        {
            spaces_buffered++;
            current_col++;
        }

        else if (c == '\n')
        {
            while (spaces_buffered-- != 0)
            {
                putchar(' ');

            }
            putchar('\n');
            current_col = 1;
            spaces_buffered = 0;

        }
        else if (c == '\t')
        {
            temp_col_for_flush = current_col - spaces_buffered;

            int num_tabs_to_print = 0;
            int num_spaces_to_print = 0;
        
            while (spaces_buffered > 0)
            {
                int spaces_needed_for_tab = TAB - ((temp_col_for_flush - 1) % TAB); // Spaces to next tab stop
                if (spaces_needed_for_tab == 0) spaces_needed_for_tab = TAB; // If already at tab stop, need full TAB spaces

                if (spaces_buffered >= spaces_needed_for_tab)
                {
                    num_tabs_to_print++;
                    spaces_buffered -= spaces_needed_for_tab;
                    temp_col_for_flush += spaces_needed_for_tab;
                }
                else
                {
                    num_spaces_to_print = spaces_buffered;
                    spaces_buffered = 0;
                }
            }

            while (num_tabs_to_print-- > 0) printf("\\t");
            while (num_spaces_to_print-- > 0)putchar(' ');

            printf("\\t");
            current_col = ((current_col - 1) / TAB + 1) * TAB + 1; // Correctly advance column for a tab

            current_col++;
        }
        else
        {
            temp_col = current_col - spaces_buffered;
            num_tabs_possible = 0;
            num_spaces_remaining = 0;

            while (spaces_buffered > 0)
            {
                spaces_to_next_tab_stop = TAB - ((temp_col - 1) % TAB);
                if (spaces_to_next_tab_stop == TAB) spaces_to_next_tab_stop = TAB;
                if (spaces_buffered >= spaces_to_next_tab_stop && spaces_to_next_tab_stop > 0)
                {
                    num_tabs_possible++;
                    spaces_buffered -= spaces_to_next_tab_stop;
                    temp_col += spaces_to_next_tab_stop;
                }
                else
                {
                    num_spaces_remaining = spaces_buffered;
                    spaces_buffered = 0;
                }

            }

            while (num_tabs_possible-- > 0)
            {
                printf("\\t");
                
                
            }
            while (num_spaces_remaining-- > 0)putchar(' ');
            putchar(c);
            spaces_buffered = 0;
            current_col++;


        }
    }

    return 0;
}


/*Entab is primarily adding tabs replacing spaces
** In this program tab stop is defined at 4
** so tab stops occurs at columns 4, 8, 12, 16, 20,.......
** column starts at 1.
** suppose if line is 'I love c programming'
** then column 1 for I, column 1 for space, column 3 for l, column 4 for o and so on
** input: abc d: as tab stop is at 4 we replace  4th space with tab so output: abc    d
** input abcdef
** one thing to notice: Terminal(both linux and windows) tab stop occurs at 8, it interferes with output
** eg: input: my name is idiot: output should be "my name    is idiot", but it shows "my name is idiot"
** it is because terminal automatically converts"my name is\tis idiot" to "my name is idiot" 
** i.e \t replaced by single space as it occurs at 8 th column where default tab stop defined for terminal
** so to correctly see output, I replace putchar('\t') with printf("\\t"); so we see \t instead of tab
** This program calculates consecutive spaces(spaces buffered) and finds the next tab stop after last character printed
** If this spaces buffered is greater than or equal to no of tabs required after last character to reach tab stop
** it will replace spaces required to reach next tab stop with single tab, and reduces spaces buffered by same amount
** as it is while loop if again we have enough spaces buffered to reach another tab stop , we replace with tab and so on
** when tab is encounted, it checks if any spaces are there before and flush them using same logic above and before 
** printing tab
*/
