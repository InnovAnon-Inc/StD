lib_LTLIBRARIES =
include_HEADERS =
bin_PROGRAMS    =

lib_LTLIBRARIES += libstd.la
libstd_la_SOURCES = std.c
#libarray_la_LIBADD = -lswap
include_HEADERS += std.h
bin_PROGRAMS += std
std_SOURCES = std-test.c
std_LDADD = libstd.la

AM_CPPFLAGS = -D__STDC_INT64__
AM_CPPFLAGS += -I $(srcdir)/../glitter/src
