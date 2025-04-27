#include <stdio.h>

int any(const char [], const char []);

int main() {
    char s1[100], s2[100];
    printf("Enter first string: ");
    scanf("%99s", s1);
    printf("Enter second string: ");
    scanf("%99s", s2);

    int result = any(s1, s2);

    if (result != -1)
        printf("First matching index: %d\n", result);
    else
        printf("-1\n");

    return 0;
}

int any(const char s1[], const char s2[]) {
    int i;
    int char_seen[256] = {0}; // Lookup table for all possible characters

    // Mark characters present in s2
    for (i = 0; s2[i] != '\0'; i++) {
        char_seen[(unsigned char)s2[i]] = 1;
    }

    // Find the first character in s1 that is present in s2
    for (i = 0; s1[i] != '\0'; i++) {
        if (char_seen[(unsigned char)s1[i]])
            return i;
    }

    return -1;
}
 
