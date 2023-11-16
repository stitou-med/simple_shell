#include "shell.h"

char *readline(void)
{

    char *line = NULL;
    size_t bfsize = 0;
    ssize_t n;
    if (isatty(STDIN_FILENO))
    {
        write(STDOUT_FILENO, "$ ", 2);
    } 
    n = getline(&line, &bfsize, stdin);
    if (n == -1)
    {
        free(line); 
        return (NULL);
    }
    

    return (line); 
}
