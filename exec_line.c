#include "shell.h"

/**
 * exec_line - finds builtins and commands
 * @hsh: relevant arguments
 *
 * Return: 1 on success.
 */
int exec_line(h_shell *hsh)
{
	int (*builtin)(h_shell *hsh);

	if (hsh->args[0] == NULL)
		return (1);

	builtin = get_builtin(hsh->args[0]);

	if (builtin != NULL)
		return (builtin(hsh));

	return (cmd_exec(hsh));
}
