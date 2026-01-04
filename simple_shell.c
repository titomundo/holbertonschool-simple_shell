#include "shell.h"

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
	char *buf, *cmd, **args = NULL;

	while (1)
	{
		buf = get_userin();

		if (!buf || strcmp(buf, "exit") == 0)
			break;

		args = arg_array(buf);

		if (!args)
		{
			free(buf);
			continue;
		}

		cmd = get_cmd(split_path(get_path(env)), args[0]);

		if (access(args[0], F_OK) == 0)
			run_cmd(args[0], args, env, buf);
		else if (cmd)
			run_cmd(cmd, args, env, buf);
		else
			perror(argv[argc * 0]);

		free(buf);
		free(cmd);
		free_array(args);
		wait(NULL);
	}

	free(buf);
	return (0);
}
