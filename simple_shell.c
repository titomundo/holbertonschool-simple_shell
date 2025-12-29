#include <stdio.h>
#include <sys/types.h>
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
	char *buf = NULL;
	char **args;
	pid_t process;
	int status;

	printf("$ ");
	while ((nread = getline(&buf, &len, stdin)) != -1)
	{
		process = fork();

		if (process == -1)
		{
			perror("Error: ");
			return (0);
		}
		else if (process == 0)
		{
			buf[nread - 1] = 0;
			args = arg_array(buf);

			if (execve(args[0], args, NULL) == -1)
				perror(argv[argc * 0]);

			exit(1);
		}
		else
			wait(&status);

		printf("$ ");
	}

	free(buf);
	return (0);
}
