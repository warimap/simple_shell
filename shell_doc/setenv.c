#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int _setenv(const char *name, const char *value, int overwrite) {
    if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL) {
        // Invalid variable name
        return (-1);
    }

    char *var = NULL;
    int name_len = strlen(name);
    int value_len = (value != NULL) ? strlen(value) : 0;

    // Construct the variable string in the form "name=value"
    var = malloc(name_len + 1 + value_len + 1);
    if (var == NULL) {
        // Failed to allocate memory
        return (-1);
    }
    sprintf(var, "%s=%s", name, (value != NULL) ? value : "");

    // Check if the variable already exists in the environment
    char **p = environ;
    while (*p != NULL) {
        if (strncmp(*p, name, name_len) == 0 && (*p)[name_len] == '=') {
            // Variable already exists
            if (!overwrite) {
                // Don't overwrite, just return success
                free(var);
                return (0);
            }
            // Overwrite the existing variable
            else {
                *p = var;
                return (0);
            }
        }
        p++;
    }

    // Variable doesn't exist, add it to the environment
    *p = var;
    *(p + 1) = NULL;
    return (0);
}
