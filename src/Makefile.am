AM_CPPFLAGS = -D__STDC_INT64__

lib_LTLIBRARIES =
include_HEADERS =
bin_PROGRAMS    =

lib_LTLIBRARIES += libsimon.la
#libsimon_la_LIBADD = 
include_HEADERS += simon.h

bin_PROGRAMS += simon-test
simon_test_CPPFLAGS = $(SIMON_CFLAGS)
simon_test_LDADD    = $(SIMON_LIBS)
EXTRA_simon_test_DEPENDENCIES = libsimon.la

