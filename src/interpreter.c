#include "interpreter.h"
#include <string.h>

int
run_one_line(struct machine *vm, char *line)
{
	size_t i = 0;
	char *token = strtok(line, " ");
	struct value var;
	char *var_name;
	while (token != NULL) {
		switch (i) {
		case 0:
			if (!strcmp(token, "num"))
				var.type = NUM;
			else if (!strcmp(token, "txt"))
				var.type = TXT;
			else {
			}
			break;
		case 1:
			var_name = token;
			break;
		case 2:
		default:
		}

		token = strtok(NULL, " ");
		i++;
	}

	return 0;
}
