# Simple shell project

Module of **Low-level programming** and **algorithm**, carried out during **Full Stack Software Engineering studies** at **[African Leadership X](https://www.alxafrica.com/)**.

## Technologies
* Scripts written in Bash 4.3.11(1)
* C files are compiled using `gcc 4.8.4`
* C files are written according to the C90 standard
* Tested on Ubuntu 14.04 LTS

## General

* The original Unix operating system was designed and implemented by a team of programmers at Bell Labs, including Ken Thompson and Dennis Ritchie, in the late 1960s and early 1970s. Thompson developed the initial version of Unix on a DEC PDP-7 computer in 1969, and later worked with Ritchie to rewrite Unix in the C programming language, which allowed it to be more portable across different hardware platforms. Unix went on to become a widely-used and influential operating system, and its development paved the way for the creation of many other important software tools and technologies.

* The first version of the Unix shell, called the "Thompson shell" or "sh", was written by Ken Thompson in 1971. The shell provided a command-line interface for interacting with the Unix operating system and running programs. It allowed users to enter commands and receive output, and also provided features such as command history, input/output redirection, and pipeline functionality for chaining together multiple commands. The Thompson shell was later replaced by the Bourne shell (sh), developed by Stephen Bourne in 1977, which became the standard Unix shell for many years and influenced the design of many other shell programs.

* The B programming language, which was a precursor to the C programming language, was developed by Ken Thompson at Bell Labs in the early 1970s. Thompson had previously implemented an operating system for the DEC PDP-7 computer in assembly language, and he wanted to create a higher-level language that could be used to rewrite the system in a more portable way. B was originally designed as a simplified version of the BCPL programming language, and it was used to implement the first version of the Unix operating system written in a high-level language. B was later replaced by the C programming language, which was also developed by Thompson and his colleagues at Bell Labs, and which offered more advanced features and greater portability.

* Ken Thompson is an American computer scientist and programmer who is best known for his pioneering work on the Unix operating system and the development of the C programming language. Thompson was born in 1943 in New Orleans, Louisiana, and received a degree in electrical engineering from the University of California, Berkeley in 1965. After working for a few years at Bell Labs, he began working on the development of Unix in the late 1960s, along with fellow programmer Dennis Ritchie. Thompson also created the first version of the Unix shell and the B programming language, which was a precursor to C. In addition to his work on Unix, Thompson has made contributions to many other areas of computer science, including computer security, programming languages, and distributed systems. He has received numerous awards for his work, including the Turing Award in 1983, which is considered one of the most prestigious awards in computer science.

* A shell is a command-line interface that allows a user to interact with an operating system. The shell works by providing a command prompt where the user can enter commands and receive output. When a user types a command into the shell, the shell interprets the command and passes it to the operating system for execution.

The shell typically provides a number of features to help the user enter commands and manage the results. For example, the shell may provide command history, allowing the user to recall previous commands with the arrow keys, or tab completion, which can help the user complete a partially-typed command by suggesting possible matches.

In addition to basic command execution, the shell also allows users to combine commands using pipelines, which pass the output of one command as input to another command. The shell also supports input/output redirection, which allows users to redirect the output of a command to a file, or to redirect input from a file instead of typing it at the command prompt.

Overall, the shell is a powerful and flexible tool for interacting with an operating system, and it plays a key role in many software development and system administration tasks.

* In a Unix-like operating system, a process is a running program or task, and each process is identified by a unique process ID (PID) number. The PID is a positive integer that is assigned by the operating system when the process is created. The PID allows the operating system to keep track of the process and manage its resources, such as memory and CPU time.

The parent process ID (PPID) is the PID of the process that created the current process. When a new process is created, the operating system assigns it a unique PID and sets the PPID to the PID of the process that created it. This creates a hierarchical relationship between processes, with each process having a single parent process (except for the init process, which is the ancestor of all processes in the system).

The PPID is useful for understanding the relationships between processes and their history, and it can be used by the operating system to manage process resources and terminate processes if necessary. In addition, many Unix utilities, such as ps and top, display process information including the PID and PPID, which can be used to diagnose problems and understand system behavior.

* In a Unix-like operating system, the environment of a process includes a set of environment variables that define various aspects of the process's runtime environment, such as the path to search for executables, the default editor or shell, and the current working directory. These environment variables can be manipulated by the current process using a few key commands:

export: This command is used to set an environment variable and make it available to child processes. For example, to add a directory to the PATH variable, you can use the command export PATH=$PATH:/my/new/directory.

unset: This command is used to remove an environment variable from the process's environment. For example, to remove the MY_VAR variable, you can use the command unset MY_VAR.

env: This command is used to display the current environment variables. For example, to see the value of the PATH variable, you can use the command env | grep PATH.

source or .: These commands are used to execute a script or a file that sets environment variables. When a script is executed using one of these commands, any environment variables that are set or modified by the script will be applied to the current process. For example, to set environment variables from a script called my_script.sh, you can use the command source my_script.sh or . my_script.sh.
These commands can be used in combination to manipulate the environment of the current process as needed.
* A function and a system call are both ways to execute a block of code in a program, but they are different in several important ways.

A function is a block of code that is defined within a program and can be called from other parts of the program. Functions are used to perform specific tasks, such as computing a value or modifying a data structure, and they can be called multiple times from different parts of the program. Functions are executed within the same process that calls them, and they typically use the same memory and resources as the calling process.

In contrast, a system call is a request made by a process to the operating system to perform a specific task on its behalf, such as reading from a file or creating a new process. System calls are used to interact with the operating system and access its services and resources, and they are typically used to perform operations that require privileged access or cannot be performed by user-level code alone. System calls are executed in kernel mode, which provides greater access to system resources but also imposes greater restrictions on the execution of the code.

In summary, a function is a block of code that is executed within the same process that calls it, while a system call is a request made by a process to the operating system to perform a specific task on its behalf. Functions are typically used to perform specific tasks within a program, while system calls are used to access system resources and services provided by the operating system.

* In the C programming language, there are three valid prototypes for the main function, which is the entry point of a C program. The three prototypes are:

int main(void): This prototype takes no arguments and returns an integer value. This is the most commonly used prototype for main.

int main(int argc, char *argv[]): This prototype takes two arguments: an integer argc, which represents the number of command-line arguments passed to the program, and a pointer to an array of strings argv, which contains the command-line arguments themselves. This prototype is used when the program needs to process command-line arguments.

int main(int argc, char *argv[], char *envp[]): This prototype is similar to the previous one, but it also includes a third argument envp, which is a pointer to an array of strings that contains the program's environment variables. This prototype is used when the program needs to access environment variables.

Note that while all three prototypes are valid, the first one (int main(void)) is the most commonly used and is often used for simple programs that do not require command-line arguments or access to environment variables.

* In Unix-like operating systems, the shell uses the PATH environment variable to search for executable programs when a user types a command. The PATH variable is a colon-separated list of directories that the shell searches in order to find the requested program. When a user types a command, the shell looks for an executable file with the same name in each directory listed in PATH, in the order specified by the variable.

For example, suppose a user types the command ls at the command prompt. The shell will look for an executable file named ls in each directory listed in PATH, in the order specified by the variable. If it finds a file named ls in one of the directories, it will execute that file. If it does not find a file named ls in any of the directories, it will display an error message.

It's worth noting that the current working directory (.) is not included in the default PATH variable for security reasons, as it can be a potential security vulnerability if a user unknowingly runs a program with the same name as a commonly used system command. To run a program in the current directory, a user must specify the full path to the program or include . in the PATH variable. However, this is generally not recommended for security reasons.

* The execve system call is used to replace the current process image with a new process image, which can be another program. The new process image can be an executable file or a script, and it can be located anywhere in the file system. Here's how to use the execve system call to execute another program:

Include the unistd.h header file, which contains the execve system call.

Create an array of strings that represents the command-line arguments to the new program. The first element of the array should be the path to the executable file, and the last element should be NULL.

Create an array of strings that represents the environment variables to be passed to the new program. This array should also end with NULL.

Call the execve system call with the path to the executable file, the array of command-line arguments, and the array of environment variables as arguments. The function does not return if successful.

Here is an example program that uses the execve system call to execute another program:
#include <unistd.h>
#include <stdio.h>

int main() {
    char *args[] = { "/bin/ls", "-l", NULL };
    char *env[] = { NULL };
    execve("/bin/ls", args, env);
    perror("execve"); // this line will be executed only if execve fails
    return 1;
}

* In Unix-like operating systems, a process can use the wait system call to suspend its execution until one of its child processes terminates. The wait system call allows a parent process to wait for the termination of a child process and obtain information about its termination status.
Here's an example of how to use the wait system call:
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child process executing\n");
        sleep(5);
        exit(0);
    } else if (pid > 0) {
        // Parent process
        printf("Parent process waiting for child\n");
        wait(&status);
        if (WIFEXITED(status)) {
            printf("Child process terminated with status %d\n", WEXITSTATUS(status));
        } else {
            printf("Child process terminated abnormally\n");
        }
    } else {
        // Error forking
        perror("fork");
        exit(1);
    }

    return 0;
}

