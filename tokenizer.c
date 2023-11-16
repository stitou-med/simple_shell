 #include "shell.h"
 char **tokenizer(char *line)
 {
    char *token = NULL;
    char *tmp = NULL;
    char **command = NULL;
    int cpt = 0, i = 0;

    if (!line)
    {
        return (NULL);
    }
    tmp = _strdup(line);

    token = strtok(tmp, LIM);
    if (token == NULL)
    {
        free(line), line=NULL;
        free(tmp), tmp = NULL;
        return (NULL);
    }
    
    while (token)
    {
        cpt++;
        token = strtok(NULL, LIM);
    }
    free(tmp), tmp = NULL;
    command = malloc(sizeof(char*) * (cpt + 1));

    token = strtok(line, LIM);
    while (token)
    {
        command[i] = _strdup(token);
        token = strtok(NULL, LIM);
        i++;
    }
    free(line), line=NULL;
    command[i] = NULL;
    return (command);
 }
 