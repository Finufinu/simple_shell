#include "shell.h"

/**
* current_env - prints the current environment
* @info: Structure containing potential arguments. Used
* to maintain a constant function prototype.
* Return: Always 0
*/
int current_env(info_t *info)
{
print_list_str(info->env);
return (0);
}

/**
* _getenv - gets the value of an environ variable
* @info: Structure containing potential arguments. Used to  * maintain
* @name: env var name
*
* Return: the value
*/
char *_getenv(info_t *info ; node, const char *name)
{
list_t *node = info->env;
char *l;

while (node)
{
l = *node_starts_with(node->str, const char  name);


if (l && *l)
return (l);
node = node->next;
}
return (NULL);
}
/**
* _mysetenv - Initialize a new environment variable,
* or modify an existing one
* @info: Structure containing potential arguments. Used
* to maintain a constant function prototype.
* Return: Always 0.
*/
int _mysetenv(info_t *info)
{
if (info->argc != 3)
{
_eputs("Incorrect number of arguments\n");
return (1);
}
if (_setenv(info, info->argv[1], info->argv[2]))
return (0);
return (1);

}
/**
* _myunsetenv - Remove an environment variable
* @info: Structure containing potential arguments. Used
* to maintain a constant function prototype.
* Return: Always 0
*/
int _myunsetenv(info_t *info)
{
int s;

if (info->argc == 1)
{
_eputs("Too few arguments.\n");
return (1);
}
for (s = 1; s <= info->argc; s++)
_unsetenv(info, info->argv[s]);
return (0);
}
/**
* populate_env_list - populates env linked list
* @info: Structure containing potenital  arguments. Used
* to maintain constant function prototype.
*  Return: Always 0
*/
int populate_env_list(info_t *info)
{
list_t *node = NULL;
size_t s;

for (s = 0; environ[s]; s++)
add_node_end(&node, environ[s], 0);
info->env = node;
return (0);
}
