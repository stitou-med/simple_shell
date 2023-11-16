#include "shell.h"
/**
 * main - Simple shell main function
 * @argc: count of arguments
 * @argv: arguments table
 * return: 0 Always success.
*/
int main(int ac, char **argv)
{
    char *line = NULL;
    char **command = NULL;
    int status = 0, idx = 0;
    (void) ac;



    while (1)
    {
        line = readline();
        if (line == NULL)
        {
            if (isatty(STDIN_FILENO))
            {
                write(STDOUT_FILENO, "\n", 1);
            }    
            return (status);    
        }
        idx++;
        
        command = tokenizer(line);
        if (!command)
        {
            continue;
        }
        
        status = _execute(command, argv, idx); 
    }   
}
