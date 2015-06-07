#include <iostream>
#include "examples/human.hpp"

int main(void)
{
	std::cout << "Hello World" << std::endl;

	dra::human test_subject[10];

	for(auto &i : test_subject){
		i.toStream(std::cout);
		std::cout << std::endl;
	}
}
