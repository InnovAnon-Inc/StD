AM_CPPFLAGS = -D__STDC_INT64__

SUBDIRS = ../glitter
AM_CPPFLAGS += -I ../glitter/src

lib_LTLIBRARIES =
include_HEADERS =
bin_PROGRAMS    =

LIBSTD_LIBADD =

lib_LTLIBRARIES += libstd.la
libstd_la_LIBADD = $(LIBSTAT_LIBADD)
include_HEADERS += std.h
bin_PROGRAMS += std-test
std_LDADD = libstd.la $(LIBSTD_LIBADD)
