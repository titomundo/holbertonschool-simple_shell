#include "shell.h"

/**
* run_cmd - executes a command in a fork process
* @cmd: path to program
* @args: args to program
* @env: environment to use
* @buf: user input (only for free)
*
* Return: 0
*/
int run_cmd(char *cmd, char **args, char **env, char *buf)
{
	pid_t pid = fork();

	if (!cmd | !args)
		return (0);

	if (pid < 0)
	{
		perror("Error: ");
		exit(1);
	}
	else if (pid == 0)
	{
		free(buf);
		if (execve(cmd, args, env) == -1)
		{
			free(cmd);
			free_array(args);
			perror("execve error");
			_exit(1);
		}
	}

	return (0);
}
