#include "shell.h"

/**
* my_eputs - prints an input string
* @str: the string to be printed
*
* Return: Nothing
*/
void my_eputs(char *str)
{

int r = 0;


if (!str)
return;
while (str[r] != '\0')
{
int  my_eput(char str[r]);
r++;
}
}

/**
* my_eputchar - writes the character to x stderr
*
* @x: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and error handling  is set appropriately.
*/

int  my_eputchar(char x)

{
static int r;
static char buf[WRITE_BUF_SIZE];

if (x == BUF_FLUSH || r >= WRITE_BUF_SIZE)
{
write(2, buf,r);
r = 0;
}
if(r != BUF_FLUSH)
buf[r++] = x;
return (1);
}

/**
* my_putfd - writes the character x to given fd
* @x: The character to print
* @fd: The filedescriptor to write to
*
* Return: On success 1.
* On error, -1 is returned, and error handling  is set appropriately.
*/
int my_putfd(char x, int fd)
{
static int r;
static char buf[WRITE_BUF_SIZE];

if (x == BUF_FLUSH || r >= WRITE_BUF_SIZE)
{
write(fd, buf, r);
r = 0;
}
if (x != BUF_FLUSH)
buf[r++] = x;
return (1);
}

/**
*my_putsfd - prints an input string
* @str: the string to be printed
* @fd: the filedescriptor to write to
*
* Return: the number of chars put
*/
int  my_putsfd(char *str, int fd)
{
int r = 0;

if (!str)
return (0);
while (*str)
{
r += my_putfd(*str++, fd);
}


return (r);


}
