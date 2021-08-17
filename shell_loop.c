/**
 * sh_loop - function runs shell loop
 *
 *Return: nothing
 */
#include "main.h"
void sh_loop(void)
{
	char *line;
	char **args;
	int state;

	do
	{
		printf("$ ");
		line = sh_readline();
		args = sh_parseline(line);
		state = sh_execute(args);
		free(line);
		free(args);
	}while (state);
}
/**
 * sh_realine - function read liens the shell arguments
 *
 * Return: pointer to the arguments entered
 */
char *sh_readline(void)
{
	char *line = NULL;
	size_t n= 0;

	if (getline(&line, &n, stdin) == -1)
		exit(EXIT_SUCCESS);
	return (line);
}
/**
 * sh_parseline - fuction eliminates spaces and delimeters in arguments
 * @line: argument pointer
 *
 * Return: Pointer to array of arguments
 */
#define DELIM " \t\r\n\a"
char **sh_parseline(char *line)
{
	int buf_size = 64;
	int c = 0;
	char **token_array = NULL;
	char *token;

	if (line == NULL)
		return (NULL);
	token_array = malloc(sizeof(char *) * buf_size);
	if (!token_array)
		exit(EXIT_FAILURE);
	token = strtok(line, DELIM);
	while (token != NULL)
	{
		token_array[c] = token;
		c++;
		if (c >= buf_size)
		{
			buf_size += 64;
			token_array = realloc(token_array, sizeof(char *) * buf_size);
			if (!token_array)
				exit(EXIT_FAILURE);
		}
		token = strtok(NULL, DELIM);
	}
	token_array[c] = NULL;
	return (token_array);
}
/**
 * sh_execute - function determines if builtin exit is present
 * @args: Command line arguments
 *
 * Return: status
 */
int sh_execute(char **args)
{
	int i;
	
	if (args[0] == NULL)
		return (1);
	for (i = 0; args[i] != NULL; i++)
	{
	       	if (_strcmp(args[i]) == 1)
			return (0);
	} 
	 return (sh_start(args));
}
/**
 * _strcmp - function compares string argument with 'exit'
 *@ptr: Argument pointer
 *
 * Return: flag
 */
int _strcmp(char *ptr)
{
	char *a = "exit";
	int i, flag = 1;

	for (i = 0; ptr[i] != '\0' && a[i] != '\0'; i++)
		if (ptr[i] != a[i])
			flag *= 0;
	return (flag);
}
