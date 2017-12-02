
generate := $(shell cd .. && python generator.py && cd tests)

FLAGS = -DLIN -DNOMAIN
LIBRARY = -lcppunit -lpthread -lbz2
INCLUDE := -I/usr/include -I/usr/include/SDL -I/usr/include/lua5.1 -I../generated -I../data \
$(addprefix -I,$(shell find ../src -type d -print))

#Dependencies

S1  := $(shell find ../src/bson -type f -iname '*.cpp')
S2  := $(shell find ../src/client -type f -iname '*.cpp')
S3  := $(shell find ../src/graphics -type f -iname '*.cpp')
S4  := $(shell find ../src/gui -type f -iname '*.cpp')
S5  := $(shell find ../src/json -type f -iname '*.cpp')
S6  := $(shell find ../src/lua -type f -iname '*.cpp')
S7  := $(shell find ../generated -type f -iname '*.cpp')
S8  := $(shell find ../src/simulation -type f -iname '*.cpp')
S9   = ../src/Format.cpp ../src/Misc.cpp ../src/Platform.cpp \
       ../src/PowderToyRenderer.cpp ../src/Probability.cpp \
       ../src/PowderToySDL.cpp
S10 := $(shell find ../src/debug -type f -iname '*.cpp')
S11 := $(shell find ../src/tasks -type f -iname '*.cpp')
S12 := $(shell find ../src/lua -type f -iname '*.cpp')

#Testing source code
SOURCES = SimulationTest.cpp OptionsViewTest.cpp TestRunner.cpp
SOURCES += $(S1) $(S2) $(S3) $(S4) $(S5) $(S6) $(S7) $(S8) $(S9) $(S10) $(S11) $(S12)

OBJ := $(SOURCES:%.cpp=%.o)

all: runTest

runTest: $(OBJ)
	g++ -g -o runTest $(OBJ) $(LIBRARY) $(INCLUDE) $(FLAGS)

%.o: %.cpp
	g++ -c -o $@ $< $(LIBRARY) $(INCLUDE) $(FLAGS)

clean:
	rm -f $(OBJ)
c: clean
