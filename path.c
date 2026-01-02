#include "shell.h"

char *split_path(char **arr)
{
	int i = 0;

	while(arr[i])
	{
		if (strncmp(arr[i], "PATH=", 5) == 0)
			return (arr[i] + 5);

		i++;
	}

	return (0);
}

char *get_path(char **arr, char *cmd)
{
	int s1, s2, i = 0;
	char *temp;
	struct stat st;

	s1 = strlen(cmd);

	while(arr[i])
	{
		s2 = strlen(arr[i]);
		temp = malloc((s1 + s2 + 2) * sizeof(char));

		strcpy(temp, arr[i]);
		temp[s2] = '/';
		strcpy(temp + s2 + 1, cmd);

		if (stat(temp, &st) == 0)
		{
			printf("%s\n", temp);
			free(temp);
			return (temp);
		}
		
		free(temp);
		i++;
	}

	return (0);
}
