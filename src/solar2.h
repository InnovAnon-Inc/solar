#ifndef _SOLAR2_H_
#define _SOLAR2_H_

#ifdef __cplusplus
extern "C" {
#endif

double calculateSunrise(
   int year, int month, int day,
   double lat, double lng,
   int localOffset, int daylightSavings, bool sunset)
__attribute__ ((const, leaf, nothrow, warn_unused_result)) ;

void printSunrise(
   int year, int month, int day,
    double lat, double lng,
    int localOffset, int daylightSavings, bool sunset)
__attribute__ ((nothrow)) ;

#ifdef __cplusplus
}
#endif

#endif /* _SOLAR2_H_ */