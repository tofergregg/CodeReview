CC=g++
PROG=SequenceDecode
CCFLAGS=-std=c++11 \
  -Wall \
  -Wextra \
  -Wreturn-type \
  -Werror=return-type \
  -Wunreachable-code \
  -Wno-missing-field-initializers \
  -Wno-sign-compare \
  -Wno-write-strings
OBJECTS=$(PROG)/obj/base64.o \
	$(PROG)/obj/basicgraph.o \
	$(PROG)/obj/bitstream.o \
	$(PROG)/obj/call_stack_gcc.o \
	$(PROG)/obj/call_stack_windows.o \
	$(PROG)/obj/console.o \
	$(PROG)/obj/dawglexicon.o \
	$(PROG)/obj/direction.o \
	$(PROG)/obj/error.o \
	$(PROG)/obj/exceptions.o \
	$(PROG)/obj/filelib.o \
	$(PROG)/obj/gbufferedimage.o \
	$(PROG)/obj/gevents.o \
	$(PROG)/obj/gfilechooser.o \
	$(PROG)/obj/ginteractors.o \
	$(PROG)/obj/gmath.o \
	$(PROG)/obj/gobjects.o \
	$(PROG)/obj/goptionpane.o \
	$(PROG)/obj/gtable.o \
	$(PROG)/obj/gtimer.o \
	$(PROG)/obj/gtypes.o \
	$(PROG)/obj/gwindow.o \
	$(PROG)/obj/hashcode.o \
	$(PROG)/obj/lexicon.o \
	$(PROG)/obj/main.o \
	$(PROG)/obj/observable.o \
	$(PROG)/obj/plainconsole.o \
	$(PROG)/obj/platform.o \
	$(PROG)/obj/point.o \
	$(PROG)/obj/random.o \
	$(PROG)/obj/regexpr.o \
	$(PROG)/obj/server.o \
	$(PROG)/obj/shuffle.o \
	$(PROG)/obj/simpio.o \
	$(PROG)/obj/sound.o \
	$(PROG)/obj/startup.o \
	$(PROG)/obj/strlib.o \
	$(PROG)/obj/timer.o \
	$(PROG)/obj/tokenscanner.o \
	$(PROG)/obj/urlstream.o \
	$(PROG)/obj/version.o
all: $(OBJECTS) test_decode 

test_decode: $(OBJECTS) $(PROG)/src/sequence_decode.cpp
	g++ $(CCFLAGS) -g -I$(PROG)/lib/StanfordCPPLib \
	  -I$(PROG)/lib/StanfordCPPLib/stacktrace $(PROG)/obj/*.o \
	  $(PROG)/src/*.cpp -o test_decode -ldl
$(OBJECTS):
	mkdir -p $(PROG)/obj
	cd $(PROG)/obj; \
	g++ $(CCFLAGS) -g -c -I../lib/StanfordCPPLib  -I../lib/StanfordCPPLib/stacktrace ../lib/StanfordCPPLib/stacktrace/*.cpp ../lib/StanfordCPPLib/*.cpp -ldl

clean:
	rm -f test_seq_decode
	rm -f $(PROG)/obj/*.o

