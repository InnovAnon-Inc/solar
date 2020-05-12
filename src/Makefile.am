AM_CPPFLAGS = -D__STDC_INT64__

#if USE_SUBMODULES
#SUBDIRS = ../glitter
#AM_CPPFLAGS += -I $(top_srcdir)/glitter/src
#endif

#include Makefile-LIBADD.inc
dist_bin_SCRIPTS = libsolar_config solar_config solar_test2_config solar_test4_config

lib_LTLIBRARIES = libsolar.la
libsolar_la_SOURCES = solar.c solar2.c solar3.c solar4.c solar-common.c sunriset.c
include_HEADERS = solar.h solar2.h solar3.h solar4.h solar-common.h sunriset.h
libsolar_la_LIBADD = @LIBSOLAR_LIBADD@

bin_PROGRAMS = solar-test4 solar-test2 solar

solar_test4_SOURCES = solar-test.c
#solar_test4_LDADD = libsolar.la $(LIBSOLAR_LIBADD)
solar_test4_LDADD = @SOLAR_TEST4_LIBADD@
EXTRA_solar_test4_DEPENDENCIES = libsolar.la

solar_test2_SOURCES = solar-test2.c
#solar_test2_LDADD = libsolar.la $(LIBSOLAR_LIBADD)
solar_test2_LDADD = @SOLAR_TEST2_LIBADD@
EXTRA_solar_test2_DEPENDENCIES = libsolar.la

#include ../../ezparse/src/Makefile-LIBADD.inc
solar_SOURCES = solar-main.c
#solar_LDADD = libsolar.la $(LIBSOLAR_LIBADD) -lezparse $(LIBEZPARSE_LIBADD)
solar_LDADD = @SOLAR_LIBADD@
EXTRA_solar_DEPENDENCIES = libsolar.la
