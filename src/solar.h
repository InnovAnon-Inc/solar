#ifndef _SOLAR_H_
#define _SOLAR_H_

#ifdef __cplusplus
extern "C" {
#endif

double RadToHours (double tmp)
__attribute__ ((const, leaf, nothrow, warn_unused_result)) ;

double HoursToRads (double tmp)
__attribute__ ((const, leaf, nothrow, warn_unused_result)) ;

double AngleOfDay (
   int day,     /* number of the day */
   int month,   /* number of the month */
   int year) /* year */
__attribute__ ((const, leaf, nothrow, warn_unused_result)) ;

double Declination (double DayAngle)     /* angle day in radian */
__attribute__ ((const, leaf, nothrow, warn_unused_result)) ;

double EqOfTime (double DayAngle)        /* angle day (radian) */
__attribute__ ((const, nothrow, warn_unused_result)) ;

double DayDurationRadian (double _declination,      /* _declination in radian */
                          double lat)                /* latitude in radian */
__attribute__ ((const, leaf, nothrow, warn_unused_result)) ;

double DayDuratInHours (double _declination     /* _declination in radian */
                  , double lat)              /* latitude in radian */
__attribute__ ((const, nothrow, warn_unused_result)) ;

double Tsv_Tu (double rlong             /* longitude en radian positive a l est. */
               ,double eqOfTime         /* Equation of times en heure */
__attribute__ ((const, leaf, nothrow, warn_unused_result)) ;

double Excentricity(int day,
                    int month,
                    int year)
__attribute__ ((const, nothrow, warn_unused_result)) ;

double TheoreticRadiation(int day, int month, int year,
                            double lat          /* Latitude in radian ! */
__attribute__ ((const, nothrow, warn_unused_result)) ;

double CalclulateSunriseLocalTime(int day,
                        int month,
                        int year,
                        double rlong,
                        double rlat)
__attribute__ ((nothrow, warn_unused_result)) ;

double CalculateSunsetLocalTime(int day,
                          int month,
                          int year,
                          double rlong,
                          double rlat)
__attribute__ ((nothrow, warn_unused_result)) ;

double CalculateSunriseUniversalTime(int day,
                        int month,
                        int year,
                        double rlong,
                        double rlat)
__attribute__ ((const, nothrow, warn_unused_result)) ;

double CalculateSunsetUniversalTime(int day,
                          int month,
                          int year,
                          double rlong,
                          double rlat)
__attribute__ ((const, nothrow, warn_unused_result)) ;

double SolarHeight (int tu,     /* universal times (0,1,2,.....,23) */
                      int day,
                      int month,
                      int year,
                      double lat,   /* latitude in radian */
                      double rlong)  /* longitude in radian */
__attribute__ ((const, nothrow, warn_unused_result)) ;

int julian(int year, int month, int day)
__attribute__ ((const, leaf, nothrow, warn_unused_result)) ;

int solar_test(int argc, /*_TCHAR*/ char* argv[])
__attribute__ ((nothrow, warn_unused_result)) ;

#ifdef __cplusplus
}
#endif

#endif /* _SOLAR_H_ */