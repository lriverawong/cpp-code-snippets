# Creation notes: https://www.cprogramming.com/tutorial/makefiles.html

# Define required macros here
SHELL = /bin/sh

FILES = testSafeArray.cpp safeArray.cpp safeArray.h 
OUTPUT_NAME = safeArray
CXX = g++
DEBUG = -g
CXXFLAGS = -Wall --std=c++11 $(DEBUG)
LFLAGS = -Wall $(DEBUG)
INCLUDES =

build: ${FILES}
	${CXX} ${CXXFLAGS} ${INCLUDES} -o ${OUTPUT_NAME} ${FILES}

clean:	
	-rm -f *.o *.gch safeArray

rebuild: clean build