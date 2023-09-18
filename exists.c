#include "shell.h"
/**
* my_strncpy - copies a string
* @dest: the destination string to be copied to
* @src: the source string
* @n: the amount of characters to be copied
* Return: the combined string
*/
char *my_strncpy(char *dest, char *src, int n)
{
int m, o;
char *s = dest;

m = 0;
while (src[m] != '\0' && m < n - 1)
{
dest[m] = src[m];
m++;
}
if (m < n)
{
o = m;
while (o < n)
{
dest[o] = '\0';
o++;
}
}
return (s);
}
