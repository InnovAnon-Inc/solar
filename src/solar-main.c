__attribute__ ((leaf, nonnull (1, 2), nothrow, warn_unused_result))
int parseInt (int *ret, char const str[]) {
	char *endptr;
	errno = 0;
	long int tmp = strtol (str, &endptr, 0);
	error_check (tmp == LONG_MIN && errno == ERANGE) return -2;
	error_check (tmp == LONG_MAX && errno == ERANGE) return -3;
	error_check (tmp == 0        && errno != 0)      return -4;
	/*error_check (endptr != NULL) return -1;*/
	error_check (endptr == str)   return -5;
	error_check (tmp < INT_MIN) return -7;
	error_check (tmp > INT_MAX) return -8;
	*ret = tmp;
	error_check (*endptr != '\0') return -6;
	return 0;
}

__attribute__ ((leaf, nonnull (1, 2), nothrow, warn_unused_result))
int parseDouble (double *ret, char const str[]) {
	char *endptr;
	errno = 0;
	*ret = strtod (str, &endptr, 0);
	error_check (*ret == HUGE_VAL && errno == ERANGE) return -2;
	error_check (*ret == HUGE_VAL && errno == ERANGE) return -3;
	error_check (*ret == 0        && errno != 0)      return -4;
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

__attribute__ ((nonnull (2), nothrow))
int main (int argc, char *argv[]) {
	int year, month, day;
	double latitude, longitude, zenith;
	int localoffset;
	bool sunrise;
	error_check (parseInt    (&year,        argv[1]) != 0) return EXIT_FAILURE;
	TODO (validate year);
	error_check (parseInt    (&month,       argv[2]) != 0) return EXIT_FAILURE;
	error_check (month < 1 || month > 12) return EXIT_FAILURE;
	error_check (parseInt    (&day,         argv[3]) != 0) return EXIT_FAILURE;
	error_check (parseDouble (&latitude,    argv[4]) != 0) return EXIT_FAILURE;
	error_check (parseDouble (&longitude,   argv[5]) != 0) return EXIT_FAILURE;
	error_check (parseDouble (&zenith,      argv[6]) != 0) return EXIT_FAILURE;
	error_check (parseInt    (&localoffset, argv[7]) != 0) return EXIT_FAILURE;
	error_check (parseBool   (&sunrise,     argv[8]) != 0) return EXIT_FAILURE;

	printSunrise2 (year, month, day, latitude, longitude, localoffset, true,  zenith);
}