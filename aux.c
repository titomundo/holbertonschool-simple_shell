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
 * get_userin - get user input
 *
 * Return: string with the user's input
 */
char *get_userin()
{
	size_t len = 0;
	ssize_t nread;
	char *buf = NULL;

	print_prompt();
	nread = getline(&buf, &len, stdin);

	if (nread < 1)
	{
		free(buf);
		return (0);
	}

	buf[nread - 1] = '\0';
	nread--;

	return (buf);
}
