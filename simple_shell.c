#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "shell.h"

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
	int status;

	if (isatty(0) == 1)
		printf("$ ");

	while ((nread = getline(&buf, &len, stdin)) != -1)
	{
		process = fork();

		if (process == -1)
		{
			perror("Error: ");
			exit(1);
		}
		else if (process == 0)
		{
			buf[nread - 1] = 0;
			args = arg_array(buf);
			if (!args)
				exit(1);

			if (execve(args[0], args, NULL) == -1)
				perror(argv[argc * 0]);

			exit(0);
		}
		else
			wait(&status);

		if (isatty(0) == 1)
			printf("$ ");
	}

	free(buf);
	free(args);
	return (0);
}
