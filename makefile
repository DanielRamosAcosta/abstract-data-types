#------------------------------------------------------------------------------>

CXX = g++-4.9
CXXFLAGS = -std=c++11 -Wall -I $(INCLUDES) -o $(BIN) -fdiagnostics-color=always

INCLUDES = include
SOURCES = src
DOCUMENTATION = docs
BIN = bin/$@

FILES = $@.cpp

RM = rm -f

#----Data-dependencies--------------------------------------------------------->

NODE = $(INCLUDES)/nodes/node.hpp $(SOURCES)/node.cpp

BINARYNODE = $(INCLUDES)/nodes/binaryNode.hpp $(SOURCES)/binaryNode.cpp

SINGLYLINKEDNODE = $(INCLUDES)/nodes/singlyLinkedNode.hpp $(SOURCES)/singlyLinkedNode.cpp

DOUBLYLINKEDNODE = $(INCLUDES)/nodes/doublyLinkedNode.hpp $(SOURCES)/doublyLinkedNode.cpp

SINGLYLINKEDLIST = $(INCLUDES)/linkedLists/singlyLinkedList.hpp $(SOURCES)/singlyLinkedList.cpp

HASHTABLE = $(INCLUDES)/hashTable/hashTable.hpp $(INCLUDES)/utils/common.hpp  $(SOURCES)/hashTable.cpp

BUCKET = $(INCLUDES)/hashTable/bucket.hpp $(INCLUDES)/utils/common.hpp $(SOURCES)/bucket.cpp

HUMAN = $(INCLUDES)/examples/human.hpp $(INCLUDES)/utils/random.hpp $(SOURCES)/human.cpp

#----Data-types-(main-stuff)--------------------------------------------------->

all: singlyLinkedList hashTable

singlyLinkedList: node singlyLinkedNode $(SINGLYLINKEDLIST)
	$(CXX) $(CXXFLAGS) $(SOURCES)/$(FILES)

hashTable: bucket $(HASHTABLE)
	$(CXX) $(CXXFLAGS) $(SOURCES)/$(FILES)

#----Nodes--------------------------------------------------------------------->

node: $(NODE)
	$(CXX) $(CXXFLAGS) $(SOURCES)/$(FILES)

binaryNode: node $(BINARYNODE)
	$(CXX) $(CXXFLAGS) $(SOURCES)/$(FILES)

singlyLinkedNode: node $(SINGLYLINKEDNODE)
	$(CXX) $(CXXFLAGS) $(SOURCES)/$(FILES)

doublyLinkedNode: node $(DOUBLYLINKEDNODE)
	$(CXX) $(CXXFLAGS) $(SOURCES)/$(FILES)

#----Utlities------------------------------------------------------------------>

bucket: human $(BUCKET)
	$(CXX) $(CXXFLAGS) $(SOURCES)/$(FILES)

human: $(HUMAN)
	$(CXX) $(CXXFLAGS) $(SOURCES)/$(FILES)

#----Tools--------------------------------------------------------------------->

clean:
	$(RM) bin/*

