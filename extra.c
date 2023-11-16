#include "shell.h"
void freearray(char **tab)
{
    int i;
    if (!tab)
    {
        return;
    }
    for ( i = 0; tab[i]; i++)
    {
        free(tab[i]);
        tab[i] = NULL;
    }
    free(tab);
    tab = NULL;
}

void printerror(char *name, char *cmd, int idx)
{
    char *index, msg[] = ": not found\n";
    index = _itoa(idx);

    write(STDERR_FILENO, name, _strlen(name));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, index, _strlen(index));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, cmd, _strlen(cmd));
    write(STDERR_FILENO, msg, _strlen(msg));

    free(index);

}

char *_itoa(int n)
{
    char buffer[20];
    int i = 0;

    if (n == 0)
    {
        buffer[i++] = '0';
    }
    else
    {
        while (n > 0)
        {
            buffer[i++] = (n % 10) + '0';
            n /= 10;
        }
        
    }

    buffer[i] = '\0';
    reverse_string(buffer, i);
    return (_strdup(buffer));
    
}

void reverse_string(char *str, int len)
{
    char tmp;
    int start = 0;
    int end = len - 1;
    while (start < end)
    {
        tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
        start++;
        end--;
    }   
}
