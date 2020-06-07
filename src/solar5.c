#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

/*#ifndef _BSD_SOURCE*/
/*#define _BSD_SOURCE*/
#define _DEFAULT_SOURCE
/*#endif*/
/*#ifndef _ISOC99_SOURCE*/
#define _ISOC99_SOURCE
/*#endif*/
/*#ifndef _XOPEN_SOURCE*/
#define _XOPEN_SOURCE 500
/*#endif*/
/*#ifndef _POSIX_C_SOURCE*/
#define _POSIX_C_SOURCE 200112L
/*#endif*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <glitter.h>

#ifndef M_PI
#define M_PI (acos (-1))
#endif

	/*bool isNumber(char const *s) ;*/
	bool isNumber (double s);

	#pragma GCC dianostic push
	#pragma GCC diagnostic ignored "-Wunsuffixed-float-constants"
	#pragma GCC diagnostic ignored "-Wtraditional-conversion"
/***********************************************************************/
/*	DATA STRUCTURES									*/
/***********************************************************************/
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wpadded"
	typedef struct {
		char const *name;
		char const *abbr;
		unsigned int   numdays;
	} month_t;
	#pragma GCC diagnostic pop

	void month(month_t *month, char const *name, unsigned int numdays, char const *abbr) ;

	void month(month_t *month, char const *name, unsigned int numdays, char const *abbr) 
	{
		month->name = name;
		month->numdays = numdays;
		month->abbr = abbr;
	}

/*********************************************************************/
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wpadded"
	typedef struct {
		char const *daySave;
		int value;
	} ans_t;
	#pragma GCC diagnostic pop

	void ans(ans_t *ans, char const *daySave,int value) ;

	void ans(ans_t *ans, char const *daySave,int value)
	{
		ans->daySave = daySave;
		ans->value = value;
	}

/*********************************************************************/
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wpadded"
	typedef struct {
		char const *name;
		double lat;
		double lng;
		double zoneHr;
	} city_t;
	#pragma GCC diagnostic pop

	void city(city_t *city, char const *name, double lat, double lng, double zoneHr) ;
		
	void city(city_t *city, char const *name, double lat, double lng, double zoneHr) 
	{
		city->name = name;
		city->lat = lat;
		city->lng = lng;
		city->zoneHr = zoneHr;
	}


/***********************************************************************/
/*	Data for Selectbox Controls							*/
/***********************************************************************/

	/*month_t monthList[12];*/
	void initMonthList (month_t monthList[12]) ;

	void initMonthList (month_t monthList[12]) {
	/*var monthList = new Array();*/	/*	list of months and days for non-leap year*/
	/*var i = 0;*/
	month(&(monthList[0]),  "January",   31, "Jan");
	month(&(monthList[1]),  "February",  28, "Feb");
	month(&(monthList[2]),  "March",     31, "Mar");
	month(&(monthList[3]),  "April",     30, "Apr");
	month(&(monthList[4]),  "May",       31, "May");
	month(&(monthList[5]),  "June",      30, "Jun");
	month(&(monthList[6]),  "July",      31, "Jul");
	month(&(monthList[7]),  "August",    31, "Aug");
	month(&(monthList[8]),  "September", 30, "Sep");
	month(&(monthList[9]),  "October",   31, "Oct");
	month(&(monthList[10]), "November",  30, "Nov");
	month(&(monthList[11]), "December",  31, "Dec");
	}

/*********************************************************************/
	/*ans_t YesNo[2];*/
	/*var YesNo = new Array();*/	/*Daylight Saving array	*/
	/*i=0;*/
	void initYesNo (ans_t YesNo[2]) ;

	void initYesNo (ans_t YesNo[2]) {
	ans(&(YesNo[0]), "No",0);
	ans(&(YesNo[1]), "Yes",60);
	}
/*********************************************************************/

	/*var City = new Array();*/
	/*city_t City[93];*/

	/*j = 0;*/
	void initCity (city_t City[93]) ;

	void initCity (city_t City[93]) {
	city(&(City[0]),  "Enter Lat/Long -->",0,      0,      0);
	city(&(City[1]),  "",                  0,      0,      0);
	city(&(City[2]),  "US CITIES",         0,      0,      0);
	city(&(City[3]),  "Albuquerque, NM",   35.0833,106.65, 7);
	city(&(City[4]),  "Anchorage, AK",     61.217, 149.90, 9);
	city(&(City[5]),  "Atlanta, GA",       33.733, 84.383, 5);
	city(&(City[6]),  "Austin, TX",        30.283, 97.733, 6);
	city(&(City[7]),  "Birmingham, AL", 33.521, 86.8025, 6);
	city(&(City[8]),  "Bismarck, ND", 46.817, 100.783, 6);
	city(&(City[9]),  "Boston, MA", 42.35, 71.05, 5);
	city(&(City[10]), "Boulder, CO", 40.125, 105.237, 7);
	city(&(City[11]), "Chicago, IL", 41.85,87.65,6);
	city(&(City[12]), "Dallas, TX", 32.46, 96.47,6);
	city(&(City[13]), "Denver, CO", 39.733, 104.983, 7);
	city(&(City[14]), "Detroit, MI", 42.333, 83.05, 5);
	city(&(City[15]), "Honolulu, HI", 21.30, 157.85, 10);
	city(&(City[16]), "Houston, TX", 29.75, 95.35, 6);
	city(&(City[17]), "Indianapolis, IN", 39.767, 86.15, 5);
	city(&(City[18]), "Jackson, MS", 32.283, 90.183, 6);
	city(&(City[19]), "Kansas City, MO", 39.083, 94.567,6);
	city(&(City[20]), "Los Angeles, CA",34.05,118.233,8);
	city(&(City[21]), "Menomonee Falls, WI",43.11,88.10,6);
	city(&(City[22]), "Miami, FL", 25.767, 80.183,5);
	city(&(City[23]), "Minneapolis, MN", 44.967, 93.25, 6);
	city(&(City[24]), "New Orleans, LA", 29.95, 90.067, 6);
	city(&(City[25]), "New York City, NY", 40.7167, 74.0167, 5);
	city(&(City[26]), "Oklahoma City, OK", 35.483, 97.533,6);
	city(&(City[27]), "Philadelphia, PA", 39.95, 75.15, 5);
	city(&(City[28]), "Phoenix, AZ",33.433,112.067,7);
	city(&(City[29]), "Pittsburgh, PA",40.433,79.9833,5);
	city(&(City[30]), "Portland, ME", 43.666, 70.283, 5);
	city(&(City[31]), "Portland, OR", 45.517, 122.65, 8);
	city(&(City[32]), "Raleigh, NC", 35.783, 78.65, 5);
	city(&(City[33]), "Richmond, VA", 37.5667, 77.450, 5);
	city(&(City[34]), "Saint Louis, MO", 38.6167,90.1833,6);
	city(&(City[35]), "San Antonio, TX", 29.53, 98.47, 6);
	city(&(City[36]), "San Diego, CA", 32.7667, 117.2167, 8);
	city(&(City[37]), "San Francisco, CA",37.7667,122.4167,8);
	city(&(City[38]), "Seattle, WA",47.60,122.3167,8);
	city(&(City[39]), "Washington DC", 38.8833, 77.0333,5);
	city(&(City[40]), "",0,0,0);
	city(&(City[41]), "WORLD CITIES",0,0,0);
	city(&(City[42]), "Beijing, China",39.9167, -116.4167,-8);
	city(&(City[43]), "Berlin, Germany",52.33, -13.30, -1);
	city(&(City[44]), "Bombay, India", 18.9333, -72.8333, -5.5);
	city(&(City[45]), "Buenos Aires, Argentina", -34.60,58.45,3);
	city(&(City[46]), "Cairo, Egypt", 30.10,-31.3667,-2);
	city(&(City[47]), "Cape Town, South Africa",-33.9167,-18.3667,-2);
	city(&(City[48]), "Caracas, Venezuela", 10.50,66.9333,4);
	city(&(City[49]), "Helsinki, Finland", 60.1667, -24.9667,-2);
	city(&(City[50]), "Hong Kong, China", 22.25,-114.1667, -8);
	city(&(City[51]), "Jerusalem, Israel", 31.7833, -35.2333, -2);
	city(&(City[52]), "London, England", 51.50, 0.1667,0);
	city(&(City[53]), "Mexico City, Mexico", 19.4,99.15,6);
	city(&(City[54]), "Moscow, Russia", 55.75, -37.5833, -3);
	city(&(City[55]), "New Delhi, India",28.6, -77.2, -5.5);
	city(&(City[56]), "Ottawa, Canada", 45.41667,75.7,5);
	city(&(City[57]), "Paris, France", 48.8667, -2.667, -1);
	city(&(City[58]), "Rio de Janeiro, Brazil",-22.90,43.2333,3);
	city(&(City[59]), "Riyadh, Saudi Arabia", 24.633, -46.71667, -3);
	city(&(City[60]), "Rome, Italy",41.90, -12.4833,-1);
	city(&(City[61]), "Sydney, Australia",-33.8667,-151.2167,-10);
	city(&(City[62]), "Tokyo, Japan", 35.70, -139.7667, -9); 
	city(&(City[63]), "Zurich, Switzerland", 47.3833, -8.5333,-1);
	city(&(City[64]), "",0,0,0);
	city(&(City[65]), "SURFRAD NETWORK",0,0,0);
	city(&(City[66]), "Goodwin Creek, MS",34.2544444,89.8738888, 6);
	city(&(City[67]), "Fort Peck, MT",48.310555,105.1025, 7);
	city(&(City[68]), "Bondville, IL",40.055277,88.371944, 6);
	city(&(City[69]), "Table Mountain, CO",40.125,105.23694, 7);
	city(&(City[70]), "Desert Rock, NV",36.626, 116.018, 8);
	city(&(City[71]), "Penn State, PA", 40.72, 77.93, 5);
	city(&(City[72]), "Canaan Valley, WV", 39.1, 79.4, 5);
	city(&(City[73]), "Sioux Falls, SD", 43.733, 96.6233, 6);
	city(&(City[74]), "",0,0,0);
	city(&(City[75]), "ARM/CART NETWORK",0,0,0);
	city(&(City[76]), "Atqasuk, AK", 70.47215, 157.4078, 9);
	city(&(City[77]), "Barrow, AK", 71.30,156.683, 9);
	city(&(City[78]), "Manus Island, PNG", -2.06, -147.425,-10);
	city(&(City[79]), "Nauru Island", -0.52, -166.92, -12);
	city(&(City[80]), "Darwin, Australia", -12.425, -130.891, -9.5);
	city(&(City[81]), "SGP Central Facility", 36.6167, 97.5, 6);
	city(&(City[82]), "",0,0,0);
	city(&(City[83]), "SOLRAD NETWORK",0,0,0);
	city(&(City[84]), "Albuquerque, NM", 35.04, 106.62,7);
	city(&(City[85]), "Bismarck, ND", 46.77, 100.77,6);
	city(&(City[86]), "Hanford, CA", 36.31, 119.63,8);
	city(&(City[87]), "Madison, WI", 43.13, 89.33,6);	
	city(&(City[88]), "Oak Ridge, TN", 35.96, 84.37,5);
	city(&(City[89]), "Salt Lake City, UT", 40.77,111.97,7);
	city(&(City[90]), "Seattle, WA", 47.68, 122.25,8);
	city(&(City[91]), "Sterling, VA", 38.98, 77.47,5);
	city(&(City[92]), "Tallahassee, FL", 30.38, 84.37,5);
	}
