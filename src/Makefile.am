AM_CPPFLAGS = -D__STDC_INT64__

SUBDIRS = ../glitter
AM_CPPFLAGS += -I $(top_srcdir)/glitter/src

lib_LTLIBRARIES =
include_HEADERS =
bin_PROGRAMS    =

include Makefile-LIBADD.inc

lib_LTLIBRARIES += libstd.la
libstd_la_LIBADD = $(LIBSTAT_LIBADD)
include_HEADERS += std.h
bin_PROGRAMS += std-test
std_LDADD = libstd.la $(LIBSTD_LIBADD)
