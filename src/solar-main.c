#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#include <glitter.h>

#include <solar-common.h>
#include <solar3.h>

__attribute__ ((nothrow))
static void printSunrise2(
    int year, int month, int day,
    double lat, double lng,
    int localOffset, bool sunset, double zenith) {
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunsuffixed-float-constants"
	#pragma GCC diagnostic ignored "-Wtraditional-conversion"
    /*float localT = calculateSunrise(/ *args* /);*/
    double localT=fmod (24 + calculateSunrise2 (
        year, month, day, lat, lng, localOffset, sunset, zenith),
        24.0);
	#pragma GCC diagnostic pop
    double hours;
    double minutes = modf (localT, &hours)*60;
    printf("%02d:%02d\n", (int) hours, (int) minutes);
}

__attribute__ ((nonnull (2), nothrow))
int main (int argc, char *argv[]) {
	int year, month, day;
	double latitude, longitude, zenith;
	int localoffset;
	bool sunrise;
	error_check (argc != 9) {
		printf ("Usage: %0 year month day "
		      "latitude longitude zenith "
		      "local_offset sunrise\n",
		      argv[0]);
		return EXIT_FAILURE;
	}
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

	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wtraditional-conversion"
	printSunrise2 (year, month, day, latitude, longitude, localoffset, sunrise,  zenith);
	#pragma GCC diagnostic pop
}