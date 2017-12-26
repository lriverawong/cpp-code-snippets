# Creation notes: https://www.cprogramming.com/tutorial/makefiles.html

# Define required macros here
SHELL = /bin/sh

FILES = myArray.cpp myArray.h testMyArray.cpp
OUTPUT_NAME = myArray
CXX = g++
DEBUG = -g
CXXFLAGS = -Wall --std=c++11 $(DEBUG)
LFLAGS = -Wall $(DEBUG)
INCLUDES =

build: ${FILES}
	${CXX} ${CXXFLAGS} ${INCLUDES} -o ${OUTPUT_NAME} ${FILES}

clean:	
	-rm -f *.o *.gch ${OUTPUT_NAME}

rebuild: clean build