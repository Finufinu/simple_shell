#include "shell.h"


/**
* unset_alias - sets alias to string.
* @info: parameter struct.
* @str: the string alias.
*
* Return: Always 0 on success, 1 on error.
*/
int unset_alias(info_t *info, char *str)
{
char *p, l;
int ret;

p = _strchr(str, '=');
if (!p)
return (1);
l = *p;
*p = 0;
ret = delete_node_at_index(&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
*p = l;
return (ret);
}

/**
* set_alias - sets alias to string
* @info: parameter struct
* @str: the string alias
*
* Return: Always 0 on success, 1 on error
*/
int set_alias(info_t *info, char *str)
{
char *p;

p = _strchr(str, '=');
if (!p)
return (1);
if (!*++p)
return (unset_alias(info, str));

unset_alias(info, str);
return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
* print_alias - prints an alias string
* @node: the alias node
*
* Return: Always 0 on success, 1 on error
*/
int print_alias(list_t *node)
{
char *p = NULL, *a = NULL;

if (node)
{
p = _strchr(node->str, '=');
for (a = node->str; a <= p; a++)
_putchar(*a);
_putchar('\'');
_puts(p + 1);
_puts("'\n");
return (0);
}
return (1);
}

/**
* _myalias - mimics the alias builtin (man alias)
* @info: Structure containing potential arguments. Used to maintain
*          constant function prototype.
*  Return: Always 0
*/
int _myalias(info_t *info)
{
int i = 0;
char *p = NULL;
list_t *node = NULL;

if (info->argc == 1)
{
node = info->alias;
while (node)
{
print_alias(node);
node = node->next;
}
return (0);
}
for (i = 1; info->argv[i]; i++)
{
p = _strchr(info->argv[i], '=');
if (p)
set_alias(info, info->argv[i]);
else
print_alias(node_starts_with(info->alias, info->argv[i], '='));
}

return (0);
}

/**
* _mycd - changes the current directory of the process
* @info: Structure containing potential arguments. Used to maintain
*          constant function prototype.
*  Return: Always 0
*/
int _mycd(info_t *info)
{
char *d, *dir, buffer[1040];
int chdir_ret;

	d = getcwd(buffer, 1040);
if (!d)
_puts("TODO: >>getcwd failure emsg here<<\n");
if (!info->argv[1])
{
dir = _getenv(info, "HOME=");
if (!dir)
chdir_ret = /* what should this be? */
chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
else
chdir_ret = chdir(dir);
}
else if (_strcmp(info->argv[1], "-") == 0)
{
if (!_getenv(info, "OLDPWD="))
{
_puts(d);
_putchar('\n');
return (1);
}
_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
chdir_ret = /* what should this be? */
chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
}
else
chdir_ret = chdir(info->argv[1]);
if (chdir_ret == -1)
{
print_error(info, "can't cd to ");
_eputs(info->argv[1]), _eputchar('\n');
}
else
{
_setenv(info, "OLDPWD", _getenv(info, "PWD="));
_setenv(info, "PWD", getcwd(buffer, 1040));
}
return (0);
}
