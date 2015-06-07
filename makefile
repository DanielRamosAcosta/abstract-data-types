#------------------------------------------------------------------------------>

CXX = g++-4.9
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

SINGLYLINKEDLIST = $(INCLUDES)/linkedLists/singlyLinkedList.hpp $(SOURCES)/singlyLinkedList.cpp
SINGLYLINKEDLIST_FILES = $(SOURCES)/$(FILES)

HASHTABLE = $(INCLUDES)/hashTable/hashTable.hpp $(INCLUDES)/utils/common.hpp  $(SOURCES)/hashTable.cpp
HASHTABLE_FILES = $(SOURCES)/$(FILES)

BUCKET = $(INCLUDES)/hashTable/bucket.hpp $(INCLUDES)/utils/common.hpp $(SOURCES)/bucket.cpp
BUCKET_FILES = $(SOURCES)/$(FILES)

HUMAN = $(INCLUDES)/examples/human.hpp $(INCLUDES)/utils/random.hpp $(SOURCES)/human.cpp
HUMAN_FILES = $(SOURCES)/$(FILES)

#----Data-types------------------------------------------------------------>

all: node binaryNode singlyLinkedNode doublyLinkedNode singlyLinkedList

singlyLinkedList: node singlyLinkedNode $(SINGLYLINKEDLIST)
	$(CXX) $(CXXFLAGS) $(SINGLYLINKEDLIST_FILES)

hashTable: $(HASHTABLE)
	$(CXX) $(CXXFLAGS) $(HASHTABLE_FILES)

bucket: $(BUCKET)
	$(CXX) $(CXXFLAGS) $(BUCKET_FILES)

human: $(HUMAN)
	$(CXX) $(CXXFLAGS) $(HUMAN_FILES)

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

