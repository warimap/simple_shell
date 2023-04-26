#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * prints max  - ID
 *
 * Return: Always 0.
 */
int main(void)
{
FILE *fp;
int max_pid;

fp = fopen("/proc/sys/kernel/pid_max", "r");
if (fp == NULL)
{
perror("Error opening pid_max file");
exit(EXIT_FAILURE);
}
fscanf(fp, "%d", &max_pid);
fclose(fp);

printf("Maximum PID: %d\n", max_pid);
return (0);

}
