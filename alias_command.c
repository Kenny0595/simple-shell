#include "shell.h"

/**
 * execute_alias - Handles the alias built-in command
 *
 * @args: The command and its arguments are contained in an array of strings.
 * this code is written by KENNY and MBULA
 */

static Alias aliases[MAX_ALIASES];
static int num_aliases;

void execute_alias(char **args)
{
	int i;

	if (args[1] == NULL)
	{
		print_all_aliases();
		return;
	}
	for (i = 1; args[i] != NULL; i++)
	{
		char *name = NULL;
		char *value = NULL;
		char *equal_sign = strchr(args[i], '=');

		if (equal_sign != NULL)
		{
			*equal_sign = '\0';
			name = args[i];
			value = equal_sign + 1;
		}
		else
		{
			name = args[i];
			value = get_alias_value(name);
		}
		if (value != NULL)
		{
			update_alias(name, value);
		}
		else
		{
			add_alias(name, value);
		}
	}
}

/**
 * print_all_aliases - Prints all aliases
 * this code is written by KENNY and MBULA
 */

void print_all_aliases(void)
{
	int i;

	for (i = 0; i < num_aliases; i++)
	{
		printf("%s='%s'\n", aliases[i].name, aliases[i].value);
	}
}

/**
 * get_alias_value - Determine the value of an alias based on its name.
 *
 * @name: The name of the alias
 * Return: The alias value or NULL if not found
 * this code is written by KENNY and MBULA
 */

char *get_alias_value(const char *name)
{
	int i;

	for (i = 0; i < num_aliases; i++)
	{
		if (strcmp(aliases[i].name, name) == 0)
		{
			return (aliases[i].value);
		}
	}
	return (NULL);
}

/**
 * add_alias - Insert a new alias into the aliases array.
 *
 * @name: The arrays new name
 * @value: The value of the alias
 * this code is written by KENNY and MBULA
 */

void add_alias(const char *name, const char *value)
{
	if (num_aliases >= MAX_ALIASES)
	{
		fprintf(stderr, "Error: Maximum number of aliases reached.\n");
		return;
	}
	aliases[num_aliases].name = safe_strdup(name);
	aliases[num_aliases].value = safe_strdup(value);
	num_aliases++;
}

/**
 * update_alias - Update the value of an existing alias
 *
 * @name: The arrays new name
 * @value: The new value of the alias
 * this code is written by KENNY and MBULA
 */

void update_alias(const char *name, const char *value)
{
	int i;

	for (i = 0; i < num_aliases; i++)
	{
		if (strcmp(aliases[i].name, name) == 0)
		{
			free(aliases[i].value);
			aliases[i].value = safe_strdup(value);
			return;
		}
	}
}