lib_LTLIBRARIES = libsolar.la
libsolar_la_SOURCES = solar.c solar2.c solar3.c solar-common.c sunriset.c
include_HEADERS = solar.h solar2.h solar3.h solar-common.h sunriset.h
#libsolar_la_CFLAGS =
libsolar_la_LDFLAGS = -lm

bin_PROGRAMS = solar-test solar-test2 solar

solar_test_SOURCES = solar-test.c
solar_test_LDFLAGS = -lm
solar_test_LDADD = libsolar.la
#solar_test_CFLAGS =

solar_test2_SOURCES = solar-test2.c
solar_test2_LDFLAGS = -lm
solar_test2_LDADD = libsolar.la

solar_SOURCES = solar-main.c
solar_LDFLAGS = -lm
solar_LDADD = libsolar.la

#AM_CPPFLAGS = -D__STDC_INT64__
