

LIBRARY = -lcppunit
INCLUDE := $(addprefix -I,$(shell find ../src -type d -print)) -I../generated
SOURCES = SimulationTest.cpp OptionsViewTest.cpp TestRunner.cpp
OBJ := $(SOURCES:%.cpp=%.o)

all: runTest

generate := $(shell cd .. && python generator.py && cd tests)

runTest: $(OBJ)
	g++ -g -o runTest $(OBJ) $(LIBRARY) $(INCLUDE)

%.o: %.cpp
	g++ -c -o $@ $< $(LIBRARY) $(INCLUDE)
