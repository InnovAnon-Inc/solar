#ifndef _SOLAR_COMMON_H_
#define _SOLAR_COMMON_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef M_PI
#define M_PI get_PI ()
#endif

double get_PI (void)
__attribute__ ((const, leaf, nothrow, warn_unused_result)) ;

double degrees2radians (double degrees)
__attribute__ ((const, leaf, nothrow, warn_unused_result)) ;

double radians2degrees (double radians)
__attribute__ ((const, leaf, nothrow, warn_unused_result)) ;

int parseInt (int *ret, char const str[])
__attribute__ ((leaf, nonnull (1, 2), nothrow, warn_unused_result)) ;

int parseDouble (double *ret, char const str[])
__attribute__ ((leaf, nonnull (1, 2), nothrow, warn_unused_result)) ;

int parseBool (bool *ret, char const str[])
__attribute__ ((leaf, nonnull (1, 2), nothrow, warn_unused_result)) ;

#ifdef __cplusplus
}
#endif

#endif /* _SOLAR_COMMON_H_ */