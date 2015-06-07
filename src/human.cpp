#include <iostream>
#include "examples/human.hpp"

int main(void)
{

	dra::human test_subject[10];

	for(auto &i : test_subject){
		std::cout << i << std::endl;
	}
}
