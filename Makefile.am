AUTOMAKE_OPTIONS=foreign

lib_LTLIBRARIES = \
	libManagerContainer.la

BUILT_SOURCES = \
	testexternals.C

INCLUDES = \
	-I$(includedir)

include_HEADERS = \
	Manager.hh \
	ManagerContainer.hh

noinst_PROGRAMS = \
	testexternals

bin_PROGRAMS=\
	tmc

tmc_LDADD = \
        libManagerContainer.la

tmc_SOURCES=\
	tmc.cc

testexternals_LDADD = \
        libManagerContainer.la

textexternal_SOURCES= \
	testexternals.cc 

libManagerContainer_la_SOURCES = \
	Manager.cc \
	ManagerContainer.cc

libManagerContainer_la_LIBADD = \
	-L$(libdir) 

testexternals.cc:
	echo "//*** this is a generated file. Do not commit, do not edit" > $@
	echo "int main()" >> $@	
	echo "{" >> $@
	echo "  return 0;" >> $@
	echo "}" >> $@

clean-local:
	rm -f testexternals*
