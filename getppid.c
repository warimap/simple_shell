#include <stdio.h>
#include <unistd.h>

/**
 * parent - PID
 *
 * Return: Always 0.
 */
int main(void)
{
printf("Parent PID: %d\n", getppid());
return (0);
}
