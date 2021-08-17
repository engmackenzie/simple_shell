/**
 * sh_start - function initiates and executes the shell
 * @args: arguments
 *
 * Return: status of the process
 */
#include "main.h"
char *path_finder(char *args)
{
	int i = 0;
	char *path_direct[] = {
		"/usr/local/sbin", 
		"/usr/local/bin", 
		"/usr/sbin",
	       	"/usr/bin", 
		"/sbin", 
		"/bin", 
		NULL};
	char *bufptr;
	if (args == NULL)
		return (NULL);
	while (path_direct[i] != NULL)
	{
		if (access(args, X_OK) == 0)
		{
			return (args);
		}
		else
		{
			bufptr = buf(path_direct[i], args);
			if(access(bufptr, X_OK) == 0)
			{
				return (bufptr);
			}
		}
		i++;
	}
	return(NULL);
}
char *buf(char *path, char *args)
{
	int i, j;
	char *_buf = malloc(sizeof(char) * 64);
	if (_buf == NULL)
		return NULL;

	for (i = 0; path[i] != '\0'; i++)
	{
		_buf[i] = path[i];
	}
	_buf[i] = '/';
	i++;
	for (j = 0; args[j] != '\0'; i++, j++)
	{
	       	_buf[i] = args[j];
	}
	_buf[i] = '\0';
	return (_buf);
}	
int sh_start(char **args)
{
	pid_t pid, wpid;
	int status;
	char *env_arg[] = {(char*)0};
	char *ptr = path_finder(args[0]);

	if (ptr)
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(ptr, args, env_arg) == -1)
			{
				perror("./shell");
			}
		exit(EXIT_FAILURE);
		}
		else if (pid < 0)
			perror("./shell");
		else
		{
			do
			{
				wpid = waitpid(pid, &status, WUNTRACED);
				if (wpid == -1)
					perror("./shell");
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
	else
		perror("./shell");
	return (1);
}
/**
 * main - program entry point
 *
 * Return: 0 success.
 */
int main(void)
{
	sh_loop();
	
	return (EXIT_SUCCESS);
}
