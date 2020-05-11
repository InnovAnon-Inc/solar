#if HAVE_CONFIG_H
#include <config.h>
#endif

#define XOPEN_SOURCE 600
/*#define _BSD_SOURCE
#define _SVID_SOURCE*/
#define _DEFAULT_SOURCE
#define _ISOC99_SOURCE
#define _POSIX_C_SOURCE 200112L

#include <errno.h>
#include <limits.h>
#include <stdlib.h>

#include <math.h>

#include <glitter.h>

#include <solar-common.h>

__attribute__ ((const, leaf, nothrow, warn_unused_result))
double get_PI (void) {
#ifdef __asm
	double pi;
	__asm
	{
		fldpi
		fstp pi
	}
	return pi;
#else
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunsuffixed-float-constants"
	return acos (-1.0);
	#pragma GCC diagnostic pop
#endif
}

__attribute__ ((const, leaf, nothrow, warn_unused_result))
double degrees2radians (double degrees) {
	double ret;
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunsuffixed-float-constants"
	degrees = fmod (360 + degrees, 360.0);
	ret = degrees * 2 * M_PI / 360;
	ret = fmod (2 * M_PI + ret, 2 * M_PI);
	return ret;
	#pragma GCC diagnostic pop
}

__attribute__ ((const, leaf, nothrow, warn_unused_result))
double radians2degrees (double radians) {
	double ret;
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunsuffixed-float-constants"
	radians = fmod (2 * M_PI + radians, 2 * M_PI);
	ret = radians * 360 / (2 * M_PI);
	ret = fmod (360 + ret, 360.0);
	return ret;
	#pragma GCC diagnostic pop
}
