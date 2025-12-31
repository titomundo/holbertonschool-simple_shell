#include "shell.h"

/**
* print_array - prints an array of strings
* @arr: arrray to print
* @size: size of the array
*
* Return: void
*/
void print_array(char **arr, int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("[%d]: %s\n", i, arr[i]);
}

/**
* word_count - returns the number of words in a string
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
* free_array - frees an array
* @arr: array to clear
* @size: size of the array
*
* Return: void
*/
void free_array(char **arr, int size)
{
	int i;

	for (i = 0; i < size; i++)
		free(arr[i]);

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
			free_array(args, size);
			return (0);
		}
		token = strtok(NULL, " ");
		i++;
	}

	free(temp);
	args[size] = NULL;
	return (args);
}
