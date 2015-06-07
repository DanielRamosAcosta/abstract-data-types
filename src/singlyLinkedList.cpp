#include <iostream>
#include "linkedLists/singlyLinkedList.hpp"

void test1(void);
//void test2(void);

int main(void)
{
	test1();
}

void test1(void)
{
	dra::singlyLinkedList<int> mylist;

	mylist.insert_back(1);
	mylist.insert_back(2);
	mylist.insert_back(3);
	
	mylist.insert_front(4);
	mylist.insert_front(5);

	mylist.toStream(std::cout);
	std::cout << std::endl;

	mylist.extract_front();
	mylist.extract_front();
	mylist.extract_back();

	mylist.toStream(std::cout);
	std::cout << std::endl;
}
/*
void test2(void)
{
	dra::singlyLinkedList<int> mylist;

	mylist.insert_pos(new dra::singlyLinkedNode<int>(1), 0);
	mylist.insert_pos(new dra::singlyLinkedNode<int>(2), 1);
	mylist.insert_pos(new dra::singlyLinkedNode<int>(3), 2);
	mylist.insert_pos(new dra::singlyLinkedNode<int>(4), 3);

	mylist.toStream(std::cout);
	std::cout << std::endl;
}*/