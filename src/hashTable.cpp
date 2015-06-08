#include <iostream>
#include "hashTable/hashTable.hpp"
#include "key/keyHumanDNI.hpp"

int main(void)
{
	//std::cout << "Hello World" << std::endl;

	dra::hashTable test_table(10, 3, 0, 0); //10x3 table with hash=module probe=linear probing

	dra::human subject[31];

	system("clear");

	for(auto &i : subject){
		test_table.insert(new dra::keyHumanDNI(&i));
		test_table.toStream(std::cout);
		sleep(1);
		system("clear");
	}

	test_table.toStream(std::cout);

}
