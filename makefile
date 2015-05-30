#------------------------------------------------------------------------------>

CXX = g++
CXXFLAGS = -std=c++11 -Wall -I $(INCLUDES) -o $(BIN)

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

SINGLYLINKEDNODE = $(INCLUDES)/nodes/singlyLinkedNode.hpp $(SOURCES)/singlyLinkedNode.cpp
SINGLYLINKEDNODE_FILES = $(SOURCES)/$(FILES)

DOUBLYLINKEDNODE = $(INCLUDES)/nodes/doublyLinkedNode.hpp $(SOURCES)/doublyLinkedNode.cpp
DOUBLYLINKEDNODE_FILES = $(SOURCES)/$(FILES)

#----Data-types------------------------------------------------------------>

all: node binaryNode singlyLinkedNode doublyLinkedNode

#----Nodes----------------------------------------------------------------->

node: $(NODE)
	$(CXX) $(CXXFLAGS) $(NODE_FILES)

binaryNode: node $(BINARYNODE)
	$(CXX) $(CXXFLAGS) $(BINARYNODE_FILES)

singlyLinkedNode: node $(SINGLYLINKEDNODE)
	$(CXX) $(CXXFLAGS) $(SINGLYLINKEDNODE_FILES)

doublyLinkedNode: node $(DOUBLYLINKEDNODE)
	$(CXX) $(CXXFLAGS) $(DOUBLYLINKEDNODE_FILES)
	

#----Utlities-------------------------------------------------------------->

#WIP

#----Tools----------------------------------------------------------------->

clean:
	$(RM) bin/*

