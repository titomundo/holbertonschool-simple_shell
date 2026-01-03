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
 * @env: env variables
 *
 * Return: Always 0
 */
int main(int argc, char *argv[], char *env[])
{
	size_t len = 0;
	ssize_t nread;
	char *buf = NULL, *cmd, **args = NULL;

	while (1)
	{
		print_prompt();
		nread = getline(&buf, &len, stdin);

		if (nread < 1)
			break;

		buf[nread - 1] = '\0';
		nread--;
		args = arg_array(buf);

		if (!args)
			continue;

		cmd = get_cmd(split_path(get_path(env)), args[0]);

		if (access(args[0], F_OK) == 0)
			run_cmd(args[0], args, env, buf);
		else if (cmd)
			run_cmd(cmd, args, env, buf);
		else
		{
			free_array(args);
			perror(argv[argc * 0]);
			continue;
		}

		free(cmd);
		free_array(args);
		wait(NULL);
	}

	free(buf);
	return (0);
}
