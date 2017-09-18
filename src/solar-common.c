#define XOPEN_SOURCE 600
#define _BSD_SOURCE
#define _SVID_SOURCE
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

__attribute__ ((leaf, nonnull (1, 2), nothrow, warn_unused_result))
int parseLong (long int *ret, char const str[]) {
	char *endptr;
	long int tmp;
	errno = 0;
	tmp = strtol (str, &endptr, 0);
	error_check (tmp == LONG_MIN && errno == ERANGE) return -2;
	error_check (tmp == LONG_MAX && errno == ERANGE) return -3;
	error_check (tmp == 0        && errno != 0)      return -4;
	/*error_check (endptr != NULL) return -1;*/
	error_check (endptr == str)   return -5;
	*ret = tmp;
	error_check (*endptr != '\0') return -6;
	return 0;
}

__attribute__ ((leaf, nonnull (1, 2), nothrow, warn_unused_result))
int parseInt (int *ret, char const str[]) {
	long int tmp;
	error_check (parseLong (&tmp, str) != 0) return -1;
	error_check (tmp < INT_MIN) return -2;
	error_check (tmp > INT_MAX) return -3;
	*ret = (int) tmp;
	return 0;
}

__attribute__ ((leaf, nonnull (1, 2), nothrow, warn_unused_result))
int parseDouble (double *ret, char const str[]) {
	char *endptr;
	errno = 0;
	*ret = strtod (str, &endptr);
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wfloat-equal"
	error_check (*ret == HUGE_VAL && errno == ERANGE) return -2;
	error_check (*ret == HUGE_VAL && errno == ERANGE) return -3;
	error_check (*ret == 0        && errno != 0)      return -4;
	#pragma GCC diagnostic pop
	/*error_check (endptr != NULL) return -1;*/
	error_check (endptr == str)   return -5;
	error_check (*endptr != '\0') return -6;
	return 0;
}

__attribute__ ((leaf, nonnull (1, 2), nothrow, warn_unused_result))
int parseBool (bool *ret, char const str[]) {
	int tmp;
	error_check (parseInt (&tmp, str) != 0) return -1;
	*ret = !! tmp;
	return 0;
}
