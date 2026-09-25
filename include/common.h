#ifndef NITAS_COMMON_H
#define NITAS_COMMON_H

#include <stdio.h>
#include <stdbool.h>

#define NITAS_STATIC_ASSERT(expression, information) \
typedef char information[((bool)expression) ? 1 : -1]

#endif