#define __STDC_VERSION__ 199901L
#define _USE_MATH_DEFINES
#include <math.h>

#ifndef M_PI
#define M_PI get_PI ()
#endif

#include <solar2.h>

/*#define PI 3.1415926
#define ZENITH -.83*/

const float ZENITH = -.83f;

__attribute__ ((const, leaf, nothrow, warn_unused_result))
double get_PI (void) {
    /*
   double pi;
   __asm
   {
      fldpi
      fstp pi
   }
   return pi;
   */
   return acos (-1.0);
}

__attribute__ ((const, leaf, nothrow, warn_unused_result))
double calculateSunrise(
    int year, int month, int day,
    double lat, double lng,
    int localOffset, int daylightSavings) {
    /*
    localOffset will be <0 for western hemisphere and >0 for eastern hemisphere
    daylightSavings should be 1 if it is in effect during the summer otherwise it should be 0
    */
    /* 1. first calculate the day of the year */
    double N1 = floor (275.0 * (double) month / 9.0);
    double N2 = floor ((double) (month + 9) / 12.0);
    double N31 = 4 * floor ((double) year / 4.0);
    double N3 = (1 + floor ((year - 4 * N31 + 2) / 3.0));
    double N = N1 - (N2 * N3) + day - 30;

    /* 2. convert the longitude to hour value and calculate an approximate time */
    double lngHour = lng / 15.0;
    double t = N + ((6 - lngHour) / 24.0);   /* if rising time is desired: */
    /*float t = N + ((18 - lngHour) / 24)*/   /* if setting time is desired: */

    /* 3. calculate the Sun's mean anomaly */
    double M = (0.9856 * t) - 3.289;

    /* 4. calculate the Sun's true longitude */
    double L1 = 1.916 * sin ((M_PI / 180) * M);
    double L2 = 0.020 * sin (2 *(M_PI / 180) * M);
    double L = fmod (M + L1 + L2 + 282.634, 360.0);

    /* 5a. calculate the Sun's right ascension */
    double RA1 = 0.91764 * tan ((M_PI/180)*L);
    double RA = fmod (180/M_PI*atan (RA1), 360.0);

    /* 5b. right ascension value needs to be in the same quadrant as L */
    double Lquadrant  = floor ( L/90) * 90;
    double RAquadrant = floor (RA/90) * 90;

    double sinDec, cosDec;
    double cosH1, cosH2, cosH3;
    double cosH;
    double H;
    double T;
    double UT;

    RA = RA + (Lquadrant - RAquadrant);

    /* 5c. right ascension value needs to be converted into hours */
    RA = RA / 15.0;

    /* 6. calculate the Sun's declination */
    /*float*/ sinDec = 0.39782 * sin ((M_PI/180)*L);
    /*float*/ cosDec = cos (asin (sinDec));

    /* 7a. calculate the Sun's local hour angle */
    cosH1 = sin ((M_PI/180)*ZENITH);
    cosH2 = sin ((M_PI/180)*lat);
    cosH3 = cos ((M_PI/180)*lat);
    /*float*/ cosH = (cosH1 - (sinDec * cosH2)) / (cosDec * cosH3);
    /*
    if (cosH >  1)
    the sun never rises on this location (on the specified date)
    if (cosH < -1)
    the sun never sets on this location (on the specified date)
    */

    /* 7b. finish calculating H and convert into hours */
    /*float*/ H = 360 - (180/M_PI) * acos (cosH);   /*   if if rising time is desired: */
    /*float H = acos(cosH)*/ /*   if setting time is desired: */
    /*float H = (180/PI)*acos(cosH)*/ /* if setting time is desired: */
    H = H / 15;

    /* 8. calculate local mean time of rising/setting */
    /*float*/ T = H + RA - (0.06571 * t) - 6.622;

    /* 9. adjust back to UTC */
    /*float*/ UT = fmod (T - lngHour, 24.0);

    /* 10. convert UT value to local time zone of latitude/longitude */
    return UT + localOffset + daylightSavings;

    }

__attribute__ ((nothrow))
void printSunrise() {
    /*float localT = calculateSunrise(/ *args* /);*/
    double localT=fmod(24 + calculateSunrise(/* args */),24.0f);
    double hours;
    double minutes = modf(localT,&hours)*60;
    printf("%.0g:%.0g",hours,minutes);
    }