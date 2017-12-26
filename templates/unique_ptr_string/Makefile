# Creation notes: https://www.cprogramming.com/tutorial/makefiles.html

# Define required macros here
SHELL = /bin/sh

FILES = TestString.cpp String.h String.cpp
OUTPUT_NAME = stringTemplate
CXX = g++-4.9
DEBUG = -g
CXXFLAGS = -Wall -std=c++14 $(DEBUG)
LFLAGS = -Wall $(DEBUG)
INCLUDES =

build: ${FILES}
	${CXX} ${CXXFLAGS} ${INCLUDES} -o ${OUTPUT_NAME} ${FILES}

clean:	
	-rm -f *.o *.gch ${OUTPUT_NAME}

rebuild: clean build