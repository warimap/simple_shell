#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int _unsetenv(const char *name) {
    if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL) {
        // Invalid variable name
        return (-1);
    }

    // Find the variable in the environment
    char **p = environ;
    while (*p != NULL) {
        if (strncmp(*p, name, strlen(name)) == 0 && (*p)[strlen(name)] == '=') {
            // Variable found, remove it by shifting the remaining variables left
            char **q = p;
            while (*q != NULL) {
                *q = *(q + 1);
                q++;
            }
            return (0);
        }
        p++;
    }

    // Variable not found
    return (0);
}