/*********************************************************************/

/*********************************************************************/

	typedef struct {
		double latDeg;
		double lonDeg;
		double latMin;
		double latSec;
		double lonMin;
		double lonSec;
		double hrsToGMT;
		unsigned int day;
		int year;
		size_t mos;
	} f_t;

	void setLatLong(city_t City[93], f_t *f, size_t index) ;
	void convLatLong(f_t *f) ;

	void setLatLong(city_t City[93], f_t *f, size_t index)
	{
		/* Decimal degrees are passed in the array.  Temporarily store these */
		/* degs in lat and lon deg and have convLatLong modify them.*/

		f->latDeg = City[index].lat;
		f->lonDeg = City[index].lng;
		f->latDeg = City[index].lat;
		f->lonDeg = City[index].lng;
	
		/* These are needed to prevent iterative adding of min and sec when */
		/* set button is clicked. */

		f->latMin = 0;
		f->latSec = 0;
		f->lonMin = 0;
		f->lonSec = 0;
		
		/*call convLatLong to convert decimal degrees into table form. */

		convLatLong(f);

		/*Local time zone value set in table */

		f->hrsToGMT =  City[index].zoneHr;
	}


/*********************************************************************/

/* isLeapYear returns 1 if the 4-digit yr is a leap year, 0 if it is not */

	bool isLeapYear(int yr) ;
	bool isLeapYear(int yr) 
	{
		return ((yr % 4 == 0 && yr % 100 != 0) || yr % 400 == 0);
	}


/**********************************************************************/

/* isPosInteger returns false if the value is not a positive integer, true is */
/* returned otherwise.  The code is from taken from Danny Goodman's Javascript */
/* Handbook, p. 372. */

	bool isPosInteger(int inputVal) ;

	bool isPosInteger(int inputVal) 
	{	return inputVal >=0;
		/*
		inputStr = ("" + inputVal);
		for (var i = 0; i < inputStr.length; i++) {
			var oneChar = inputStr.charAt(i);
			if (oneChar < "0" || oneChar > "9")
				return false;
		}
		return true;*/
	}

/*********************************************************************/

	bool isInteger(double inputVal) ;

	bool isInteger(double inputVal) 
	{	return !(floor(inputVal) < ceil(inputVal));
		/*inputStr = "" + inputVal;
		if(inputStr == "NaN") return false;
		if(inputStr == "-NaN") return false;
		for (var i = 0; i < inputStr.length; i++) 
		{
			var oneChar = inputStr.charAt(i);
			if (i == 0 && (oneChar == "-" || oneChar == "+"))
			{
				continue;
			}
			if (oneChar < "0" || oneChar > "9")
			{
				return false;
			}
		}
		return true;*/
	}


/**********************************************************************/


	/*bool isNumber(char const *inputStr) */
	/*bool isNumber(char const *s) */
	bool isNumber (double s)
	{
		return (! isnan(s) && !isinf(s));
    /*char * p;
		if (s == NULL || *s == '\0' || isspace(*s))
      return false;
    strtod (s, &p);
    return *p == '\0';*/
		/* bool oneDecimal = false;*/
		/*var inputStr = "" + inputVal;*/
		/*size_t i;
		for (i = 0; i < inputStr.length; i++) 
		{
			var oneChar = inputStr.charAt(i);
			if (i == 0 && (oneChar == "-" || oneChar == "+"))
			{
				continue;
			}
			if (oneChar == "." && !oneDecimal) 
			{
				oneDecimal = true;
				continue;
			}
			if (oneChar < "0" || oneChar > "9")
			{
				return false;
			}
		}
		return true;*/
	}


/**********************************************************************/

/* isValidInput makes sure valid input is entered before going ahead to */
/* calculate the sunrise and sunset.  False is returned if an invalid entry */
/* was made, true is the entry is valid.*/

	bool isValidInput(month_t monthList[12], f_t *f, size_t index/*, latLongForm*/) ;

	void alert (char const *str) ;
	void alert (char const *str) { fputs (str, stderr); }

	bool isValidInput(month_t monthList[12], f_t *f, size_t index/*, latLongForm*/) 
	{
		/*if (f->day == "") 
		{*/	/*	see if the day field is empty*/
			/*alert("You must enter a day before attempting the calculation.");
			return false;
		}
		else if (f->year == "") 
		{*/	/*	 see if the year field is empty*/
			/*alert("You must enter a year before attempting the calculation.");
			return false;
		}
		else*/ /*if (!isPosInteger(f->day)*/ /* || f->day.value == 0*/ /*)
		{
			alert("The day must be a positive integer.");
			return false;
		}
		else*/ if (!isInteger(f->year)) 
		{
			alert("The year must be an integer.");
			return false;
		}
		else if ( (f->year < -1000) || (f->year > 3000) )
		{
			alert("The algorithm used is not valid for years outside of/nthe range -1000 to 3000.");
			return false;
		}


		/*	For the non-February months see if the day entered is greater than*/
		/*	the number of days in the selected month*/

		else if ((index != 1) && (f->day > monthList[index].numdays)) 
		{
			/*alert("There are only " + monthList[index].numdays + " days in " 
				+ monthList[index].name + ".");*/
			return false;
		}

		/*	First see if the year entered is a leap year.  If so we have to make sure*/
		/*	the days entered is <= 29.  If not a leap year we make sure that the days*/
		/*	entered is <= 28.*/

		else if (index == 1) 
		{	/*	 month selected is February the screwball month*/
			if (isLeapYear(f->year)) {	/*	year entered is a leap year*/
				if (f->day > (monthList[index].numdays + 1)) 
				{
					/*alert("There are only " + (monthList[index].numdays + 1) 
						+ " days in " + monthList[index].name + ".");*/
					return false;
				}
				else
					return true;
			}
			else 
			{	/*	year entered is not a leap year*/
				if (f->day > monthList[index].numdays) 
				{
					/*alert("There are only " + monthList[index].numdays 
						+ " days in " + monthList[index].name + ".");*/
					return false;
				}
				else
					return true;
			}
		}
		else 
			return true;	
	}

