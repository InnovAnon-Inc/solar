#if HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define __STDC_VERSION__ 199901L
#define _USE_MATH_DEFINES
#include <math.h>

#include <solar-common.h>
#include <solar.h>

__attribute__ ((nonnull (1, 2), nothrow, warn_unused_result))
int getnextsunriseorsunset (
   struct timeval *restrict timeout,
   coord_t *restrict coord) {
   TODO (implement this method)
   return 0;
}