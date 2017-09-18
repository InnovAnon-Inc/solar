#ifndef _SOLAR_COMMON_H_
#define _SOLAR_COMMON_H_

#ifdef __cplusplus
extern "C" {
#endif

#define __STDC_VERSION__ 199901L
#define _USE_MATH_DEFINES
#include <math.h>

#ifndef M_PI
#define M_PI get_PI ()
#endif

double get_PI (void)
__attribute__ ((const, leaf, nothrow, warn_unused_result)) ;

#ifdef __cplusplus
}
#endif

#endif /* _SOLAR_COMMON_H_ */