#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
void sh_loop(void);
char *path_finder(char *args);
char *buf(char *path, char *args);
int sh_start(char **args);
char *sh_readline(void);
char **sh_parseline(char *line);
int sh_execute(char **args);
int _strcmp(char *ptr);

#endif
