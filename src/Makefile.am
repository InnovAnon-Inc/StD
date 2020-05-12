AM_CPPFLAGS = -D__STDC_INT64__

#if USE_SUBMODULES
#SUBDIRS = ../glitter
#AM_CPPFLAGS += -I $(top_srcdir)/glitter/src
#endif

lib_LTLIBRARIES =
include_HEADERS =
bin_PROGRAMS    =

#include Makefile-LIBADD.inc
dist_bin_SCRIPTS = libsimon_config

lib_LTLIBRARIES += libsimon.la
#libsimon_la_LIBADD = $(LIBSTAT_LIBADD)
libsimon_la_LIBADD = @LIBSIMON_LIBADD@
include_HEADERS += simon.h
bin_PROGRAMS += simon-test
#simon_test_LDADD = libsimon.la $(LIBSIMON_LIBADD)
simon_test_LDADD = @SIMON_TEST_LIBADD@
EXTRA_simon_test_DEPENDENCIES = libsimon.la
