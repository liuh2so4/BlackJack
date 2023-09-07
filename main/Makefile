#
#  Sample Makefile for C++ programs 
#  Designed for the OOP class
#  by Tsai-Yen Li (li@cs.nccu.edu.tw) 08/08/96
#

# the name of this package. 
# The library and tar file, if any, will be named after it.
PACKAGE  = BJackTest
# The executable program
TARGET   = BJackTest
# The C++ source programs (.cc) [multiple files]
SOURCES  = AnsiPrint Card  BJackPlayer BJackDealer ConsoleMenu BJackGame
# The C++ source program for testing your implementation
TEST     = BJackTest

O_DIR    = O_$(HOSTTYPE)
SYSDIR   = /usr/local
CLASSDIR = $(SYSDIR)/class/oop
BASEDIR  = .
INCDIR   = $(BASEDIR)/include #-I$(SYSDIR)/lib/g++-include 
LIBDIR   = -L$(BASEDIR)/lib -L/usr/openwin/lib -L/usr/ucblib
LIBS     = $(LIBDIR) -lm -lc

# You may not need to modify anything below

CXX      = g++
CXXFLAGS = -Wall -Wno-deprecated -I$(INCDIR) #-D__STDC__ 
TARG     = $(TARGET)_$(HOSTTYPE)
LIB      = lib$(PACKAGE)_$(HOSTTYPE).a

SRCS     = ${SOURCES:%=%.cc}
OBJS     = ${SRCS:%.cc=$(O_DIR)/%.o}
HEADERS  = ${SRCS:%.cc=%.h} Cards.h
TESTSRC  = ${TEST:%=%.cc}
TESTOBJ  = ${TESTSRC:%.cc=$(O_DIR)/%.o}
#MAKEDEP  = $(CLASSDIR)/bin/makedepend
MAKEDEP  = makedepend

$(TARG) : $(O_DIR) $(OBJS) $(TESTOBJ)
	$(CXX) -o $@ $(CXXFLAGS) $(OBJS) $(TESTOBJ) $(LIBS) 

$(O_DIR) :
	mkdir $@

lib : $(O_DIR) $(LIB)
	@echo $@ Built

$(LIB) : $(OBJS)
	rm -f $(LIB)
	ar cr $@ $(OBJS)
	ranlib $@

$(O_DIR)/%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean: 
	rm -f $(OBJS) $(TESTOBJ) $(TARG) core* *~ Makefile.bak 
	rmdir $(O_DIR)

tags: 
	etags $(SRCS) $(HEADERS)

ztar:
	/usr/local/bin/tar zcvf $(PACKAGE).tgz Makefile $(SRCS) $(HEADERS) $(TESTSRC) 

ci:
	ci -l Makefile $(SRCS) $(HEADERS) $(TESTSRC) 

depend : 
	$(MAKEDEP) -p$(O_DIR)/ -I$(INCDIR) $(SRCS) $(TESTSRC)

# DO NOT DELETE THIS LINE -- make depend depends on it.

O_i86pc/AnsiPrint.o: AnsiPrint.h
O_i86pc/Card.o: /usr/include/assert.h AnsiPrint.h CardPat.h Card.h
O_i86pc/BJackPlayer.o: /usr/include/stdio.h /usr/include/sys/feature_tests.h
O_i86pc/BJackPlayer.o: /usr/include/sys/ccompile.h
O_i86pc/BJackPlayer.o: /usr/include/sys/isa_defs.h
O_i86pc/BJackPlayer.o: /usr/include/iso/stdio_iso.h
O_i86pc/BJackPlayer.o: /usr/include/sys/va_list.h /usr/include/stdio_tag.h
O_i86pc/BJackPlayer.o: /usr/include/stdio_impl.h /usr/include/iso/stdio_c99.h
O_i86pc/BJackPlayer.o: /usr/include/stdlib.h /usr/include/iso/stdlib_iso.h
O_i86pc/BJackPlayer.o: /usr/include/iso/stdlib_c99.h /usr/include/string.h
O_i86pc/BJackPlayer.o: /usr/include/iso/string_iso.h AnsiPrint.h CardPat.h
O_i86pc/BJackPlayer.o: BJackPlayer.h Card.h
O_i86pc/BJackDealer.o: /usr/include/stdio.h /usr/include/sys/feature_tests.h
O_i86pc/BJackDealer.o: /usr/include/sys/ccompile.h
O_i86pc/BJackDealer.o: /usr/include/sys/isa_defs.h
O_i86pc/BJackDealer.o: /usr/include/iso/stdio_iso.h
O_i86pc/BJackDealer.o: /usr/include/sys/va_list.h /usr/include/stdio_tag.h
O_i86pc/BJackDealer.o: /usr/include/stdio_impl.h /usr/include/iso/stdio_c99.h
O_i86pc/BJackDealer.o: /usr/include/stdlib.h /usr/include/iso/stdlib_iso.h
O_i86pc/BJackDealer.o: /usr/include/iso/stdlib_c99.h /usr/include/assert.h
O_i86pc/BJackDealer.o: AnsiPrint.h Card.h BJackPlayer.h BJackDealer.h
O_i86pc/ConsoleMenu.o: ConsoleMenu.h
O_i86pc/BJackGame.o: AnsiPrint.h Card.h BJackGame.h ConsoleMenu.h
O_i86pc/BJackGame.o: BJackPlayer.h BJackDealer.h
O_i86pc/BJackTest.o: /usr/include/stdio.h /usr/include/sys/feature_tests.h
O_i86pc/BJackTest.o: /usr/include/sys/ccompile.h /usr/include/sys/isa_defs.h
O_i86pc/BJackTest.o: /usr/include/iso/stdio_iso.h /usr/include/sys/va_list.h
O_i86pc/BJackTest.o: /usr/include/stdio_tag.h /usr/include/stdio_impl.h
O_i86pc/BJackTest.o: /usr/include/iso/stdio_c99.h /usr/include/stdlib.h
O_i86pc/BJackTest.o: /usr/include/iso/stdlib_iso.h
O_i86pc/BJackTest.o: /usr/include/iso/stdlib_c99.h /usr/include/assert.h
O_i86pc/BJackTest.o: AnsiPrint.h Card.h ConsoleMenu.h BJackPlayer.h
O_i86pc/BJackTest.o: BJackDealer.h BJackGame.h
