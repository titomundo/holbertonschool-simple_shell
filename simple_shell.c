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
	pid_t pid;
	int shell = 1;

	while (shell)
	{
		print_prompt();
		nread = getline(&buf, &len, stdin);
		buf[nread - 1] = '\0';
		nread--;

		if (nread < 0)
			break;

		args = arg_array(buf);

		if (!args)
			continue;

		pid = fork();

		if (pid < 0)
		{
			perror("Error: ");
			exit(1);
		}
		else if (pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
				perror(argv[argc * 0]);
		}

		wait(NULL);
	}
	
	free(buf);
	free_array(args, nread);
	return (0);
}
