#------------------------------------------------------------------------------>

CXX = g++

CXXFLAGS = -std=c++11 -Wall -o $(BINARIES)/$@

INCLUDES = inc
SOURCES = src
DOCUMENTATION = docs
BINARIES = bin

FILES = main.cpp

RM = rm -f

#----Data-types------------------------------------------------------------>

vector: $(SOURCES)/vector/$(FILES) $(INCLUDES)/vector/vector.h
	$(CXX) $(CXXFLAGS) $(SOURCES)/$@/$(FILES)

queue: $(SOURCES)/queue/$(FILES) $(INCLUDES)/queue/queue.h
	$(CXX) $(CXXFLAGS) $(SOURCES)/$@/$(FILES)

stack: $(SOURCES)/stack/$(FILES) $(INCLUDES)/stack/stack.h
	$(CXX) $(CXXFLAGS) $(SOURCES)/$@/$(FILES)

simpleLinkedList: $(SOURCES)/simpleLinkedList/$(FILES) $(INCLUDES)/simpleLinkedList/simpleLinkedList.h
	$(CXX) $(CXXFLAGS) $(SOURCES)/$@/$(FILES)

doubleLinkedList: $(SOURCES)/doubleLinkedList/$(FILES) $(INCLUDES)/doubleLinkedList/doubleLinkedList.h
	$(CXX) $(CXXFLAGS) $(SOURCES)/$@/$(FILES)

binaryTree: $(SOURCES)/binaryTree/$(FILES) $(INCLUDES)/binaryTree/binaryTree.h
	$(CXX) $(CXXFLAGS) $(SOURCES)/$@/$(FILES)

binarySearchTree: $(SOURCES)/binarySearchTree/$(FILES) $(INCLUDES)/binarySearchTree/binarySearchTree.h
	$(CXX) $(CXXFLAGS) $(SOURCES)/$@/$(FILES)

#----Nodes----------------------------------------------------------------->

node: $(SOURCES)/node/$(FILES) $(INCLUDES)/node/node.h
	$(CXX) $(CXXFLAGS) $(SOURCES)/$@/$(FILES)

simpleLinkedNode: $(SOURCES)/simpleLinkedNode/$(FILES) $(INCLUDES)/simpleLinkedNode/simpleLinkedNode.h
	$(CXX) $(CXXFLAGS) $(SOURCES)/$@/$(FILES)

doubleLinkedNode: $(SOURCES)/doubleLinkedNode/$(FILES) $(INCLUDES)/doubleLinkedNode/doubleLinkedNode.h
	$(CXX) $(CXXFLAGS) $(SOURCES)/$@/$(FILES)

binaryNode: $(SOURCES)/binaryNode/$(FILES) $(INCLUDES)/binaryNode/binaryNode.h
	$(CXX) $(CXXFLAGS) $(SOURCES)/$@/$(FILES)

#----Utlities-------------------------------------------------------------->

random: $(SOURCES)/random/$(FILES) $(INCLUDES)/random/random.h
	$(CXX) $(CXXFLAGS) $(SOURCES)/$@/$(FILES)

exceptions: $(SOURCES)/exceptions/$(FILES) $(INCLUDES)/exceptions/exceptions.h
	$(CXX) $(CXXFLAGS) $(SOURCES)/$@/$(FILES)

#----Tools----------------------------------------------------------------->

clean:
	$(RM) bin/*
