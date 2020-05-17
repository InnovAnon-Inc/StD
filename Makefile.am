# Install the pkg-config file.
pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = src/libsimon.pc src/simon-test.pc

DISTCLEANFILES = $(pkgconfig_DATA)
EXTRA_DIST = src/libsimon.pc.in src/simon-test.pc.in

SUBDIRS = src
dist_doc_DATA = README.md
ACLOCAL_AMFLAGS = -I m4

