#include "shell.h"

void print_array2(char **arr)
{
    int i = 0;

    while (arr[i])
    {
		printf("[%d]: %s\n", i, arr[i]);
		i++;
	}
}

int word_count2(char *str)
{
	int i;
	char *temp, *token;

	if (!str)
		return (0);

	temp = strdup(str);
	token = strtok(temp, ":");
	i = 0;

	while (token)
	{
		i++;
		token = strtok(NULL, ":");
	}

	free(temp);
	return (i);
}

char **env_array(char *str)
{
	char **args;
	char *token, *temp;
	int i, size;

	size = word_count2(str);

	if (size < 1)
		return (0);

	args = (char **) malloc(size * sizeof(char *));

	if (!args)
		return (0);

	temp = strdup(str);
	token = strtok(temp, ":");
	i = 0;

	while (token)
	{
		args[i] = strdup(token);

		if (!args[i])
		{
			free(temp);
			free_array(args, size);
			return (0);
		}

		token = strtok(NULL, ":");
		i++;
	}

	free(temp);
	return (args);
}
