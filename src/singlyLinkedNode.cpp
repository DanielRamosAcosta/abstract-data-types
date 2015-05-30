#include <iostream>
#include "nodes/singlyLinkedNode.hpp"

int main(void)
{
	dra::singlyLinkedNode<int>* one = new dra::singlyLinkedNode<int>(8);
	dra::singlyLinkedNode<int>* two = new dra::singlyLinkedNode<int>(3);

	one->next() = two;

	delete one;
	delete two;
}
