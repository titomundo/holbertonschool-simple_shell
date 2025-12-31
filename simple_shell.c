#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "shell.h"

/**
 * print_prompt - prints the $ prompt to the user
 *
 * Return: void
 */
void print_prompt(void)
{
	if (isatty(0) == 1)
		printf("$ ");
}
/**
 * main - start shell
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	size_t len = 0;
	ssize_t nread;
	char *buf = NULL, **args = NULL;
	pid_t process;

	print_prompt();

	while ((nread = getline(&buf, &len, stdin)) != -1)
	{
		process = fork();
		buf[nread - 1] = '\0';
		nread--;

		if (process < 0)
		{
			perror("Error: ");
			exit(1);
		}
		else if (process == 0)
		{
			args = arg_array(buf);

			if (!args)
				break;

			if (execve(args[0], args, NULL) == -1)
				perror(argv[argc * 0]);

			break;
		}
		else
			wait(NULL);

		print_prompt();
	}

	free(buf);
	free_array(args, nread);
	return (0);
}
