CXX=g++
CXXFLAGS=-c -Wall -g
LDFLAGS=
SOURCES = $(wildcard *.cpp)
OBJECTS = ${SOURCES:.cpp=.o}
BLD_DIR := bin/
OBJDIR := objd
TITLE= ass3
ARCHIVE=$(TITLE).tar.gz
PROJECT := SEP


.PHONY : all clean debug valgrind archive

all: $(TITLE)

$(TITLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJECTS)

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean :
	rm -f *.o $(TITLE)

debug : $(TITLE)
	gdb ./$<

valgrind : $(TITLE)
	valgrind --tool=memcheck --leak-check=full ./$<

valgrindbonus : $(TITLE)
	valgrind --tool=memcheck --leak-check=full ./$< Ra1Nb1Bc1Qd1Ke1Bf1Ng1Rh1Pb2Pc2Pd2Pe2Pg2Ph2Pa2Pf2pb7pa7pc7pd7pe7pf7pg7ph7ra8nb8bc8qd8ke8bf8ng8rh8 -b

linecheck: $(SOURCES)
	wc -L $(SOURCES) $(wildcard *.h)