In this example, the parent process forks a child process and waits for the child to terminate using the wait system call. The child process executes for 5 seconds before terminating with an exit status of 0. The parent process waits for the child to terminate using wait(&status). The wait system call suspends the execution of the parent process until the child process terminates. When the child terminates, the parent process obtains the termination status using the WIFEXITED and WEXITSTATUS macros. If the child process terminated normally, the WIFEXITED macro returns a nonzero value, and the WEXITSTATUS macro returns the exit status of the child process.

Note that if a process has multiple child processes, the wait system call will wait for any child process to terminate, not a specific child process. If a process needs to wait for a specific child process to terminate, it can use the waitpid system call instead of wait.

* EOF stands for "end-of-file." In Unix-like operating systems, it is a signal that indicates the end of a file. When a program reads from a file using input/output functions such as fgetc or fgets, it will receive an EOF signal when it reaches the end of the file.

The EOF signal is represented by a special integer value that is typically -1. This value is returned by input/output functions to indicate that there is no more data to read from the file.

Here's an example of how to use EOF to read data from a file:
#include <stdio.h>

int main() {
    FILE *file;
    int c;

    file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }

    fclose(file);
    return 0;
}
EOF stands for "end-of-file." In Unix-like operating systems, it is a signal that indicates the end of a file. When a program reads from a file using input/output functions such as fgetc or fgets, it will receive an EOF signal when it reaches the end of the file.

The EOF signal is represented by a special integer value that is typically -1. This value is returned by input/output functions to indicate that there is no more data to read from the file.

Here's an example of how to use EOF to read data from a file:

arduino
Copy code
#include <stdio.h>

int main() {
    FILE *file;
    int c;

    file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }

    fclose(file);
    return 0;
}
In this example, the program reads characters from the file example.txt using the fgetc function. The fgetc function returns the next character from the file, or EOF if there is no more data to read. The program loops over the characters in the file and prints them to the console using the putchar function. When the end of the file is reached, the fgetc function returns EOF, and the loop terminates.

Note that EOF is not a character or a string. It is a special value that indicates the end of a file. When reading from a file, programs should always check for EOF to avoid reading past the end of the file.




## Authors
+ [`Faith Warima  Ng'endo `](https://github.com/Warimap/Warimap/tree/master/README.md)
+ [`David Macharia Waweru`](https://github.com/DavidMacharia62/DavidMacharia62/tree/master/README.md)

---

## WARNING!!
- This repo is done as a school assignment. Beware of copying any of our responses. We recommend you  to read resources and come up with your own solutions instead. Feel free to reach out for help!
- This repo may contain some errors. If you notice any, please add a pull request.

