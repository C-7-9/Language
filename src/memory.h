#ifndef VAL
#define VAL

#include "value.h"

#endif

struct memory {
	struct value *value;
	int *scopes;
};
