AM_CPPFLAGS = -D__STDC_INT64__

lib_LTLIBRARIES =
include_HEADERS =
bin_PROGRAMS    =

lib_LTLIBRARIES += libsimon.la
libsimon_la_CPPFLAGS = $(GLITTER_CFLAGS)
libsimon_la_LIBADD   = $(GLITTER_LIBS)
include_HEADERS += simon.h

bin_PROGRAMS += simon-test
simon_test_CPPFLAGS =         $(GLITTER_CFLAGS)
simon_test_LDADD    = -lsimon $(GLITTER_LIBS)
EXTRA_simon_test_DEPENDENCIES = libsimon.la