/**********************************************************************/

/*convLatLong converts any type of lat/long input */
/*into  the table form and then handles bad input */
/*it is nested in the calcSun function. */

	void convLatLong(f_t *f)
	{
		bool neg;
		double latSeconds;
		double lonSeconds;
		/*if(f->latDeg == "")
		{
			f->latDeg = 0;
		}
		if(f->latMin == "")
		{
			f->latMin = 0;
		}
		if(f->latSec == "")
		{
			f->latSec = 0;
		}
		if(f->lonDeg == "")
		{
			f->lonDeg = 0;
		}
		if(f->lonMin == "")
		{
			f->lonMin = 0;
		}
		if(f->lonSec == "")
		{
			f->lonSec = 0;
		}

		var neg = false;
		if(f->latDeg.charAt(0) == '-') 
		{
			neg = true;
		}

		if(neg != 1)*/
		if(f->latDeg >= 0)
		{
			latSeconds = ( (f->latDeg))*3600 
				+ (f->latMin)*60 
				+ (f->latSec)*1;

			f->latDeg = floor(latSeconds/3600);
			f->latMin = floor((latSeconds
				- ( (f->latDeg)*3600))/60);
			f->latSec = floor((latSeconds
				- ( (f->latDeg)*3600) 
				- ( (f->latMin)*60)) + 0.5);
		}
		else if( (f->latDeg) > -1)
		{
			latSeconds = (f->latDeg)*3600 
				- (f->latMin)*60 
				- (f->latSec)*1;

			f->latDeg = -0;
			f->latMin = floor((-latSeconds)/60);
			f->latSec = floor( (-latSeconds 
				- ( (f->latMin)*60)) + 0.5);

		}
		else
		{
			latSeconds = (f->latDeg)*3600 
				- (f->latMin)*60 
				- (f->latSec)*1;

			f->latDeg = ceil(latSeconds/3600);
			f->latMin = floor((-latSeconds
				+ ( (f->latDeg)*3600))/60);
			f->latSec = floor((-latSeconds
				+ ( (f->latDeg)*3600) 
				- ( (f->latMin)*60)) + 0.5);
		}

		neg = false;
		if(f->lonDeg < 0)
		{
			neg = true;
		}

		if(!neg)
		{
			lonSeconds = (f->lonDeg)*3600 
				+ (f->lonMin)*60 
				+ (f->lonSec)*1;
			f->lonDeg = floor(lonSeconds/3600);
			f->lonMin = floor((lonSeconds
				- ( (f->lonDeg)*3600))/60);
			f->lonSec = floor((lonSeconds
				- ( (f->lonDeg)*3600)
				- ( (f->lonMin))*60) + 0.5);
		}
		else if( (f->lonDeg) > -1)
		{
			lonSeconds = (f->lonDeg)*3600 
				- (f->lonMin)*60 
				- (f->lonSec)*1;

			f->lonDeg = -0;
			f->lonMin = floor((-lonSeconds)/60);
			f->lonSec = floor((-lonSeconds
				- ( (f->lonMin)*60)) + 0.5);
		}
		else
		{
			lonSeconds = (f->lonDeg)*3600 
				- (f->lonMin)*60 
				- (f->lonSec)*1;
			f->lonDeg = ceil(lonSeconds/3600);
			f->lonMin = floor((-lonSeconds
				+ ( (f->lonDeg)*3600))/60);
			f->lonSec = floor((-lonSeconds
				+ ( (f->lonDeg)*3600)
				- ( (f->lonMin)*60)) + 0.5);
		}

		/*Test for invalid lat/long input*/

		if(latSeconds > 324000)
		{
			alert("You have entered an invalid latitude.\n  Setting lat = 89.");
			f->latDeg = 89;
			f->latMin = 0;
			f->latSec = 0;
		}
		if(latSeconds < -324000)
		{
			alert("You have entered an invalid latitude.\n  Setting lat = -89.");
			f->latDeg = -89;
			f->latMin = 0;
			f->latSec = 0;
		}
		if(lonSeconds > 648000)
		{
			alert("You have entered an invalid longitude.\n Setting lon = 180.");
			f->lonDeg = 180;
			f->lonMin = 0;
			f->lonSec = 0;
		}
		if(lonSeconds < -648000)
		{
			alert("You have entered an invalid longitude.\n Setting lon = -180.");
			f->lonDeg = -180;
			f->lonMin = 0;
			f->lonSec =0;
		}

	}



/***********************************************************************/
/***********************************************************************/
/*												*/
/*This section contains subroutines used in calculating solar position */
/*												*/
/***********************************************************************/
/***********************************************************************/

/* Convert radian angle to degrees*/

	double radToDeg(double angleRad) ;

	double radToDeg(double angleRad) 
	{
		return (180.0 * angleRad / M_PI);
	}

/**********************************************************************/

/* Convert degree angle to radians */

	double degToRad(double angleDeg) ;

	double degToRad(double angleDeg) 
	{
		return (M_PI * angleDeg / 180.0);
	}

/**********************************************************************/


/************************************************************************/
/* Name:    calcDayOfYear								*/
/* Type:    Function									*/
/* Purpose: Finds numerical day-of-year from mn, day and lp year info  */
/* Arguments:										*/
/*   month: January = 1								*/
/*   day  : 1 - 31									*/
/*   lpyr : 1 if leap year, 0 if not						*/
/* Return value:										*/
/*   The numerical day of year							*/
/***********************************************************************/

	unsigned int calcDayOfYear(size_t mn, unsigned int dy, unsigned int lpyr) ;

	unsigned int calcDayOfYear(size_t mn, unsigned int dy, unsigned int lpyr) 
	{
		unsigned int k = (lpyr ? 1 : 2);
		unsigned int doy = (unsigned int) (floor((275 * (double) mn)/9.0) - k * floor(((double)mn + 9)/12.0) + dy -30);
		return doy;
	}


/***********************************************************************/
/* Name:    calcDayOfWeek								*/
/* Type:    Function									*/
/* Purpose: Derives weekday from Julian Day					*/
/* Arguments:										*/
/*   juld : Julian Day									*/
/* Return value:										*/
/*   String containing name of weekday						*/
/***********************************************************************/

	char const * calcDayOfWeek(double juld) ;

	char const * calcDayOfWeek(double juld)
	{
		unsigned int A = (unsigned int)(juld + 1.5) % 7;
		char const * DOW = (A==0)?"Sunday":(A==1)?"Monday":(A==2)?"Tuesday":(A==3)?"Wednesday":(A==4)?"Thursday":(A==5)?"Friday":"Saturday";
		return DOW;
	}


/***********************************************************************/
/* Name:    calcJD									*/
/* Type:    Function									*/
/* Purpose: Julian day from calendar day						*/
/* Arguments:										*/
/*   year : 4 digit year								*/
/*   month: January = 1								*/
/*   day  : 1 - 31									*/
/* Return value:										*/
/*   The Julian day corresponding to the date					*/
/* Note:											*/
/*   Number is returned for start of day.  Fractional days should be	*/
/*   added later.									*/
/***********************************************************************/

	int calcJD(int year, size_t month, unsigned int day) ;

	int calcJD(int year, size_t month, unsigned int day)
	{
		int A, B, JD;
		if (month <= 2) {
			year -= 1;
			month += 12;
		}
		A = (int) (floor(year/100.0) + 0.0);
		B = 2 - A + (int) (floor(A/4.0) + 0.0);

		JD = (int) (floor(365.25*(year + 4716)) + floor(30.6001*(double)(month+1)) + day + B - 1524.5);
		return JD;
	}



/***********************************************************************/
/* Name:    calcDateFromJD								*/
/* Type:    Function									*/
/* Purpose: Calendar date from Julian Day					*/
/* Arguments:										*/
/*   jd   : Julian Day									*/
/* Return value:										*/
/*   String date in the form DD-MONTHNAME-YYYY					*/
/* Note:											*/
/***********************************************************************/
/*
	void calcDateFromJD(char dest[17], month_t monthList[12], double jd) ;

	void calcDateFromJD(char dest[17], month_t monthList[12], double jd)
	{
		double z = floor(jd + 0.5);
		double f = (jd + 0.5) - z;
		double A, B, C, D, E;
		double day, month, year;

		if (z < 2299161) {
			A = z;
		} else {
			alpha = floor((z - 1867216.25)/36524.25);
			A = z + 1 + alpha - floor(alpha/4);
		}

		B = A + 1524;
		C = floor((B - 122.1)/365.25);
		D = floor(365.25 * C);
		E = floor((B - D)/30.6001);

		day = B - D - floor(30.6001 * E) + f;
		month = (E < 14) ? E - 1 : E - 13;
		year = (month > 2) ? C - 4716 : C - 4715;

		/ * alert ("date: " + day + "-" + monthList[month-1].name + "-" + year);* /
		/ *return (day + "-" + monthList[month-1].name + "-" + year);* /
		snprintf(dest, (size_t) 17, "%02d-%8s-%4s", (int) day, monthList[(int) month - 1].name, (int) year);
	}
*/

