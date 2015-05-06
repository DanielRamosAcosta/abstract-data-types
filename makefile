#------------------------------------------------------------------------------>

CXX = g++

CXXFLAGS = -std=c++11 -Wall -o $(BINARIES)/$@

INCLUDES = include
SOURCES = src
DOCUMENTATION = docs
BINARIES = bin

FILES = $@.cpp

RM = rm -f

#----Data-types------------------------------------------------------------>

#WIP

#----Nodes----------------------------------------------------------------->

node: $(INCLUDES)/nodes/node.hpp $(SOURCES)/node.cpp
	$(CXX) $(CXXFLAGS) $(SOURCES)/$@.cpp
	

#----Utlities-------------------------------------------------------------->

#WIP

#----Tools----------------------------------------------------------------->

clean:
	$(RM) bin/*

