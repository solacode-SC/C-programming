#include <stdio.h>

#include <string.h>


int main(int argc, char **argv)
{
    if (argc != 2)
        return printf("Error");
    char *strtosplit = argv[1];
    char *token = strtok(strtosplit, " ");
    while (token!= NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

    int *b1;
    int *b2;
    return 0;
}