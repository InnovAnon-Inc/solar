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
   return acos (-1.0f);
}

__attribute__ ((const, leaf, nothrow, warn_unused_result))
float calculateSunrise(int year,int month,int day,float lat, float lng,int localOffset, int daylightSavings) {
    /*
    localOffset will be <0 for western hemisphere and >0 for eastern hemisphere
    daylightSavings should be 1 if it is in effect during the summer otherwise it should be 0
    */
    /* 1. first calculate the day of the year */
    float N1 = floorf((float) (275.0f * (float) month / 9.0f));
    float N2 = floorf((float) (((float) month + 9) / 12.0f));
    float N3 = (1 + floorf(((float) year - 4 * floorf((float) year / 4.0f) + 2) / 3.0f));
    float N = N1 - (N2 * N3) + (float) day - 30;

    /* 2. convert the longitude to hour value and calculate an approximate time */
    float lngHour = lng / 15.0f;
    float t = N + ((6 - lngHour) / 24.0f);   /* if rising time is desired: */
    /*float t = N + ((18 - lngHour) / 24)*/   /* if setting time is desired: */

    /* 3. calculate the Sun's mean anomaly */
    float M = (0.9856f * t) - 3.289f;

    /* 4. calculate the Sun's true longitude */
    float L = fmodf(M + (1.916f * sinf((M_PI/180)*M)) + (0.020f * sinf(2 *(M_PI/180) * M)) + 282.634f,360.0f);

    /* 5a. calculate the Sun's right ascension */
    float RA = fmodf(180/M_PI*atanf(0.91764f * tanf((M_PI/180)*L)),360.0f);

    /* 5b. right ascension value needs to be in the same quadrant as L */
    float Lquadrant  = floorf( L/90) * 90;
    float RAquadrant = floorf(RA/90) * 90;

    float sinDec, cosDec;
    float cosH;
    float H;
    float T;
    float UT;

    RA = RA + (Lquadrant - RAquadrant);

    /* 5c. right ascension value needs to be converted into hours */
    RA = RA / 15;

    /* 6. calculate the Sun's declination */
    /*float*/ sinDec = 0.39782f * sinf((M_PI/180)*L);
    /*float*/ cosDec = cosf(asinf(sinDec));

    /* 7a. calculate the Sun's local hour angle */
    /*float*/ cosH = (sinf((M_PI/180)*ZENITH) - (sinDec * sinf((M_PI/180)*lat))) / (cosDec * cosf((M_PI/180)*lat));
    /*
    if (cosH >  1)
    the sun never rises on this location (on the specified date)
    if (cosH < -1)
    the sun never sets on this location (on the specified date)
    */

    /* 7b. finish calculating H and convert into hours */
    /*float*/ H = 360 - (180/M_PI)*acosf(cosH);   /*   if if rising time is desired: */
    /*float H = acos(cosH)*/ /*   if setting time is desired: */
    /*float H = (180/PI)*acos(cosH)*/ /* if setting time is desired: */
    H = H / 15;

    /* 8. calculate local mean time of rising/setting */
    /*float*/ T = H + RA - (0.06571f * t) - 6.622f;

    /* 9. adjust back to UTC */
    /*float*/ UT = fmodf(T - lngHour,24.0f);

    /* 10. convert UT value to local time zone of latitude/longitude */
    return UT + localOffset + daylightSavings;

    }

__attribute__ ((nothrow))
void printSunrise() {
    /*float localT = calculateSunrise(/ *args* /);*/
    float localT=fmod(24 + calculateSunrise(/* args */),24.0f);
    double hours;
    float minutes = modf(localT,&hours)*60;
    printf("%.0f:%.0f",hours,minutes);
    }