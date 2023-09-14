#include "shell.h"


/**
* unset_alias - set alias to string
* @info: parameter struct
* @str: string alias
*
* Return: Return 0 on success, 1 on error
*/
int unset_alias(info_t *info, char *str)
{
char *p, c;
int ret;

p = _strchr(str, '=');
if (!p)
return (1);
c = *p;
*p = 0;
c = delete_node_at_index(str&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
*p = c;
return (ret);
}

/**
* set_alias - set alias to string
* @info: parameter struct
* @str: string alias
*
* Return: Return 0 on success, 1 on error
*/
int set_alias(info_t *info, char *str)
{
char *r;

r = _strchr(str, '=');
if (!r)
return (1);
if (!*++r)
return (unset_alias(info, str));

unset_alias(info, str);
return (add_node_end(&(info->alias), str, 0) == NULL);
}
/**
* print_alias - prints alias string
* @node: the alias node
*
* Return: Return 0 on success, 1 on error
*/
int print_alias(list_t *node)
{
char *c = NULL, *a = NULL;

if (node)
{
c = _strchr(node->str, '=');
for (a = node->str; a <= c; a++)
_putchar(*a);
_putchar('\'');
_puts(c + 1);
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
char *s = NULL;
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

s = _strchr(info->argv[i], '=');
if (s)

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
char *a, *dir, buffer[1040];
int chdir_ret;

a = getcwd(buffer, 1040);
if (!a)
_puts("TODO: >>getcwd failure emsg here<<\n");
if (!info->argv[1])
{
dir = _getenv(info, "HOME=");
if (!dir)
chdir_ret = /* TODO: what should this be? */
chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
else
chdir_ret = chdir(dir);
}
else if (_strcmp(info->argv[1], "-") == 0)
{
if (!_getenv(info, "OLDPWD="))
{
_puts(a);
_putchar('\n');
return (1);
}
_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
chdir_ret = /* TODO: what should this be? */
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
