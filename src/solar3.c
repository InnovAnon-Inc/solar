#include <stdio.h>

#define __STDC_VERSION__ 199901L
#define _USE_MATH_DEFINES
#include <math.h>

#include <solar-common.h>
#include <solar3.h>

/*#define ZENITH -.83*/

/*
Sun's zenith for sunrise/sunset
official = 90 degrees 50'
civil = 96 degrees
nautical = 102 degrees
astronomical = 108 degrees
*/

__attribute__ ((const, nothrow, warn_unused_result))
static double calculateSunrise2_time (
    double N, double lngHour,
    bool sunset) {
    if (! sunset) return N + (( 6 - lngHour) / 24);
    else          return N + ((18 - lngHour) / 24);
}

__attribute__ ((const, nothrow, warn_unused_result))
static double calculateSunrise2_doy (
    int year, int month, int day) {
    double N1, N2, N3;
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunsuffixed-float-constants"

    /* first calculate the day of the year */
    N1 = floor (275 * (double) month / 9);
    N2 = floor ((double) (month + 9) / 12);
    N3 = (1 + floor ((double) (year - 4 * floor((double) year / 4) + 2) / 3));
    return N1 - (N2 * N3) + day - 30;
	#pragma GCC diagnostic pop
}

__attribute__ ((const, nothrow, warn_unused_result))
static double sindeg (double deg) { return radians2degrees (sin (degrees2radians (deg))); }

__attribute__ ((const, nothrow, warn_unused_result))
static double cosdeg (double deg) { return radians2degrees (cos (degrees2radians (deg))); }

__attribute__ ((const, nothrow, warn_unused_result))
static double tandeg (double deg) { return radians2degrees (tan (degrees2radians (deg))); }

__attribute__ ((const, nothrow, warn_unused_result))
static double atandeg (double deg) { return radians2degrees (atan (degrees2radians (deg))); }

__attribute__ ((const, nothrow, warn_unused_result))
static double asindeg (double deg) { return radians2degrees (asin (degrees2radians (deg))); }

__attribute__ ((const, nothrow, warn_unused_result))
static double acosdeg (double deg) { return radians2degrees (acos (degrees2radians (deg))); }

__attribute__ ((const, nothrow, warn_unused_result))
double calculateSunrise2 (
    int year, int month, int day,
    double latitude, double longitude,
    int localOffset, bool sunset, double zenith) {
    /*double N1, N2, N3,*/double N;
    double lngHour;
    double t;
    double M;
    double L;
    double RA;
    double Lquadrant, RAquadrant;
    double sinDec, cosDec;
    double cosH;
    double H;
    double T;
    double UT;
    double localT;
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunsuffixed-float-constants"

    /* first calculate the day of the year */
    /*N1 = floor (275 * (double) month / 9);
    N2 = floor ((double) (month + 9) / 12);
    N3 = (1 + floor ((double) (year - 4 * floor((double) year / 4) + 2) / 3));
    N = N1 - (N2 * N3) + day - 30;*/
    N = calculateSunrise2_doy (year, month, day);

    /* convert the longitude to hour value and calculate an approximate time */
    lngHour = longitude / 15;

    /*if (! sunset) t = N + (( 6 - lngHour) / 24);
    else          t = N + ((18 - lngHour) / 24);*/
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wtraditional-conversion"
    t = calculateSunrise2_time (N, lngHour, sunset);
	#pragma GCC diagnostic pop

    /* calculate the Sun's mean anomaly */
    M = (0.9856 * t) - 3.289;

    /* calculate the Sun's true longitude */
    L = M + (1.916 * sindeg(M)) + (0.020 * sindeg(2 * M)) + 282.634;
    L = fmod (L, 360.0);

    /* calculate the Sun's right ascension */
    RA = atandeg(0.91764 * tandeg(L));
    RA = fmod (360 + RA, 360.0);

    /* right ascension value needs to be in the same quadrant as L */
    Lquadrant  = (floor( L/90)) * 90;
    RAquadrant = (floor(RA/90)) * 90;
    RA = RA + (Lquadrant - RAquadrant);

    /* right ascension value needs to be converted into hours */
    RA = RA / 15;

    /* calculate the Sun's declination */
    sinDec = 0.39782 * sindeg(L);
    cosDec = cosdeg(asindeg(sinDec));

    /* calculate the Sun's local hour angle */
    cosH = (cosdeg(zenith) - (sinDec * sindeg(latitude))) / (cosDec * cosdeg(latitude));

    /*if (! sunset && cosH > 1)*/
        /* the sun never rises on this location (on the specified date) */
        /*return;*/
    /*if (sunset && cosH < -1)*/
        /* the sun never sets on this location (on the specified date) */
        /*return;*/

    /* finish calculating H and convert into hours */
    if (! sunset)
         H = 360 - acosdeg(cosH);
    else
         /*H = acos(cosH);*/
         H = (180/M_PI)*acosdeg(cosH);

    /**/
    if (__builtin_isnan (H)) return H;

    H = H / 15;

    /* calculate local mean time of rising/setting */
    T = H + RA - (0.06571 * t) - 6.622;

    /* adjust back to UTC */
    UT = T - lngHour;
    UT = fmod (24 + UT, 24.0);

    /* convert UT value to local time zone of latitude/longitude */
    localT = UT + localOffset;

    localT = fmod (24 + localT, 24.0);
    return localT;
	#pragma GCC diagnostic pop
}