/***********************************************************************/
/* Name:    calcDayFromJD								*/
/* Type:    Function									*/
/* Purpose: Calendar day (minus year) from Julian Day			*/
/* Arguments:										*/
/*   jd   : Julian Day									*/
/* Return value:										*/
/*   String date in the form DD-MONTH						*/
/***********************************************************************/

	void calcDayFromJD(char dest[6], month_t monthList[12], double jd) ;

	void calcDayFromJD(char dest[6], month_t monthList[12], double jd)
	{
		double z = floor(jd + 0.5);
		double f = (jd + 0.5) - z;
		double A, B, C, D, E;
		double day, month;

		if (z < 2299161) {
			A = z;
		} else {
			double alpha = floor((z - 1867216.25)/36524.25);
			A = z + 1 + alpha - floor(alpha/4.0);
		}

		B = A + 1524.0;
		C = floor((B - 122.1)/365.25);
		D = floor(365.25 * C);
		E = floor((B - D)/30.6001);

		day = B - D - floor(30.6001 * E) + f;
		month = (E < 14) ? E - 1 : E - 13;
		/*double year = (month > 2) ? C - 4716 : C - 4715;*/

		/*return ((day<10 ? "0" : "") + day + monthList[month-1].abbr);*/
		snprintf(dest, 6, "%02d-%3s", (int) day, monthList[(int)month - 1].abbr);
	}


/***********************************************************************/
/* Name:    calcTimeJulianCent							*/
/* Type:    Function									*/
/* Purpose: convert Julian Day to centuries since J2000.0.			*/
/* Arguments:										*/
/*   jd : the Julian Day to convert						*/
/* Return value:										*/
/*   the T value corresponding to the Julian Day				*/
/***********************************************************************/

	double calcTimeJulianCent(double jd) ;

	double calcTimeJulianCent(double jd)
	{
		double T = (jd - 2451545.0)/36525.0;
		return T;
	}


/***********************************************************************/
/* Name:    calcJDFromJulianCent							*/
/* Type:    Function									*/
/* Purpose: convert centuries since J2000.0 to Julian Day.			*/
/* Arguments:										*/
/*   t : number of Julian centuries since J2000.0				*/
/* Return value:										*/
/*   the Julian Day corresponding to the t value				*/
/***********************************************************************/

	double calcJDFromJulianCent(double t) ;

	double calcJDFromJulianCent(double t)
	{
		double JD = t * 36525.0 + 2451545.0;
		return JD;
	}


/***********************************************************************/
/* Name:    calGeomMeanLongSun							*/
/* Type:    Function									*/
/* Purpose: calculate the Geometric Mean Longitude of the Sun		*/
/* Arguments:										*/
/*   t : number of Julian centuries since J2000.0				*/
/* Return value:										*/
/*   the Geometric Mean Longitude of the Sun in degrees			*/
/***********************************************************************/

	double calcGeomMeanLongSun(double t) ;

	double calcGeomMeanLongSun(double t)
	{
		double L0 = 280.46646 + t * (36000.76983 + 0.0003032 * t);
		while(L0 > 360.0)
		{
			L0 -= 360.0;
		}
		while(L0 < 0.0)
		{
			L0 += 360.0;
		}
		return L0;		/* in degrees*/
	}


/***********************************************************************/
/* Name:    calGeomAnomalySun							*/
/* Type:    Function									*/
/* Purpose: calculate the Geometric Mean Anomaly of the Sun		*/
/* Arguments:										*/
/*   t : number of Julian centuries since J2000.0				*/
/* Return value:										*/
/*   the Geometric Mean Anomaly of the Sun in degrees			*/
/***********************************************************************/

	double calcGeomMeanAnomalySun(double t) ;

	double calcGeomMeanAnomalySun(double t)
	{
		double M = 357.52911 + t * (35999.05029 - 0.0001537 * t);
		return M;		/* in degrees*/
	}

/***********************************************************************/
/* Name:    calcEccentricityEarthOrbit						*/
/* Type:    Function									*/
/* Purpose: calculate the eccentricity of earth's orbit			*/
/* Arguments:										*/
/*   t : number of Julian centuries since J2000.0				*/
/* Return value:										*/
/*   the unitless eccentricity							*/
/***********************************************************************/


	double calcEccentricityEarthOrbit(double t) ;

	double calcEccentricityEarthOrbit(double t)
	{
		double e = 0.016708634 - t * (0.000042037 + 0.0000001267 * t);
		return e;		/* unitless*/
	}

/***********************************************************************/
/* Name:    calcSunEqOfCenter							*/
/* Type:    Function									*/
/* Purpose: calculate the equation of center for the sun			*/
/* Arguments:										*/
/*   t : number of Julian centuries since J2000.0				*/
/* Return value:										*/
/*   in degrees										*/
/***********************************************************************/


	double calcSunEqOfCenter(double t) ;

	double calcSunEqOfCenter(double t)
	{
		double m = calcGeomMeanAnomalySun(t);

		double mrad = degToRad(m);
		double sinm = sin(mrad);
		double sin2m = sin(mrad+mrad);
		double sin3m = sin(mrad+mrad+mrad);

		double C = sinm * (1.914602 - t * (0.004817 + 0.000014 * t)) + sin2m * (0.019993 - 0.000101 * t) + sin3m * 0.000289;
		return C;		/* in degrees*/
	}

/***********************************************************************/
/* Name:    calcSunTrueLong								*/
/* Type:    Function									*/
/* Purpose: calculate the true longitude of the sun				*/
/* Arguments:										*/
/*   t : number of Julian centuries since J2000.0				*/
/* Return value:										*/
/*   sun's true longitude in degrees						*/
/***********************************************************************/


	double calcSunTrueLong(double t) ;

	double calcSunTrueLong(double t)
	{
		double l0 = calcGeomMeanLongSun(t);
		double c = calcSunEqOfCenter(t);

		double O = l0 + c;
		return O;		/* in degrees*/
	}

/***********************************************************************/
/* Name:    calcSunTrueAnomaly							*/
/* Type:    Function									*/
/* Purpose: calculate the true anamoly of the sun				*/
/* Arguments:										*/
/*   t : number of Julian centuries since J2000.0				*/
/* Return value:										*/
/*   sun's true anamoly in degrees							*/
/***********************************************************************/

	double calcSunTrueAnomaly(double t) ;

	double calcSunTrueAnomaly(double t)
	{
		double m = calcGeomMeanAnomalySun(t);
		double c = calcSunEqOfCenter(t);

		double v = m + c;
		return v;		/* in degrees*/
	}

/***********************************************************************/
/* Name:    calcSunRadVector								*/
/* Type:    Function									*/
/* Purpose: calculate the distance to the sun in AU				*/
/* Arguments:										*/
/*   t : number of Julian centuries since J2000.0				*/
/* Return value:										*/
/*   sun radius vector in AUs							*/
/***********************************************************************/

	double calcSunRadVector(double t) ;

	double calcSunRadVector(double t)
	{
		double v = calcSunTrueAnomaly(t);
		double e = calcEccentricityEarthOrbit(t);
 
		double R = (1.000001018 * (1 - e * e)) / (1 + e * cos(degToRad(v)));
		return R;		/* in AUs*/
	}

/***********************************************************************/
/* Name:    calcSunApparentLong							*/
/* Type:    Function									*/
/* Purpose: calculate the apparent longitude of the sun			*/
/* Arguments:										*/
/*   t : number of Julian centuries since J2000.0				*/
/* Return value:										*/
/*   sun's apparent longitude in degrees						*/
/***********************************************************************/

	double calcSunApparentLong(double t) ;

	double calcSunApparentLong(double t)
	{
		double o = calcSunTrueLong(t);

		double omega = 125.04 - 1934.136 * t;
		double lambda = o - 0.00569 - 0.00478 * sin(degToRad(omega));
		return lambda;		/* in degrees*/
	}

/***********************************************************************/
/* Name:    calcMeanObliquityOfEcliptic						*/
/* Type:    Function									*/
/* Purpose: calculate the mean obliquity of the ecliptic			*/
/* Arguments:										*/
/*   t : number of Julian centuries since J2000.0				*/
/* Return value:										*/
/*   mean obliquity in degrees							*/
/***********************************************************************/

	double calcMeanObliquityOfEcliptic(double t) ;

	double calcMeanObliquityOfEcliptic(double t)
	{
		double seconds = 21.448 - t*(46.8150 + t*(0.00059 - t*(0.001813)));
		double e0 = 23.0 + (26.0 + (seconds/60.0))/60.0;
		return e0;		/* in degrees*/
	}

