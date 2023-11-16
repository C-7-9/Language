#include "memory.h"

struct machine {
	struct memory mem;
};

int
run_one_line(struct machine *, char *);
