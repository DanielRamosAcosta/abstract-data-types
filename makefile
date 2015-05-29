#------------------------------------------------------------------------------>

CXX = g++
CXXFLAGS = -std=c++11 -Wall -o $(BIN) -I $(INCLUDES)

INCLUDES = include
SOURCES = src
DOCUMENTATION = docs
BIN = bin/$@

FILES = $@.cpp

RM = rm -f

#----Data-dependencies----------------------------------------------------->

NODE = $(INCLUDES)/nodes/node.hpp $(SOURCES)/node.cpp
NODE_FILES = $(SOURCES)/$(FILES)

BINARYNODE = $(INCLUDES)/nodes/binaryNode.hpp $(SOURCES)/binaryNode.cpp
BINARYNODE_FILES = $(SOURCES)/$(FILES)

#----Data-types------------------------------------------------------------>

all: node binaryNode

#----Nodes----------------------------------------------------------------->

node: $(NODE)
	$(CXX) $(CXXFLAGS) $(NODE_FILES)

binaryNode: node $(BINARYNODE)
	$(CXX) $(CXXFLAGS) $(BINARYNODE_FILES)
	

#----Utlities-------------------------------------------------------------->

#WIP

#----Tools----------------------------------------------------------------->

clean:
	$(RM) bin/*

