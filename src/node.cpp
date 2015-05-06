#include <iostream>
#include "../include/nodes/node.hpp"

int main(void)
{
	dra::node<int> dummy;

	dummy.data() = 8;

	std::cout << "Data is set in the node, I feel so dumb" << std::endl;
}
