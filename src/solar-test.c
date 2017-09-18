#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#include <glitter.h>

#include <solar-common.h>
#include <solar.h>
#include <solar2.h>

__attribute__ ((nothrow))
static void printSunrise(
    int year, int month, int day,
    double lat, double lng,
    int localOffset, int daylightSavings, bool sunset) {
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunsuffixed-float-constants"
    #pragma GCC diagnostic ignored "-Wtraditional-conversion"
    /*float localT = calculateSunrise(/ *args* /);*/
    double localT=fmod (24 + calculateSunrise (
        year, month, day, lat, lng, localOffset, daylightSavings, sunset),
        24.0);
	#pragma GCC diagnostic pop
    double hours;
    double minutes = modf (localT, &hours)*60;
    printf("%2.0g:%2.0g\n",hours,minutes);
}

__attribute__ ((nothrow, warn_unused_result))
static int solar_test(
    int year, int month, int day,
    double lat, double lon
) {
   double rlat = lat * M_PI/180;
   double rlong = lon * M_PI/180;

   double _AngleOfDay = AngleOfDay ( day , month , year );

   double _Declinaison;
   double _EqOfTime;
   double _DayDuratInHours;
   double _Excentricity;
   double _TheoreticRadiation;
   double _CalclulateSunriseLocalTime;
   double _CalculateSunsetLocalTime;

   /*cout << "Angle of day: " << _AngleOfDay << "\n";*/
   printf ("Angle of day: %g\n", _AngleOfDay);

   /*double*/ _Declinaison = Declination (_AngleOfDay);
   /*cout << "Declination (Delta): " << _Declinaison << "\n";*/
   printf ("Declination (Delta): %g\n", _Declinaison);

   /*double*/ _EqOfTime = EqOfTime (_AngleOfDay);
   /*cout << "Declination (Delta): " << _EqOfTime << "\n";*/
   printf ("EqOfTime: %g\n", _EqOfTime);

   /*double*/ _DayDuratInHours = DayDuratInHours (_Declinaison, rlat);
   /*cout << "Day duration: " << _DayDuratInHours << "\n";*/
   printf ("Day duration: %g\n", _DayDuratInHours);

   /*double*/ _Excentricity = Excentricity(day, month, year);
   /*cout << "Excentricity: " << _Excentricity << "\n";*/
   printf ("Eccentricity: %g\n", _Excentricity);

   /*double*/ _TheoreticRadiation = TheoreticRadiation(day, month, year, rlat);
   /*cout << "Theoretical radiation: " << _TheoreticRadiation << "\n";*/
   printf ("Theoretical radiation: %g\n", _TheoreticRadiation);

   /*double*/ _CalclulateSunriseLocalTime = CalclulateSunriseLocalTime
                   (day, month, year, rlong, rlat);
   /*cout << "Sunrise Local Time: " << _CalclulateSunriseLocalTime << "\n";*/
   printf ("Sunrise Local Time: %g\n", _CalclulateSunriseLocalTime);

   /*double*/ _CalculateSunsetLocalTime = CalculateSunsetLocalTime
       (day, month, year, rlong, rlat);
   /*cout << "Sunrise Local Time: " << _CalculateSunsetLocalTime << "\n";*/
   printf ("Sunset Local Time: %g\n", _CalculateSunsetLocalTime);

   return 0;
}

int main (void) {
    int year  = 2017;
    int month = 5;
    int day   = 19;
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunsuffixed-float-constants"
    double latitude =  0.0;
    double longitude = 0.0;
	#pragma GCC diagnostic pop
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wtraditional-conversion"
    printSunrise (year, month, day, latitude, longitude, 0, 0, false);
    printSunrise (year, month, day, latitude, longitude, 0, 0, true);
	#pragma GCC diagnostic pop
    error_check (solar_test   (year, month, day, latitude, longitude) != 0)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}