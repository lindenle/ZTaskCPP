AUTOMAKE_OPTIONS=foreign

lib_LTLIBRARIES = \
	libManagerContainer.la

INCLUDES = \
	-I$(includedir)

include_HEADERS = \
	Client.hpp \
	Manager.hpp \
	ManagerContainerExceptions.hpp \
	ManagerContainer.hpp

bin_PROGRAMS = \
	tm \
	tmc 

tm_LDADD = \
        libManagerContainer.la \
	-lboost_signals

tm_SOURCES= \
	tm.cpp

tmc_LDADD = \
       libManagerContainer.la \
	-lboost_signals

tmc_SOURCES=\
	tmc.cpp

libManagerContainer_la_SOURCES = \
	Client.cpp \
	Manager.cpp \
	ManagerContainer.cpp

libManagerContainer_la_LIBADD = \
	-L$(libdir) 

