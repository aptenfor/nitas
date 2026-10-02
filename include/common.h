#ifndef NITAS_COMMON_H
#define NITAS_COMMON_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#define NITAS_STATIC_ASSERT(expression, information) \
typedef char information[((bool)(expression)) ? 1 : -1]

#define nitas_malloc malloc
#define nitas_free free

typedef long long NitasInt;

#endif
