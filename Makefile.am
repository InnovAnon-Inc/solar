# Install the pkg-config file.
pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = src/libsolar.pc src/solar.pc src/solar-test2.pc src/solar-test4.pc

DISTCLEANFILES = $(pkgconfig_DATA)
EXTRA_DIST = src/libsolar.pc.in src/solar.pc.in src/solar-test2.pc.in src/solar-test4.pc.in

SUBDIRS = src
dist_doc_DATA = README.md
ACLOCAL_AMFLAGS = -I m4

