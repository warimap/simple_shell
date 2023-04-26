#include <stdio.h>
#include <stdlib.h>

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while (1) {
        // Print the prompt
        printf("$ ");

        // Read in a line of input
        read = getline(&line, &len, stdin);

        // If getline returns -1, it means an error occurred or the end of input was reached
        if (read == -1) {
            printf("\n");
            break;
        }

        // Print the line of input
        printf("%s", line);
    }

    // Free the memory used by getline
    free(line);

    return 0;
}

