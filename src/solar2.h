#ifndef _SOLAR2_H_
#define _SOLAR2_H_

#ifdef __cplusplus
extern "C" {
#endif

float calculateSunrise(int year,int month,int day,float lat, float lng,int localOffset, int daylightSavings)
__attribute__ ((const, leaf, nothrow, warn_unused_result)) ;

void printSunrise()
__attribute__ ((nothrow)) ;

#ifdef __cplusplus
}
#endif

#endif /* _SOLAR2_H_ */