#include <stdio.h>
#include <stdlib.h>

// Function definition of _unsetenv goes here...

int main(void) {
    char *path = getenv("PATH");
    printf("Before unset:\nPATH=%s\n", path);

    _unsetenv("PATH");

    path = getenv("PATH");
    printf("After unset:\nPATH=%s\n", (path != NULL) ? path : "(null)");

    return (0);
}
