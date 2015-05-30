#include <iostream>
#include "nodes/doublyLinkedNode.hpp"

int main(void)
{
	dra::doublyLinkedNode<int>* one = new dra::doublyLinkedNode<int>(4);
	dra::doublyLinkedNode<int>* two = new dra::doublyLinkedNode<int>(9);

	one->next() = two;
	two->prev() = one;

	delete one;
	delete two;
}