/***********************************************************************/
/* Name:    calcObliquityCorrection						*/
/* Type:    Function									*/
/* Purpose: calculate the corrected obliquity of the ecliptic		*/
/* Arguments:										*/
/*   t : number of Julian centuries since J2000.0				*/
/* Return value:										*/
/*   corrected obliquity in degrees						*/
/***********************************************************************/

	double calcObliquityCorrection(double t) ;

	double calcObliquityCorrection(double t)
	{
		double e0 = calcMeanObliquityOfEcliptic(t);

		double omega = 125.04 - 1934.136 * t;
		double e = e0 + 0.00256 * cos(degToRad(omega));
		return e;		/* in degrees*/
	}

/***********************************************************************/
/* Name:    calcSunRtAscension							*/
/* Type:    Function									*/
/* Purpose: calculate the right ascension of the sun				*/
/* Arguments:										*/
/*   t : number of Julian centuries since J2000.0				*/
/* Return value:										*/
/*   sun's right ascension in degrees						*/
/***********************************************************************/

	double calcSunRtAscension(double t) ;

	double calcSunRtAscension(double t)
	{
		double e = calcObliquityCorrection(t);
		double lambda = calcSunApparentLong(t);
 
		double tananum = ( cos(degToRad(e)) * sin(degToRad(lambda)));
		double tanadenom = ( cos(degToRad(lambda)));
		double alpha = radToDeg( atan2(tananum, tanadenom));
		return alpha;		/* in degrees*/
	}

/***********************************************************************/
/* Name:    calcSunDeclination							*/
/* Type:    Function									*/
/* Purpose: calculate the declination of the sun				*/
/* Arguments:										*/
/*   t : number of Julian centuries since J2000.0				*/
/* Return value:										*/
/*   sun's declination in degrees							*/
/***********************************************************************/

	double calcSunDeclination(double t) ;

	double calcSunDeclination(double t)
	{
		double e = calcObliquityCorrection(t);
		double lambda = calcSunApparentLong(t);

		double sint = sin(degToRad(e)) * sin(degToRad(lambda));
		double theta = radToDeg( asin(sint));
		return theta;		/* in degrees*/
	}

/***********************************************************************/
/* Name:    calcEquationOfTime							*/
/* Type:    Function									*/
/* Purpose: calculate the difference between true solar time and mean	*/
/*		solar time									*/
/* Arguments:										*/
/*   t : number of Julian centuries since J2000.0				*/
/* Return value:										*/
/*   equation of time in minutes of time						*/
/***********************************************************************/

	double calcEquationOfTime(double t) ;

	double calcEquationOfTime(double t)
	{
		double epsilon = calcObliquityCorrection(t);
		double l0 = calcGeomMeanLongSun(t);
		double e = calcEccentricityEarthOrbit(t);
		double m = calcGeomMeanAnomalySun(t);

		double y = tan(degToRad(epsilon)/2.0);

		double sin2l0 = sin(2.0 * degToRad(l0));
		double sinm   = sin(degToRad(m));
		double cos2l0 = cos(2.0 * degToRad(l0));
		double sin4l0 = sin(4.0 * degToRad(l0));
		double sin2m  = sin(2.0 * degToRad(m));

		double Etime;

		y *= y;

		Etime = y * sin2l0 - 2.0 * e * sinm + 4.0 * e * y * sinm * cos2l0
				- 0.5 * y * y * sin4l0 - 1.25 * e * e * sin2m;

		return radToDeg(Etime)*4.0;	/* in minutes of time*/
	}

/***********************************************************************/
/* Name:    calcHourAngleSunrise							*/
/* Type:    Function									*/
/* Purpose: calculate the hour angle of the sun at sunrise for the	*/
/*			latitude								*/
/* Arguments:										*/
/*   lat : latitude of observer in degrees					*/
/*	solarDec : declination angle of sun in degrees				*/
/* Return value:										*/
/*   hour angle of sunrise in radians						*/
/***********************************************************************/

	double calcHourAngleSunrise(double lat, double solarDec) ;

	double calcHourAngleSunrise(double lat, double solarDec)
	{
		double latRad = degToRad(lat);
		double sdRad  = degToRad(solarDec);

		double HAarg = (cos(degToRad(90.833))/(cos(latRad)*cos(sdRad))-tan(latRad) * tan(sdRad));

		double HA = (acos(cos(degToRad(90.833))/(cos(latRad)*cos(sdRad))-tan(latRad) * tan(sdRad)));

		return HA;		/* in radians*/
	}

/***********************************************************************/
/* Name:    calcHourAngleSunset							*/
/* Type:    Function									*/
/* Purpose: calculate the hour angle of the sun at sunset for the	*/
/*			latitude								*/
/* Arguments:										*/
/*   lat : latitude of observer in degrees					*/
/*	solarDec : declination angle of sun in degrees				*/
/* Return value:										*/
/*   hour angle of sunset in radians						*/
/***********************************************************************/

	double calcHourAngleSunset(double lat, double solarDec) ;

	double calcHourAngleSunset(double lat, double solarDec)
	{
		double latRad = degToRad(lat);
		double sdRad  = degToRad(solarDec);

		double HAarg = (cos(degToRad(90.833))/(cos(latRad)*cos(sdRad))-tan(latRad) * tan(sdRad));

		double HA = (acos(cos(degToRad(90.833))/(cos(latRad)*cos(sdRad))-tan(latRad) * tan(sdRad)));

		return -HA;		/* in radians*/
	}


/***********************************************************************/
/* Name:    calcSunriseUTC								*/
/* Type:    Function									*/
/* Purpose: calculate the Universal Coordinated Time (UTC) of sunrise	*/
/*			for the given day at the given location on earth	*/
/* Arguments:										*/
/*   JD  : julian day									*/
/*   latitude : latitude of observer in degrees				*/
/*   longitude : longitude of observer in degrees				*/
/* Return value:										*/
/*   time in minutes from zero Z							*/
/***********************************************************************/
	double calcSolNoonUTC(double t, double longitude);

	double calcSunriseUTC(double JD, double latitude, double longitude) ;

	double calcSunriseUTC(double JD, double latitude, double longitude)
	{
		double t = calcTimeJulianCent(JD);

		/* *** Find the time of solar noon at the location, and use*/
        /*     that declination. This is better than start of the */
        /*     Julian day*/

		double noonmin = calcSolNoonUTC(t, longitude);
		double tnoon = calcTimeJulianCent (JD+noonmin/1440.0);

		/* *** First pass to approximate sunrise (using solar noon)*/

		double eqTime = calcEquationOfTime(tnoon);
		double solarDec = calcSunDeclination(tnoon);
		double hourAngle = calcHourAngleSunrise(latitude, solarDec);

		double delta = longitude - radToDeg(hourAngle);
		double timeDiff = 4 * delta;	/* in minutes of time*/
		double timeUTC = 720 + timeDiff - eqTime;	/* in minutes*/

		/* alert("eqTime = " + eqTime + "\nsolarDec = " + solarDec + "\ntimeUTC = " + timeUTC);*/

		/* *** Second pass includes fractional jday in gamma calc*/

		double newt = calcTimeJulianCent(calcJDFromJulianCent(t) + timeUTC/1440.0); 
		eqTime = calcEquationOfTime(newt);
		solarDec = calcSunDeclination(newt);
		hourAngle = calcHourAngleSunrise(latitude, solarDec);
		delta = longitude - radToDeg(hourAngle);
		timeDiff = 4 * delta;
		timeUTC = 720 + timeDiff - eqTime; /* in minutes*/

		/* alert("eqTime = " + eqTime + "\nsolarDec = " + solarDec + "\ntimeUTC = " + timeUTC);*/

		return timeUTC;
	}

/***********************************************************************/
/* Name:    calcSolNoonUTC								*/
/* Type:    Function									*/
/* Purpose: calculate the Universal Coordinated Time (UTC) of solar	*/
/*		noon for the given day at the given location on earth		*/
/* Arguments:										*/
/*   t : number of Julian centuries since J2000.0				*/
/*   longitude : longitude of observer in degrees				*/
/* Return value:										*/
/*   time in minutes from zero Z							*/
/***********************************************************************/

	double calcSolNoonUTC(double t, double longitude)
	{
		/* First pass uses approximate solar noon to calculate eqtime*/
		double tnoon = calcTimeJulianCent(calcJDFromJulianCent(t) + longitude/360.0);
		double eqTime = calcEquationOfTime(tnoon);
		double solNoonUTC = 720 + (longitude * 4) - eqTime; /* min*/

		double newt = calcTimeJulianCent(calcJDFromJulianCent(t) -0.5 + solNoonUTC/1440.0); 

		eqTime = calcEquationOfTime(newt);
		/* var solarNoonDec = calcSunDeclination(newt);*/
		solNoonUTC = 720 + (longitude * 4) - eqTime; /* min*/
		
		return solNoonUTC;
	}

