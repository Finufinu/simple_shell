#include "shell.h"

/**
* *_eputs - prints an input string
* @str: the string to be printed
* Return: Nothing
*/
void _eputs(char *str)
{
int m = 0;

if (!str)
return;
while (str[m] != '\0')
{
_eputchar(str[m]);
m++;
}
}
/**
* _eputchar - writes the character c to stderr
* @c: The character to print
*
* Return: On success1.
* On error, -1 is returned, and errno is set appropriately
*/
int _eputchar(char c)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(2, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}
/**
* _putfd - writes the character c to given fd
* @c: The character to print
* @fd: The filedescriptor to write to
*
* Return: On success 1
* On error, -1 is returned and errno is set appropriateky
*/
int _putfd(char c, int fd)
{
static int n;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || n >= WRITE_BUF_SIZE)
{
write(fd, buf, n);
n = 0;
}
if (c != BUF_FLUSH)
buf[n++] = c;
return (1);
}
