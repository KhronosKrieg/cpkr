/*Write a recursive version of the function reverse(s), which reverses the string s in place*/

#include <stdio.h>
#include <string.h>
void reverse(char [], int, int);
void getstr_safe(char *, int);
int main()
{
	char s[100];
	printf("enter a string:");
	// Use the safer getstr_safe function to read input
    getstr_safe(s, sizeof(s));
	int last = strlen(s);
	reverse(s, 0 , last-1);
	printf("%s",s);
	return 0;
}

void reverse(char s[], int first, int last)
{
	int c;

	if(first == last)
		return;
	c= s[first];
	s[first++] = s[last];
	s[last--] = c;
	
	reverse(s, first ,last);
	

}
/* getstr_safe: read a line from input into s, stopping at newline or EOF,
 * and preventing buffer overflow.
 * s: the buffer to store the string
 * size: the maximum number of characters to store (including null terminator)
 */
void getstr_safe(char *s, int size)
{
    if (s == NULL || size <= 0) {
        // Handle invalid buffer or size
        if (s != NULL) s[0] = '\0'; // Ensure buffer is empty if possible
        return;
    }

    // Use fgets to read input safely
    // fgets reads up to size-1 characters or until a newline or EOF
    if (fgets(s, size, stdin) == NULL) {
        // Handle potential read error or EOF immediately
        if (s != NULL) s[0] = '\0'; // Ensure buffer is empty on error
        return;
    }

    // fgets includes the newline character if the line fits in the buffer.
    // We usually want to remove it.
    // Find the newline character
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0'; // Replace newline with null terminator
    }
    // If the newline was not found (meaning the line was longer than the buffer),
    // the buffer is full but not null-terminated by fgets. It's null-terminated
    // at size-1. The remaining characters in the input buffer need to be consumed
    // to avoid issues with subsequent input operations.
    else if (len == size - 1 && s[len - 1] != '\n') {
         int c;
         // Consume remaining characters until newline or EOF
         while ((c = getchar()) != '\n' && c != EOF);
    }
}

