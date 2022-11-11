#include "shell.h"

/**
 * copy_info - copies info to create
 * a new env or alias
 * @name: name (env or alias)
 * @value: value (env or alias)
 *
 * Return: new env or alias.
 */
char *copy_info(char *name, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = _strlen(name);
	len_value = _strlen(value);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * (len));
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);
	_strcat(new, "\0");

	return (new);
}

/**
 * set_env - sets an environment variable
 * @name: name of the environment variable
 * @value: value of the environment variable
 * @hsh: data structure (environ)
 *
 * Return: no return
 */
void set_env(char *name, char *value, h_shell *hsh)
{
	int i;
	char *var_env, *name_env;

	for (i = 0; hsh->_environ[i]; i++)
	{
		var_env = _strdup(hsh->_environ[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, name) == 0)
		{
			free(hsh->_environ[i]);
			hsh->_environ[i] = copy_info(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	hsh->_environ = _reallocdp(hsh->_environ, i, sizeof(char *) * (i + 2));
	hsh->_environ[i] = copy_info(name, value);
	hsh->_environ[i + 1] = NULL;
}

/**
 * _setenv - compares env variables names
 * with the name passed.
 * @hsh: data relevant (env name and env value)
 *
 * Return: 1 on success.
 */
int _setenv(h_shell *hsh)
{

	if (hsh->args[1] == NULL || hsh->args[2] == NULL)
	{
		get_error(hsh, -1);
		return (1);
	}

	set_env(hsh->args[1], hsh->args[2], hsh);

	return (1);
}

/**
 * _unsetenv - deletes a environment variable
 * @hsh: relevant data (env name)
 *
 * Return: 1 on success.
 */
int _unsetenv(h_shell *hsh)
{
	char **realloc_environ;
	char *var_env, *name_env;
	int i, j, k;

	if (hsh->args[1] == NULL)
	{
		get_error(hsh, -1);
		return (1);
	}
	k = -1;
	for (i = 0; hsh->_environ[i]; i++)
	{
		var_env = _strdup(hsh->_environ[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, hsh->args[1]) == 0)
		{
			k = i;
		}
		free(var_env);
	}
	if (k == -1)
	{
		get_error(hsh, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (i));
	for (i = j = 0; hsh->_environ[i]; i++)
	{
		if (i != k)
		{
			realloc_environ[j] = hsh->_environ[i];
			j++;
		}
	}
	realloc_environ[j] = NULL;
	free(hsh->_environ[k]);
	free(hsh->_environ);
	hsh->_environ = realloc_environ;
	return (1);
}
