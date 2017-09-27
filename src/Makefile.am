lib_LTLIBRARIES = libsolar.la
libsolar_la_SOURCES = solar.c solar2.c solar3.c solar4.c solar-common.c sunriset.c
include_HEADERS = solar.h solar2.h solar3.h solar4.h solar-common.h sunriset.h
#libsolar_la_CFLAGS =
libsolar_la_LIBADD = -lm

bin_PROGRAMS = solar-test4 solar-test2 solar

solar_test4_SOURCES = solar-test.c
solar_test4_LDADD = libsolar.la -lm
#solar_test4_CFLAGS =

solar_test2_SOURCES = solar-test2.c
solar_test2_LDADD = libsolar.la -lm

solar_SOURCES = solar-main.c
solar_LDADD = libsolar.la -lm -lezparse

AM_CPPFLAGS += -D__STDC_INT64__