/***********************************************************************/
/* Name:    calcSunsetUTC								*/
/* Type:    Function									*/
/* Purpose: calculate the Universal Coordinated Time (UTC) of sunset	*/
/*			for the given day at the given location on earth	*/
/* Arguments:										*/
/*   JD  : julian day									*/
/*   latitude : latitude of observer in degrees				*/
/*   longitude : longitude of observer in degrees				*/
/* Return value:										*/
/*   time in minutes from zero Z							*/
/***********************************************************************/

	double calcSunsetUTC(double JD, double latitude, double longitude) ;

	double calcSunsetUTC(double JD, double latitude, double longitude)
	{
		double t = calcTimeJulianCent(JD);

		/* *** Find the time of solar noon at the location, and use*/
        /*     that declination. This is better than start of the */
        /*     Julian day*/

		double noonmin = calcSolNoonUTC(t, longitude);
		double tnoon = calcTimeJulianCent (JD+noonmin/1440.0);

		/* First calculates sunrise and approx length of day*/

		double eqTime = calcEquationOfTime(tnoon);
		double solarDec = calcSunDeclination(tnoon);
		double hourAngle = calcHourAngleSunset(latitude, solarDec);

		double delta = longitude - radToDeg(hourAngle);
		double timeDiff = 4 * delta;
		double timeUTC = 720 + timeDiff - eqTime;

		/* first pass used to include fractional day in gamma calc*/

		double newt = calcTimeJulianCent(calcJDFromJulianCent(t) + timeUTC/1440.0); 
		eqTime = calcEquationOfTime(newt);
		solarDec = calcSunDeclination(newt);
		hourAngle = calcHourAngleSunset(latitude, solarDec);

		delta = longitude - radToDeg(hourAngle);
		timeDiff = 4 * delta;
		timeUTC = 720 + timeDiff - eqTime; /* in minutes*/

		return timeUTC;
	}


/*********************************************************************/

/* Returns the decimal latitude from the degrees, minutes and seconds entered */
/* into the form	*/

	double getLatitude(f_t * latLongForm) ;

	double getLatitude(f_t * latLongForm)
	{
		bool neg = 0;
		double strLatDeg = latLongForm->latDeg;
		double degs = (latLongForm->latDeg);
		double mins, secs, decLat;
		if (latLongForm->latDeg < 0) 
		{
			neg = true;
		}

		if ((int) (floor(strLatDeg) + 0.0) == (int) (ceil(strLatDeg) + 0.0))
		{
			latLongForm->latMin = 0;
			latLongForm->latSec = 0;
		}

		/*if(latLongForm["latMin"].value == "")
		{
			latLongForm["latMin"].value = 0;
		}
		if(latLongForm["latSec"].value == "")
		{
			latLongForm["latSec"].value = 0;
		}*/

		mins = (latLongForm->latMin);

		secs = (latLongForm->latSec);

		if(!neg)
		{
			decLat = degs + (mins / 60) + (secs / 3600);
		} else if(neg == 1)
		{
			decLat = degs - (mins / 60) - (secs / 3600);
		} else 
		{
			return -9999;
		}
		return decLat;
	}	


/*********************************************************************/

/* Returns the decimal longitude from the degrees, minutes and seconds entered */
/* into the form	*/

	double getLongitude(f_t * latLongForm) ;

	double getLongitude(f_t * latLongForm)
	{
		bool neg = 0;
		double strLonDeg = latLongForm->lonDeg;
		double degs = (latLongForm->lonDeg);
		double mins, secs, decLon;
		if (latLongForm->lonDeg < 0)
		{
			neg = 1;
		}

		if ((int) (floor(strLonDeg) + 0.0) == (int) (ceil(strLonDeg) + 0.0))
		{
			latLongForm->lonMin = 0;
			latLongForm->lonSec = 0;
		}

		/*if(latLongForm->lonMin"].value == "")
		{
			latLongForm->lonMin"].value = 0;
		}
		if(latLongForm->lonSec"].value == "")
		{
			latLongForm->lonSec"].value = 0;
		}*/

		mins = (latLongForm->lonMin);
		secs = (latLongForm->lonSec);
		decLon = degs + (mins / 60) + (secs / 3600);

		if(!neg)
		{
			decLon = degs + (mins / 60) + (secs / 3600);
		} else if(neg)
		{
			decLon = degs - (mins / 60) - (secs / 3600);
		} else 
		{
			return -9999;
		}
		return decLon;
	}	


/***********************************************************************/
/* Name:    findRecentSunrise							*/
/* Type:    Function									*/
/* Purpose: calculate the julian day of the most recent sunrise		*/
/*		starting from the given day at the given location on earth	*/
/* Arguments:										*/
/*   JD  : julian day									*/
/*   latitude : latitude of observer in degrees				*/
/*   longitude : longitude of observer in degrees				*/
/* Return value:										*/
/*   julian day of the most recent sunrise					*/
/***********************************************************************/

	double findRecentSunrise(double jd, double latitude, double longitude) ;

	double findRecentSunrise(double jd, double latitude, double longitude)
	{
		double julianday = jd;

		double time = calcSunriseUTC(julianday, latitude, longitude);
		/*while(!isNumber(time))*/
		while (isinf (time) || isnan(time)){
			julianday -= 1.0;
			time = calcSunriseUTC(julianday, latitude, longitude);
		}

		return julianday;
	}


/***********************************************************************/
/* Name:    findRecentSunset								*/
/* Type:    Function									*/
/* Purpose: calculate the julian day of the most recent sunset		*/
/*		starting from the given day at the given location on earth	*/
/* Arguments:										*/
/*   JD  : julian day									*/
/*   latitude : latitude of observer in degrees				*/
/*   longitude : longitude of observer in degrees				*/
/* Return value:										*/
/*   julian day of the most recent sunset					*/
/***********************************************************************/

	double findRecentSunset(double jd, double latitude, double longitude) ;

	double findRecentSunset(double jd, double latitude, double longitude)
	{
		double julianday = jd;

		double time = calcSunsetUTC(julianday, latitude, longitude);
		/*while(!isNumber(time))*/
		while (isnan(time) || isinf(time)){
			julianday -= 1.0;
			time = calcSunsetUTC(julianday, latitude, longitude);
		}

		return julianday;
	}


/***********************************************************************/
/* Name:    findNextSunrise								*/
/* Type:    Function									*/
/* Purpose: calculate the julian day of the next sunrise			*/
/*		starting from the given day at the given location on earth	*/
/* Arguments:										*/
/*   JD  : julian day									*/
/*   latitude : latitude of observer in degrees				*/
/*   longitude : longitude of observer in degrees				*/
/* Return value:										*/
/*   julian day of the next sunrise						*/
/***********************************************************************/

	double findNextSunrise(double jd, double latitude, double longitude) ;

	double findNextSunrise(double jd, double latitude, double longitude)
	{
		double julianday = jd;

		double time = calcSunriseUTC(julianday, latitude, longitude);
		/*while(!isNumber(time))*/
		while(isnan(time) || isinf(time)){
			julianday += 1.0;
			time = calcSunriseUTC(julianday, latitude, longitude);
		}

		return julianday;
	}


/***********************************************************************/
/* Name:    findNextSunset								*/
/* Type:    Function									*/
/* Purpose: calculate the julian day of the next sunset			*/
/*		starting from the given day at the given location on earth	*/
/* Arguments:										*/
/*   JD  : julian day									*/
/*   latitude : latitude of observer in degrees				*/
/*   longitude : longitude of observer in degrees				*/
/* Return value:										*/
/*   julian day of the next sunset							*/
/***********************************************************************/

	double findNextSunset(double jd, double latitude, double longitude) ;

	double findNextSunset(double jd, double latitude, double longitude)
	{
		double julianday = jd;

		double time = calcSunsetUTC(julianday, latitude, longitude);
		/*while(!isNumber(time))*/
		while (isnan(time) || isinf(time)){
			julianday += 1.0;
			time = calcSunsetUTC(julianday, latitude, longitude);
		}

		return julianday;
	}

