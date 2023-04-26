#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_path() {
    char* path = getenv("PATH"); // Get the value of the PATH environment variable
    if (path == NULL) {
        printf("PATH environment variable not found.\n");
        return;
    }

    char* token = strtok(path, ":"); // Tokenize the PATH variable using ':' as the delimiter
    while (token != NULL) {
        printf("%s\n", token); // Print each directory on a new line
        token = strtok(NULL, ":"); // Move to the next token
    }
}

int main() {
    print_path();
    return (0);
}
