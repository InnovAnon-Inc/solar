AM_CPPFLAGS = -D__STDC_INT64__

lib_LTLIBRARIES =
bin_PROGRAMS    =

lib_LTLIBRARIES += libsolar.la
libsolar_la_SOURCES = solar.c solar2.c solar3.c solar4.c solar-common.c sunriset.c
include_HEADERS = solar.h solar2.h solar3.h solar4.h solar-common.h sunriset.h
libsolar_la_CPPFLAGS = $(GLITTER_CFLAGS)
libsolar_la_LIBADD   = $(GLITTER_LIBS)

bin_PROGRAMS += solar-test4
solar_test4_SOURCES = solar-test.c
solar_test4_CPPFLAGS =         $(GLITTER_CFLAGS)
solar_test4_LDADD    = -lsolar $(GLITTER_LIBS)
EXTRA_solar_test4_DEPENDENCIES = libsolar.la

bin_PROGRAMS += solar-test2
solar_test2_SOURCES = solar-test2.c
solar_test2_CPPFLAGS =         $(GLITTER_CFLAGS)
solar_test2_LDADD    = -lsolar $(GLITTER_LIBS)
EXTRA_solar_test2_DEPENDENCIES = libsolar.la

bin_PROGRAMS += solar
solar_SOURCES = solar-main.c
solar_CPPFLAGS =         $(GLITTER_CFLAGS) $(EZPARSE_CFLAGS)
solar_LDADD    = -lsolar $(GLITTER_LIBS)   $(EZPARSE_LIBS)
EXTRA_solar_DEPENDENCIES = libsolar.la

lib_LTLIBRARIES += libsunriset.la
libsunriset_la_SOURCES = sunriset.c
#include_HEADERS = sunriset.h
libsunriset_la_CPPFLAGS = $(GLITTER_CFLAGS)
libsunriset_la_LIBADD   = $(GLITTER_LIBS)

bin_PROGRAMS += sunriset
sunriset_SOURCES  = sunriset-test.c
sunriset_CPPFLAGS =            $(GLITTER_CFLAGS) $(EZPARSE_CFLAGS)
sunriset_LDADD    = -lsunriset $(GLITTER_LIBS)   $(EZPARSE_LIBS)
EXTRA_sunriset_DEPENDENCIES = libsunriset.la

#lib_LTLIBRARIES += libsolar2.la
#libsolar2_la_SOURCES = libsolar.c
##include_HEADERS = solar.h solar2.h solar3.h solar4.h solar-common.h sunriset.h
#libsolar2_la_CPPFLAGS = $(GLITTER_CFLAGS)
#libsolar2_la_LIBADD   = $(GLITTER_LIBS)

bin_PROGRAMS += solar5
solar5_SOURCES  = solar5.c
solar5_CPPFLAGS = $(GLITTER_CFLAGS) $(EZPARSE_CFLAGS)
solar5_LDADD    = $(GLITTER_LIBS)   $(EZPARSE_LIBS)
#EXTRA_solar5_DEPENDENCIES = libsolar5.la

