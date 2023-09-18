#include "shell.h"

/**
* get_environ - returns the string array copy of our environ
* @info: Structure containing potential arguments. Used to maintain
*          constant function prototype.
* Return: Always 0
*/
char **get_environ(info_t *info)
{
if (!info->environ || info->env_changed)
{
info->environ = list_to_strings(info->env);
info->env_changed = 0;
}

return (info->environ);
}

/**
*  _myunsetenv - Remove an environment variable
* @info: Structure containing potential arguments. Used to maintain
*        constant function prototype.
*  Return: 1 on delete, 0 otherwise
* @var: the string env var property
*/
int _myunsetenv(info_t *info, char *var)
{
list_t *node = info->env;
Size_t  j = 0;
char *p;

if (!node || !var)
return (0);

while (node)
{
p = starts_with(node->str, var);
if (p && *p == '=')
{
info->env_changed = delete_node_at_index(&(info->env), i);
J = 0;
node = info->env;
continue;
}
node = node->next;
j++;
}
return (info->env_changed);
}
