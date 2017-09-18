#ifndef _SOLAR_H_
#define _SOLAR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/time.h>

#include <glitter.h>

typedef struct {
	double latitude;  /* x */
	double longitude; /* y */
	double altitude;  /* z */
} coord_t;

int getnextsunriseorsunset (
   struct timeval *restrict timeout,
   coord_t *restrict coord)
__attribute__ ((nonnull (1, 2), nothrow, warn_unused_result)) ;

#ifdef __cplusplus
}
#endif

#endif /* _SOLAR_H_ */