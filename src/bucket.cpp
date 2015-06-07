#include <iostream>
#include "hashTable/bucket.hpp"
#include "examples/human.hpp"

int main(void)
{
	dra::human test_bench[20];

	dra::bucket<dra::human>* mbucket = new dra::bucket<dra::human>(10);

	mbucket->toStream(std::cout); std::cout << std::endl;

	for(auto &i : test_bench){
		std::cout << "I'm going to insert " << i << std::endl;
		if(mbucket->insert(&i))
			std::cout << "Success insertion!!" << std::endl;
		else
			std::cout << "Bucket overflow!!" << std::endl;
	}

	mbucket->toStream(std::cout); std::cout << std::endl;

	delete mbucket;
}
