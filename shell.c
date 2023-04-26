#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

int main() {
    char command[MAX_COMMAND_LENGTH];
    pid_t pid;
    int status;

    while (1) {
        // Display the prompt
        printf("$ ");
        fflush(stdout);

        // Read the user's input
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = 0; // Remove the trailing newline

        // If the user pressed Ctrl+D or typed "exit", exit the shell
        if (!strcmp(command, "") || !strcmp(command, "exit")) {
            break;
        }

        // Try to execute the command
        pid = fork();
        if (pid == 0) {
            // Child process
            if (execlp(command, command, NULL) == -1) {
                fprintf(stderr, "Execution failed\n");
                exit(EXIT_FAILURE);
            }
        } else if (pid > 0) {
            // Parent process
            waitpid(pid, &status, 0);
        } else {
            // Fork error
            fprintf(stderr, "Fork failed\n");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
