#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

extern char **environ;

void sh_loop(void);
char *path_finder(char *args);
char *buf(char *path, char *args);
int sh_start(char **args);
char *sh_readline(void);
char **sh_parseline(char *line);
int sh_execute(char **args);
int _strcmp(char *arg, char *built);
<<<<<<< HEAD
extern char **environ;
=======
>>>>>>> 83eede94d8cb742d4672ef61167f371e1b0d13d8
int _environ(void);

#endif /* MAIN_H */
