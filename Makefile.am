AUTOMAKE_OPTIONS=foreign

lib_LTLIBRARIES = \
	libManagerContainer.la

BUILT_SOURCES = \
	testexternals.C

INCLUDES = \
	-I$(includedir)

include_HEADERS = \
	Manager.hpp \
	ManagerContainer.hpp

noinst_PROGRAMS = \
	testexternals

bin_PROGRAMS=\
	tmc

tmc_LDADD = \
        libManagerContainer.la

tmc_SOURCES=\
	tmc.cpp

testexternals_LDADD = \
        libManagerContainer.la

textexternal_SOURCES= \
	testexternals.cpp 

libManagerContainer_la_SOURCES = \
	Manager.cpp \
	ManagerContainer.cpp

libManagerContainer_la_LIBADD = \
	-L$(libdir) 

testexternals.cpp:
	echo "//*** this is a generated file. Do not commit, do not edit" > $@
	echo "int main()" >> $@	
	echo "{" >> $@
	echo "  return 0;" >> $@
	echo "}" >> $@

clean-local:
	rm -f testexternals*
