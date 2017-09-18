#include <stdlib.h>

#include <solar-common.h>
#include <solar3.h>

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