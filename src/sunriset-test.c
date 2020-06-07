#if HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>

#include <glitter.h>

#include <sunriset.h>

int main(void)
{
      int year,month,day;
      double lon, lat;
      double daylen, civlen, nautlen, astrlen;
      double rise, set, civ_start, civ_end, naut_start, naut_end,
             astr_start, astr_end;
      double rise2, set2;
      int    rs, civ, naut, astr;

      printf( "Longitude (+ is east) and latitude (+ is north) : " );
      error_check (scanf( "%lf %lf", &lon, &lat ) != 2) return EXIT_FAILURE;

      for(;;)
      {
            printf( "Input date ( yyyy mm dd ) (ctrl-C exits): " );
            error_check (scanf( "%d %d %d", &year, &month, &day ) != 3) return EXIT_FAILURE;

	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunsuffixed-float-constants"
            daylen  = day_length(year,month,day,lon,lat);
            civlen  = day_civil_twilight_length(year,month,day,lon,lat);
            nautlen = day_nautical_twilight_length(year,month,day,lon,lat);
            astrlen = day_astronomical_twilight_length(year,month,day,
                  lon,lat);
	#pragma GCC diagnostic pop

            printf( "Day length:                 %5.2f hours\n", daylen );
            printf( "With civil twilight         %5.2f hours\n", civlen );
            printf( "With nautical twilight      %5.2f hours\n", nautlen );
            printf( "With astronomical twilight  %5.2f hours\n", astrlen );
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunsuffixed-float-constants"
            printf( "Length of twilight: civil   %5.2f hours\n",
                  (civlen-daylen)/2.0);
            printf( "                  nautical  %5.2f hours\n",
                  (nautlen-daylen)/2.0);
            printf( "              astronomical  %5.2f hours\n",
                  (astrlen-daylen)/2.0);

            rs   = sun_rise_set         ( year, month, day, lon, lat,
                                          &rise, &set );
            civ  = civil_twilight       ( year, month, day, lon, lat,
                                          &civ_start, &civ_end );
            naut = nautical_twilight    ( year, month, day, lon, lat,
                                          &naut_start, &naut_end );
            astr = astronomical_twilight( year, month, day, lon, lat,
                                          &astr_start, &astr_end );

            printf( "Sun at south %5.2fh UT\n", (rise+set)/2.0 );
	#pragma GCC diagnostic pop

            switch( rs )
            {
                case 0:
                    printf( "Sun rises %5.2fh UT, sets %5.2fh UT\n",
                             rise, set );
                    break;
                case +1:
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunsuffixed-float-constants"
                    sun_rise_set         ( year, month, day+1, lon, lat,
                                          &rise2, &set2 );
	#pragma GCC diagnostic pop
                    printf( "Sun above horizon; next sunset: %5.2f; prev sunrise: %5.2f\n", set, rise );
                    break;
                case -1:
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunsuffixed-float-constants"
                    sun_rise_set         ( year, month, day-1, lon, lat,
                                          &rise2, &set2 );
	#pragma GCC diagnostic pop
                    printf( "Sun below horizon; prev sunrise: %5.2f; next sunset: %5.2f\n", rise, set );
                    break;
                default: __builtin_unreachable();
            }

            switch( civ )
            {
                case 0:
                    printf( "Civil twilight starts %5.2fh, "
                            "ends %5.2fh UT\n", civ_start, civ_end );
                    break;
                case +1:
                    printf( "Never darker than civil twilight\n" );
                    break;
                case -1:
                    printf( "Never as bright as civil twilight\n" );
                    break;
                default: __builtin_unreachable();
            }

            switch( naut )
            {
                case 0:
                    printf( "Nautical twilight starts %5.2fh, "
                            "ends %5.2fh UT\n", naut_start, naut_end );
                    break;
                case +1:
                    printf( "Never darker than nautical twilight\n" );
                    break;
                case -1:
                    printf( "Never as bright as nautical twilight\n" );
                    break;
                default: __builtin_unreachable();
            }

            switch( astr )
            {
                case 0:
                    printf( "Astronomical twilight starts %5.2fh, "
                            "ends %5.2fh UT\n", astr_start, astr_end );
                    break;
                case +1:
                    printf( "Never darker than astronomical twilight\n" );
                    break;
                case -1:
                    printf( "Never as bright as astronomical twilight\n" );
                    break;
                default: __builtin_unreachable();
            }

      }

      return EXIT_SUCCESS;
}

