#include "shell.h"

/**
 * get_help - function that retrieves help messages according builtin
 * @hsh: data structure (args and input)
 *
 * Return: 0 on success
*/
int get_help(h_shell *hsh)
{

	if (hsh->args[1] == 0)
		help_general();
	else if (_strcmp(hsh->args[1], "setenv") == 0)
		help_setenv();
	else if (_strcmp(hsh->args[1], "env") == 0)
		help_env();
	else if (_strcmp(hsh->args[1], "unsetenv") == 0)
		help_unsetenv();
	else if (_strcmp(hsh->args[1], "help") == 0)
		help_help();
	else if (_strcmp(hsh->args[1], "exit") == 0)
		help_exit();
	else if (_strcmp(hsh->args[1], "cd") == 0)
		help_cd();
	else if (_strcmp(hsh->args[1], "alias") == 0)
		help_alias();
	else
		write(STDERR_FILENO, hsh->args[0],
		      _strlen(hsh->args[0]));

	hsh->status = 0;
	return (1);
}
