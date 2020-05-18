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

