#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char *argv[], char *env[]) {
    printf("Address of env: %p\n", (void *) env);
    printf("Address of environ: %p\n", (void *) environ);

    if (env == environ) {
        printf("env and environ are the same\n");
    } else {
        printf("env and environ are different\n");
    }

    return (0);
}
