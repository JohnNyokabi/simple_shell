#include "shell.h"

/**
 * exit_shell - exits the shell
 * @hsh: relevant data (status and args)
 *
 * Return: 0 on success.
 */
int exit_shell(h_shell *hsh)
{
	unsigned int ustatus;
	int is_digit;
	int str_len;
	int big_number;

	if (hsh->args[1] != NULL)
	{
		ustatus = _atoi(hsh->args[1]);
		is_digit = _isdigit(hsh->args[1]);
		str_len = _strlen(hsh->args[1]);
		big_number = ustatus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || big_number)
		{
			get_error(hsh, 2);
			hsh->status = 2;
			return (1);
		}
		hsh->status = (ustatus % 256);
	}
	return (0);
}
