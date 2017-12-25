# Creation notes: https://www.cprogramming.com/tutorial/makefiles.html

# Define required macros here
SHELL = /bin/sh

OBJS =  shapes.o testShapes.o
SHAPES = shapes.h shapes.cpp
TESTSHAPES = testShapes.cpp
CXX = g++
DEBUG = -g
CXXFLAGS = -Wall -c --std=c++11 $(DEBUG)
LFLAGS = -Wall $(DEBUG)
INCLUDES =

build: shapes testshapes ${OBJ}
	${CXX} ${LFLAGS} ${INCLUDES} -o ${OBJS}

shapes: ${SHAPES}
	${CXX} ${CXXFLAGS} ${INCLUDES} ${SHAPES}

testshapes: ${TESTSHAPES}
	${CXX} ${CXXFLAGS} ${INCLUDES} ${TESTSHAPES}

clean:	
	-rm -f *.o *.gch

rebuild: clean build