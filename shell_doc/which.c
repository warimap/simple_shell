#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char *path = getenv("PATH");
    if (path == NULL) {
        fprintf(stderr, "Error: PATH environment variable not set\n");
        return 1;
    }

    char *filename;
    for (int i = 1; i < argc; i++) {
        filename = argv[i];
        int found = 0;

        char *token = strtok(path, ":");
        while (token != NULL) {
            char *filepath = (char *) malloc(strlen(token) + strlen(filename) + 2);
            sprintf(filepath, "%s/%s", token, filename);
            if (access(filepath, F_OK) == 0) {
                printf("%s\n", filepath);
                found = 1;
            }
            free(filepath);
            token = strtok(NULL, ":");
        }

        if (!found) {
            fprintf(stderr, "%s: not found\n", filename);
        }
    }

    return (0);
}
