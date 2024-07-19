#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    char *str;
    int i = 0;

    if (argc == 2) {
        // Allocate memory for str, including space for the null terminator
        str = (char *)malloc((strlen(argv[1]) + 1) * sizeof(char));
        if (!str) {
            perror("Failed to allocate memory");
            return 1;
        }

        // Copy the input string to str
        while (argv[1][i]) {
            str[i] = argv[1][i];
            i++;
        }
        str[i] = '\0';

        // Print the copied string
        printf("str : %s\n", str);

        // Free the allocated memory
        free(str);
    } else {
        printf("Usage: %s <string>\n", argv[0]);
    }

    return 0;
}
