#include "shell.h"

/**
 * get_error - calls the error according to builtin or syntax
 * @hsh: data structure containing arguments
 * @eval: error value
 *
 * Return: error
 */
int get_error(h_shell *hsh, int eval)
{
	char *error;

	switch (eval)
	{
		case -1:
			error = error_env(hsh);
			break;
		case 126:
			error = error_path_126(hsh);
			break;
		case 127:
			error = error_not_found(hsh);
			break;
		case 2:
			if (_strcmp("exit", hsh->args[0]) == 0)
				error = error_exit_shell(hsh);
			else if (_strcmp("cd", hsh->args[0]) == 0)
				error = error_get_cd(hsh);
			break;
	}
	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}
	hsh->status = eval;
	return (eval);
}
