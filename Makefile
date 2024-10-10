CXX = g++
CXXFLAGS = -g -std=c++11
INCFLAGS = $(addprefix -I,$(INCL))

SRC = .
OBJ = obj
INCL = .
SRCS = $(wildcard $(SRC)/*.cpp)
OBJS = $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))

BIN = app
ARCHIVE = $(BIN).tar.gz
PROJECT = SEP

DEPS = $(OBJS:.o=.d)
DEPFLAGS = -MMD -MP

.PHONY: all clean debug valgrind valgrindbonus archive linecheck

all: $(BIN)

debug: CXXFLAGS += -g
debug: $(BIN)

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

-include $(DEPS)

$(OBJ)/%.o: $(SRC)/%.cpp | $(OBJ)
	$(CXX) $(CXXFLAGS) $(INCFLAGS) $(DEPFLAGS) -c $< -o $@

$(OBJ)/%.d: $(SRC)/%.cpp | $(OBJ)
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -MM -MT "$(OBJ)/$(<:.cpp=.o) $(OBJ)/$(<:.cpp=.d)" $< > $@

$(OBJ):
	mkdir -p $@

clean:
	rm -rf $(OBJ)/* $(BIN)

valgrind: $(BIN)
	valgrind --tool=memcheck --leak-check=full ./$(BIN)

valgrindbonus: $(BIN)
	valgrind --tool=memcheck --leak-check=full ./$(BIN) Ra1Nb1Bc1Qd1Ke1Bf1Ng1Rh1Pb2Pc2Pd2Pe2Pg2Ph2Pa2Pf2pb7pa7pc7pd7pe7pf7pg7ph7ra8nb8bc8qd8ke8bf8ng8rh8 -b

archive:
	tar -czvf $(ARCHIVE) $(SRCS) $(wildcard *.h) Makefile

linecheck: $(SRCS)
	wc -L $(SRCS) $(wildcard *.h)
