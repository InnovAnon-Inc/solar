#ifndef _SOLAR3_H_
#define _SOLAR3_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

double calculateSunrise2 (
   int year, int month, int day,
   double lat, double lng,
   int localOffset, int daylightSavings, bool sunset)
__attribute__ ((const, leaf, nothrow, warn_unused_result)) ;

#ifdef __cplusplus
}
#endif

#endif /* _SOLAR3_H_ */