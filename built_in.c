/**
 * _environ - function prints the environment variables
 *
 * Return: 1
 */
#include "main.h"
int _environ(void)
{
	char **en = environ;

	for (; *en; en++)
		printf("%s\n", *en);

	return (1);
}