/***********************************************************************/
/* Name:    timeString									*/
/* Type:    Function									*/
/* Purpose: convert time of day in minutes to a zero-padded string	*/
/*		suitable for printing to the form text fields			*/
/* Arguments:										*/
/*   minutes : time of day in minutes						*/
/* Return value:										*/
/*   string of the format HH:MM:SS, minutes and seconds are zero padded*/
/***********************************************************************/

	void timeString(char dest[8], double minutes) ;

	void timeString(char dest[8], double minutes)
	/* timeString returns a zero-padded string (HH:MM:SS) given time in minutes*/
	{
		double floatHour = minutes / 60.0;
		double hour = floor(floatHour);
		double floatMinute = 60.0 * (floatHour - floor(floatHour));
		double minute = floor(floatMinute);
		double floatSec = 60.0 * (floatMinute - floor(floatMinute));
		double second = floor(floatSec + 0.5);
		if (second > 59) {
			second = 0;
			minute += 1;
		}

		snprintf(dest, 8, "%02d:%02d:%02d", (int) hour, (int) minute, (int) second);
/*
		var timeStr = hour + ":";
		if (minute < 10)	/ *	i.e. only one digit* /
			timeStr += "0" + minute + ":";
		else
			timeStr += minute + ":";
		if (second < 10)	/ *	i.e. only one digit* /
			timeStr += "0" + second;
		else
			timeStr += second;

		return timeStr;
*/
	}


/***********************************************************************/
/* Name:    timeStringShortAMPM							*/
/* Type:    Function									*/
/* Purpose: convert time of day in minutes to a zero-padded string	*/
/*		suitable for printing to the form text fields.  If time	*/
/*		crosses a day boundary, date is appended.				*/
/* Arguments:										*/
/*   minutes : time of day in minutes						*/
/*   JD  : julian day									*/
/* Return value:										*/
/*   string of the format HH:MM[AM/PM] (DDMon)					*/
/***********************************************************************/

/* timeStringShortAMPM returns a zero-padded string (HH:MM *M) given time in */
/* minutes and appends short date if time is > 24 or < 0, resp.*/

	void timeStringShortAMPM(char dest[15], month_t monthList[12], double minutes, double JD) ;

	void timeStringShortAMPM(char dest[15], month_t monthList[12], double minutes, double JD)
	{
		double julianday = JD;
		double floatHour = minutes / 60.0;
		double hour = floor(floatHour);
		double floatMinute = 60.0 * (floatHour - floor(floatHour));
		double minute = floor(floatMinute);
		double floatSec = 60.0 * (floatMinute - floor(floatMinute));
		double second = floor(floatSec + 0.5);
		bool PM = false;
		bool daychange;

		minute += (second >= 30)? 1 : 0;

		if (minute >= 60) 
		{
			minute -= 60;
			hour ++;
		}

		daychange = false;
		if (hour > 23) 
		{
			hour -= 24;
			daychange = true;
			julianday += 1.0;
		}

		if (hour < 0)
		{
			hour += 24;
			daychange = true;
			julianday -= 1.0;
		}

		if (hour > 12)
		{
			hour -= 12;
			PM = true;
		}

            if ((int) hour == 12)
		{
              PM = true;
            }

		if ((int) hour == 0)
		{
			PM = false;
			hour = 12;
		}

		snprintf(dest, 8, "%02d:%02d %s", (int) hour, (int) minute, ((PM)?"PM":"AM"));
		if (daychange) {
			dest[8] = ' ';
			calcDayFromJD(dest + 9, monthList, julianday);
		}
		/*var timeStr = hour + ":";
		if (minute < 10)	/ *	i.e. only one digit* /
			timeStr += "0" + minute + ((PM)?"PM":"AM");
		else
			timeStr += "" + minute + ((PM)?"PM":"AM");

		if (daychange) return timeStr + " " + calcDayFromJD(julianday);
		return timeStr; */
	}


/***********************************************************************/
/* Name:    timeStringAMPMDate							*/
/* Type:    Function									*/
/* Purpose: convert time of day in minutes to a zero-padded string	*/
/*		suitable for printing to the form text fields, and appends	*/
/*		the date.									*/
/* Arguments:										*/
/*   minutes : time of day in minutes						*/
/*   JD  : julian day									*/
/* Return value:										*/
/*   string of the format HH:MM[AM/PM] DDMon					*/
/***********************************************************************/

/* timeStringAMPMDate returns a zero-padded string (HH:MM[AM/PM]) given time */
/* in minutes and julian day, and appends the short date*/

	void timeStringAMPMDate(char dest[15], month_t monthList[12], double minutes, double JD) ;

	void timeStringAMPMDate(char dest[15], month_t monthList[12], double minutes, double JD)
	{
		double julianday = JD;
		double floatHour = minutes / 60.0;
		double hour = floor(floatHour);
		double floatMinute = 60.0 * (floatHour - floor(floatHour));
		double minute = floor(floatMinute);
		double floatSec = 60.0 * (floatMinute - floor(floatMinute));
		double second = floor(floatSec + 0.5);
		bool PM;

		minute += (second >= 30)? 1 : 0;

		if (minute >= 60) 
		{
			minute -= 60;
			hour ++;
		}

		if (hour > 23) 
		{
			hour -= 24;
			julianday += 1.0;
		}

		if (hour < 0)
		{
			hour += 24;
			julianday -= 1.0;
		}

		PM = false;
		if (hour > 12)
		{
			hour -= 12;
			PM = true;
		}

        if ((int) hour == 12)
		{
            PM = true;
        }

		if ((int) hour == 0)
		{
			PM = false;
			hour = 12;
		}

		snprintf(dest, 8, "%02d:%02d %s", (int) hour, (int) minute, ((PM)?"PM":"AM"));
		dest[8] = ' ';
		calcDayFromJD(dest + 9, monthList, julianday);
		/*var timeStr = hour + ":";
		if (minute < 10)	/ *	i.e. only one digit* /
			timeStr += "0" + minute + ((PM)?"PM":"AM");
		else
			timeStr += minute + ((PM)?"PM":"AM");

		return timeStr + " " + calcDayFromJD(julianday);*/
	}


/***********************************************************************/
/* Name:    timeStringDate								*/
/* Type:    Function									*/
/* Purpose: convert time of day in minutes to a zero-padded 24hr time	*/
/*		suitable for printing to the form text fields.  If time	*/
/*		crosses a day boundary, date is appended.				*/
/* Arguments:										*/
/*   minutes : time of day in minutes						*/
/*   JD  : julian day									*/
/* Return value:										*/
/*   string of the format HH:MM (DDMon)						*/
/***********************************************************************/

/* timeStringDate returns a zero-padded string (HH:MM) given time in minutes*/
/* and julian day, and appends the short date if time crosses a day boundary*/

	void timeStringDate(char dest[11], month_t monthList[12], double minutes, double JD) ;

	void timeStringDate(char dest[11], month_t monthList[12], double minutes, double JD)
	{
		double julianday = JD;
		double floatHour = minutes / 60.0;
		double hour = floor(floatHour);
		double floatMinute = 60.0 * (floatHour - floor(floatHour));
		double minute = floor(floatMinute);
		double floatSec = 60.0 * (floatMinute - floor(floatMinute));
		double second = floor(floatSec + 0.5);
		bool daychange;

		minute += (second >= 30)? 1 : 0;

		if (minute >= 60) 
		{
			minute -= 60;
			hour ++;
		}

		daychange = false;
		if (hour > 23) 
		{
			hour -= 24;
			julianday += 1.0;
			daychange = true;
		}

		if (hour < 0)
		{
			hour += 24;
			julianday -= 1.0;
			daychange = true;
		}
		snprintf(dest, 11, "%02d:%02d", (int) hour, (int) minute);
		if (daychange) {
			dest[6] = ' ';
			calcDayFromJD(dest + 7, monthList, julianday);
		}

		/*var timeStr = hour + ":";
		if (minute < 10)	/ *	i.e. only one digit* /
			timeStr += "0" + minute;
		else
			timeStr += minute;

		if (daychange) return timeStr + " " + calcDayFromJD(julianday);
		return timeStr;*/
	}

	
