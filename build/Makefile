# user should pass in PROG
# e.g., make PROG="tempdir/program_name"
# PROG should not have the .cpp extension
CC=g++
STANFORD_LIB=StanfordLib
CCFLAGS=-std=c++11 \
  -Wall \
  -Wextra \
  -Wreturn-type \
  -Werror=return-type \
  -Wunreachable-code \
  -Wno-missing-field-initializers \
  -Wno-sign-compare \
  -Wno-write-strings
OBJECTS=$(STANFORD_LIB)/obj/base64.o \
	$(STANFORD_LIB)/obj/basicgraph.o \
	$(STANFORD_LIB)/obj/bitstream.o \
	$(STANFORD_LIB)/obj/call_stack_gcc.o \
	$(STANFORD_LIB)/obj/call_stack_windows.o \
	$(STANFORD_LIB)/obj/console.o \
	$(STANFORD_LIB)/obj/dawglexicon.o \
	$(STANFORD_LIB)/obj/direction.o \
	$(STANFORD_LIB)/obj/error.o \
	$(STANFORD_LIB)/obj/exceptions.o \
	$(STANFORD_LIB)/obj/filelib.o \
	$(STANFORD_LIB)/obj/gbufferedimage.o \
	$(STANFORD_LIB)/obj/gevents.o \
	$(STANFORD_LIB)/obj/gfilechooser.o \
	$(STANFORD_LIB)/obj/ginteractors.o \
	$(STANFORD_LIB)/obj/gmath.o \
	$(STANFORD_LIB)/obj/gobjects.o \
	$(STANFORD_LIB)/obj/goptionpane.o \
	$(STANFORD_LIB)/obj/gtable.o \
	$(STANFORD_LIB)/obj/gtimer.o \
	$(STANFORD_LIB)/obj/gtypes.o \
	$(STANFORD_LIB)/obj/gwindow.o \
	$(STANFORD_LIB)/obj/hashcode.o \
	$(STANFORD_LIB)/obj/lexicon.o \
	$(STANFORD_LIB)/obj/main.o \
	$(STANFORD_LIB)/obj/observable.o \
	$(STANFORD_LIB)/obj/plainconsole.o \
	$(STANFORD_LIB)/obj/platform.o \
	$(STANFORD_LIB)/obj/point.o \
	$(STANFORD_LIB)/obj/random.o \
	$(STANFORD_LIB)/obj/regexpr.o \
	$(STANFORD_LIB)/obj/server.o \
	$(STANFORD_LIB)/obj/shuffle.o \
	$(STANFORD_LIB)/obj/simpio.o \
	$(STANFORD_LIB)/obj/sound.o \
	$(STANFORD_LIB)/obj/startup.o \
	$(STANFORD_LIB)/obj/strlib.o \
	$(STANFORD_LIB)/obj/timer.o \
	$(STANFORD_LIB)/obj/tokenscanner.o \
	$(STANFORD_LIB)/obj/urlstream.o \
	$(STANFORD_LIB)/obj/version.o
all: $(OBJECTS) $(PROG) 

$(PROG): $(OBJECTS) $(PROG).cpp
	g++ $(CCFLAGS) -g -I$(STANFORD_LIB)/lib/StanfordCPPLib \
	  -I$(STANFORD_LIB)/lib/StanfordCPPLib/stacktrace $(STANFORD_LIB)/obj/*.o \
	  $(PROG).cpp -o $(PROG) -ldl
$(OBJECTS):
	mkdir -p $(STANFORD_LIB)/obj
	cd $(STANFORD_LIB)/obj; \
	g++ $(CCFLAGS) -g -c -I../lib/StanfordCPPLib  -I../lib/StanfordCPPLib/stacktrace ../lib/StanfordCPPLib/stacktrace/*.cpp ../lib/StanfordCPPLib/*.cpp -ldl

clean:
	rm -f $(PROG) 
	rm -f $(STANFORD_LIB)/obj/*.o

