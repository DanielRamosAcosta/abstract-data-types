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

vector: $(SOURCES)/vector.cpp $(INCLUDES)/vector.hpp
	$(CXX) $(CXXFLAGS) $(SOURCES)/$(FILES)

queue: $(SOURCES)/queue.cpp $(INCLUDES)/queue.hpp
	$(CXX) $(CXXFLAGS) $(SOURCES)/$(FILES)

stack: $(SOURCES)/stack.cpp $(INCLUDES)/stack.hpp
	$(CXX) $(CXXFLAGS) $(SOURCES)/$(FILES)

simpleLinkedList: $(SOURCES)/simpleLinkedList.cpp $(INCLUDES)/simpleLinkedList.hpp
	$(CXX) $(CXXFLAGS) $(SOURCES)/$(FILES)

doubleLinkedList: $(SOURCES)/doubleLinkedList.cpp $(INCLUDES)/doubleLinkedList.hpp
	$(CXX) $(CXXFLAGS) $(SOURCES)/$(FILES)

binaryTree: $(SOURCES)/binaryTree.cpp $(INCLUDES)/binaryTree.hpp
	$(CXX) $(CXXFLAGS) $(SOURCES)/$(FILES)

binarySearchTree: $(SOURCES)/binarySearchTree.cpp $(INCLUDES)/binarySearchTree.hpp
	$(CXX) $(CXXFLAGS) $(SOURCES)/$(FILES)

#----Nodes----------------------------------------------------------------->

node: $(SOURCES)/node.cpp $(INCLUDES)/node.hpp
	$(CXX) $(CXXFLAGS) $(SOURCES)/$(FILES)

simpleLinkedNode: $(SOURCES)/simpleLinkedNode.cpp $(INCLUDES)/simpleLinkedNode.hpp
	$(CXX) $(CXXFLAGS) $(SOURCES)/$(FILES)

doubleLinkedNode: $(SOURCES)/doubleLinkedNode.cpp $(INCLUDES)/doubleLinkedNode.hpp
	$(CXX) $(CXXFLAGS) $(SOURCES)/$(FILES)

binaryNode: $(SOURCES)/binaryNode.cpp $(INCLUDES)/binaryNode.hpp
	$(CXX) $(CXXFLAGS) $(SOURCES)/$(FILES)

#----Utlities-------------------------------------------------------------->

random: $(SOURCES)/random.cpp $(INCLUDES)/random.hpp
	$(CXX) $(CXXFLAGS) $(SOURCES)/$(FILES)

exceptions: $(SOURCES)/exceptions.cpp $(INCLUDES)/exceptions.hpp
	$(CXX) $(CXXFLAGS) $(SOURCES)/$(FILES)

#----Tools----------------------------------------------------------------->

clean:
	$(RM) bin/*

