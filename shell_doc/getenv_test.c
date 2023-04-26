#include <stdio.h>
#include <string.h>

char* _getenv(const char *name)
{
    extern char **environ;
    char *value = NULL;
    size_t namelen = strlen(name);

    for(char **env = environ; *env != NULL; env++) {
        if(strncmp(name, *env, namelen) == 0 && (*env)[namelen] == '=') {
            value = &(*env)[namelen + 1];
            break;
        }
    }

    return value;
}

char* _getenv(const char *name);

int main() {
    char *path = _getenv("PATH");
    if (path != NULL) {
        printf("The PATH environment variable is set to: %s\n", path);
    } else {
        printf("The PATH environment variable is not set.\n");
    }
    return (0);
}
