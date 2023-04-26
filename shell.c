#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdbool.h>

#define MAX_BUFFER 1024
#define MAX_PATHS 100

char *find_executable(char *command, char **paths) {
    char *executable = malloc(MAX_BUFFER);
    if (!executable) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; paths[i]; i++) {
        snprintf(executable, MAX_BUFFER, "%s/%s", paths[i], command);
        if (access(executable, X_OK) == 0) {
            return executable;
        }
    }

    free(executable);
    return NULL;
}

bool is_env_builtin(char *command) {
    return strcmp(command, "env") == 0;
}

void execute_env() {
    extern char **environ;
    for (int i = 0; environ[i]; i++) {
        printf("%s\n", environ[i]);
    }
}

int main() {
    char *buffer = malloc(MAX_BUFFER);
    if (!buffer) {
        fprintf(stderr, "Memory allocation error\n");
        return EXIT_FAILURE;
    }

    char *paths[MAX_PATHS];
    paths[0] = "/bin";
    paths[1] = "/usr/bin";
    paths[2] = NULL;

    while (1) {
        printf("simple_shell$ ");

        if (!fgets(buffer, MAX_BUFFER, stdin)) {
            printf("\n");
            break;
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        char *command = strtok(buffer, " ");

        if (is_env_builtin(command)) {
            // Execute the env command
            execute_env();
            continue;
        } else if (strcmp(command, "exit") == 0) {
            // Exit the shell
            break;
        }

        // Try to execute the command
        char *executable = find_executable(command, paths);
        if (executable) {
            pid_t pid = fork();
            int status;
            if (pid == -1) {
                fprintf(stderr, "Fork failed\n");
                free(executable);
                continue;
            } else if (pid == 0) {
                // Child process
                if (execv(executable, (char *[]){command, NULL}) == -1) {
                    fprintf(stderr, "Execution of command %s failed\n", command);
                    exit(EXIT_FAILURE);
                }
            } else {
                // Parent process
                waitpid(pid, &status, 0);
            }
            free(executable);
        } else {
            fprintf(stderr, "Command not found: %s\n", command);
        }
    }

    // Free allocated memory and exit successfully
    free(buffer);
    return 0;
}
