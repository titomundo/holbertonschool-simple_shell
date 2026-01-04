#include "shell.h"

/**
* print_array - prints an array of strings
* @arr: arrray to print
*
* Return: void
*/
void print_array(char **arr)
{
	int i = 0;

	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}

/**
* word_count - returns the number of words in user input
* @str: string to check
*
* Return: number of words
*/
int word_count(char *str)
{
	int i;
	char *temp, *token;

	if (!str)
		return (0);

	temp = strdup(str);
	token = strtok(temp, " ");
	i = 0;

	while (token)
	{
		i++;
		token = strtok(NULL, " ");
	}

	free(temp);
	return (i);
}

/**
* dir_count - returns the number of directories in the PATH
* @path: PATH variable
*
* Return: number of words
*/
int dir_count(char *path)
{
	int i;
	char *temp, *token;

	if (!path)
		return (0);

	temp = strdup(path);
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

/**
* free_array - frees an array
* @arr: array to clear
*
* Return: void
*/

void free_array(char **arr)
{
	int i = 0;

	while (arr[i])
	{
		free(arr[i]);
		i++;
	}

	free(arr);
}

/**
* arg_array - separates word in an array of arguments
* @str: string to convert
*
* Return: pointer to the array
*/
char **arg_array(char *str)
{
	char **args;
	char *token, *temp;
	int i, size;

	size = word_count(str);

	if (size < 1)
		return (0);

	args = (char **) malloc((size + 1) * sizeof(char *));
	args[size] = NULL;

	if (!args)
		return (0);

	temp = strdup(str);
	token = strtok(temp, " ");
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
		token = strtok(NULL, " ");
		i++;
	}

	free(temp);
	return (args);
}
