#include "shell.h"
char *_strdup(const char *str)
{
    char *ptr;
    int i, l = 0;
    if (str == NULL)
    {
        return (NULL);
    }
    while (*str != '\0')
    {
        l++;
        str++;
    }
    str = str - l;
    ptr = malloc(sizeof(char) * (l + 1));
    if (ptr == NULL)
    {
        return (NULL);
    }
    for ( i = 0; i <= l; i++)
    {
        ptr[i] = str[i];
    }
    return (ptr); 

}

int _strcmp(char *s1, char *s2)
{
    int cmp;
    cmp = (int)*s1 - (int)*s2;
    while (*s1)
    {
        if (*s1 != *s2)
        {
            break;
        }
        s1++;
        s2++;
        cmp = (int)*s1 - (int)*s2;
    }
    return (cmp);
       
}

int _strlen(char *s)
{
	int longi = 0;

	while (*s != '\0')
	{
		longi++;
		s++;
	}

	return (longi);
}

char *_strcpy(char *dest, char *src)
{
	int l = 0;
	int x = 0;

	while (*(src + l) != '\0')
	{
		l++;
	}
	for ( ; x < l ; x++)
	{
		dest[x] = src[x];
	}
	dest[l] = '\0';
	return (dest);
}

char *_strcat(char *dest, char *src)
{
    char *p = dest;
    while (*p)
    {
        p++;
    }
    while (*src)
    {
        *p = *src;
        p++;
        src++;
    }
    *p = *src;
    return (dest);  
}
