#include "shell.h"

/**
* split_path - turns PATH variable to array
* @path: PATH variable
*
* Return: array with each directory in the PATH
*/
char **split_path(char *path)
{
	char **args;
	char *token, *temp;
	int i, size;

	size = word_count2(path);

	if (size < 1)
		return (0);

	args = (char **) malloc((size + 1) * sizeof(char *));
	args[size] = NULL;

	if (!args)
		return (0);

	temp = strdup(path);
	token = strtok(temp, ":");
	i = 0;

	while (token)
	{
		args[i] = strdup(token);

		if (!args[i])
		{
			free(temp);
			free_array(args);
			return (0);
		}

		token = strtok(NULL, ":");
		i++;
	}

	free(temp);
	return (args);
}


/**
 * get_path - extracts the PATH variable from env
 * @env: env variables
 *
 * Return: PATH variable
 */
char *get_path(char **env)
{
	int i = 0;

	while (env[i])
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);

		i++;
	}

	return (0);
}

/**
* get_cmd - looks in the path for the path of a command
* @path: PATH env variable
* @cmd: command to look for
*
* Return: filepath to the program, null on failure
*/
char *get_cmd(char **path, char *cmd)
{
	int s1, s2, i = 0;
	char *temp;

	s1 = strlen(cmd);

	while (path[i])
	{
		s2 = strlen(path[i]);
		temp = malloc((s1 + s2 + 2) * sizeof(char));

		strcpy(temp, path[i]);
		temp[s2] = '/';
		strcpy(temp + s2 + 1, cmd);

		if (access(temp, F_OK) == 0)
		{
			free_array(path);
			return (temp);
		}

		free(temp);
		i++;
	}

	free_array(path);
	return (0);
}