/***********************************************************************/
/* Name:    calcSun									*/
/* Type:    Main Function called by form controls				*/
/* Purpose: calculate time of sunrise and sunset for the entered date	*/
/*		and location.  In the special cases near earth's poles, 	*/
/*		the date of nearest sunrise and set are reported.		*/
/* Arguments:										*/
/*   riseSetForm : for displaying results					*/
/*   latLongForm : for reading latitude and longitude data			*/
/*   index : daylight saving yes/no select					*/
/*   index2 : city select index							*/
/* Return value:										*/
/*   none											*/
/*	(fills riseSetForm text fields with results of calculations)	*/
/***********************************************************************/

	void calcSun(month_t monthList[12], city_t city[93], ans_t YesNo[2], f_t *riseSetForm, f_t *latLongForm, size_t index, size_t index2) ;

	void calcSun(month_t monthList[12], city_t city[93], ans_t YesNo[2], f_t *riseSetForm, f_t *latLongForm, size_t index, size_t index2) 
	{
		double latitude, longitude;
		size_t indexRS;

		double JD;
		char const* dow;
		double doy;
		double T;
		double alpha, theta, Etime;

		double eqTime;
		double solarDec;
		bool nosunrise;
		double riseTimeGMT;

		bool nosunset;
		double setTimeGMT;

		bool daySavings;

		if(index2 != 0)
		{
			setLatLong(city, latLongForm, index2);
		}

		latitude = getLatitude(latLongForm);
		longitude = getLongitude(latLongForm);
		indexRS = riseSetForm->mos;
		if (isValidInput(monthList, riseSetForm, indexRS/*, latLongForm*/)) 
		{
			if((latitude >= -90) && (latitude < -89))
			{
				alert("All latitudes between 89 and 90 S\n will be set to -89");
				latLongForm->latDeg = -89;
				latitude = -89;
			}
			if ((latitude <= 90) && (latitude > 89))
			{
				alert("All latitudes between 89 and 90 N\n will be set to 89");
				latLongForm->latDeg = 89;
				latitude = 89;
			}
			
			/*****	Calculate the time of sunrise			*/

/*********************************************************************/
/****************   NEW STUFF   ******   January, 2001   ****************
/*********************************************************************/

			JD = calcJD( (riseSetForm->year), indexRS + 1, (riseSetForm->day));
			dow = calcDayOfWeek(JD);
			doy = calcDayOfYear(indexRS + 1, (riseSetForm->day), isLeapYear(riseSetForm->year));
			T = calcTimeJulianCent(JD);

			alpha = calcSunRtAscension(T);
			theta = calcSunDeclination(T);
			Etime = calcEquationOfTime(T);

			/*riseSetForm["dbug"].value = doy;*/

/*********************************************************************/

			eqTime = Etime;
			solarDec = theta;

			/* Calculate sunrise for this date*/
			/* if no sunrise is found, set flag nosunrise*/

			nosunrise = false;

			riseTimeGMT = calcSunriseUTC(JD, latitude, longitude);
			if (!isNumber(riseTimeGMT))
			{
				nosunrise = true;
			}

			/* Calculate sunset for this date*/
			/* if no sunset is found, set flag nosunset*/

			nosunset = false;
			setTimeGMT = calcSunsetUTC(JD, latitude, longitude);
			if (!isNumber(setTimeGMT))
			{
				nosunset = true;
			}

			daySavings = YesNo[index] ;  /* = 0 (no) or 60 (yes)*/
			var zone = latLongForm->hrsToGMT ;
			if(zone > 12 || zone < -12.5)
			{
				alert("The offset must be between -12.5 and 12.  \n Setting \"Off-Set\"=0");
				zone = "0";
				latLongForm->hrsToGMT = zone;
			}

			if (!nosunrise)		/* Sunrise was found*/
			{
				var riseTimeLST = riseTimeGMT - (60 * zone) + daySavings;	
					/*	in minutes*/
				var riseStr = timeStringShortAMPM(riseTimeLST, JD);
				var utcRiseStr = timeStringDate(riseTimeGMT, JD);

				riseSetForm["sunrise"].value = riseStr;
				riseSetForm["utcsunrise"].value = utcRiseStr;
			}

			if (!nosunset)		/* Sunset was found*/
			{
				var setTimeLST = setTimeGMT - (60 * zone) + daySavings;
				var setStr = timeStringShortAMPM(setTimeLST, JD);
				var utcSetStr = timeStringDate(setTimeGMT, JD);

				riseSetForm["sunset"].value = setStr;
				riseSetForm["utcsunset"].value = utcSetStr;
			}

			/* Calculate solar noon for this date*/

			var solNoonGMT = calcSolNoonUTC(T, longitude);
			var solNoonLST = solNoonGMT - (60 * zone) + daySavings;

			var solnStr = timeString(solNoonLST);
			var utcSolnStr = timeString(solNoonGMT);

			riseSetForm["solnoon"].value = solnStr;
			riseSetForm["utcsolnoon"].value = utcSolnStr;

			var tsnoon = calcTimeJulianCent(calcJDFromJulianCent(T) -0.5 + solNoonGMT/1440.0); 

			eqTime = calcEquationOfTime(tsnoon);
			solarDec = calcSunDeclination(tsnoon);

			riseSetForm["eqTime"].value = (floor(100*eqTime))/100;
			riseSetForm["solarDec"].value = (floor(100*(solarDec)))/100;
			
			/***********Convert lat and long to standard format*/
			convLatLong(latLongForm);

			/* report special cases of no sunrise*/

			if(nosunrise)
			{ 
				riseSetForm["utcsunrise"].value = "";
				/* if Northern hemisphere and spring or summer, OR  */
				/* if Southern hemisphere and fall or winter, use */
				/* previous sunrise and next sunset*/

				if ( ((latitude > 66.4) && (doy > 79) && (doy < 267)) ||
				   ((latitude < -66.4) && ((doy < 83) || (doy > 263))) )
				{
					newjd = findRecentSunrise(JD, latitude, longitude);
					newtime = calcSunriseUTC(newjd, latitude, longitude)
						 - (60 * zone) + daySavings;
					if (newtime > 1440)
					{
						newtime -= 1440;
						newjd += 1.0;
					}
					if (newtime < 0)
					{
						newtime += 1440;
						newjd -= 1.0;
					}
					riseSetForm["sunrise"].value = 
						timeStringAMPMDate(newtime, newjd);
					riseSetForm["utcsunrise"].value = "prior sunrise";
				}

				/* if Northern hemisphere and fall or winter, OR */
				/* if Southern hemisphere and spring or summer, use */
				/* next sunrise and previous sunset*/

				else if ( ((latitude > 66.4) && ((doy < 83) || (doy > 263))) ||
					((latitude < -66.4) && (doy > 79) && (doy < 267)) )
				{
					newjd = findNextSunrise(JD, latitude, longitude);
					newtime = calcSunriseUTC(newjd, latitude, longitude)
						 - (60 * zone) + daySavings;
					if (newtime > 1440)
					{
						newtime -= 1440;
						newjd += 1.0;
					}
					if (newtime < 0)
					{
						newtime += 1440;
						newjd -= 1.0;
					}
					riseSetForm["sunrise"].value = 
						timeStringAMPMDate(newtime, newjd);
/*					riseSetForm["sunrise"].value = calcDayFromJD(newjd)*/
/*						+ " " + timeStringDate(newtime, newjd);*/
					riseSetForm["utcsunrise"].value = "next sunrise";
				}
				else 
				{
					alert("Cannot Find Sunrise!");
				}

				/* alert("Last Sunrise was on day " + findRecentSunrise(JD, latitude, longitude));*/
				/* alert("Next Sunrise will be on day " + findNextSunrise(JD, latitude, longitude));*/

			}

			if(nosunset)
			{ 
				riseSetForm["utcsunset"].value = "";
				/* if Northern hemisphere and spring or summer, OR*/
				/* if Southern hemisphere and fall or winter, use */
				/* previous sunrise and next sunset*/

				if ( ((latitude > 66.4) && (doy > 79) && (doy < 267)) ||
				   ((latitude < -66.4) && ((doy < 83) || (doy > 263))) )
				{
					newjd = findNextSunset(JD, latitude, longitude);
					newtime = calcSunsetUTC(newjd, latitude, longitude)
						 - (60 * zone) + daySavings;
					if (newtime > 1440)
					{
						newtime -= 1440;
						newjd += 1.0;
					}
					if (newtime < 0)
					{
						newtime += 1440;
						newjd -= 1.0;
					}
					riseSetForm["sunset"].value = 
						timeStringAMPMDate(newtime, newjd);
					riseSetForm["utcsunset"].value = "next sunset";
					riseSetForm["utcsolnoon"].value = "";
				}

				/* if Northern hemisphere and fall or winter, OR*/
				/* if Southern hemisphere and spring or summer, use */
				/* next sunrise and last sunset*/

				else if ( ((latitude > 66.4) && ((doy < 83) || (doy > 263))) ||
					((latitude < -66.4) && (doy > 79) && (doy < 267)) )
				{
					newjd = findRecentSunset(JD, latitude, longitude);
					newtime = calcSunsetUTC(newjd, latitude, longitude)
						 - (60 * zone) + daySavings;
					if (newtime > 1440)
					{
						newtime -= 1440;
						newjd += 1.0;
					}
					if (newtime < 0)
					{
						newtime += 1440;
						newjd -= 1.0;
					}
					riseSetForm["sunset"].value = 
						timeStringAMPMDate(newtime, newjd);
					riseSetForm["utcsunset"].value = "prior sunset";
					riseSetForm["solnoon"].value = "N/A";
					riseSetForm["utcsolnoon"].value = "";
				}

				else 
				{
					alert ("Cannot Find Sunset!");
				}
			}
		}
	}



/*********************************************************************/

	#pragma GCC diagnostic pop

