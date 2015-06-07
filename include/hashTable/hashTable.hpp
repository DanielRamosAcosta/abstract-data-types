#ifndef HASHTABLE
#define HASHTABLE

#include <iostream>

#include <utils/common.hpp>
#include <hashTable/bucket.hpp>

#define HASH_MODULE
#define HASH_PLUS
#define HASH_PSEUDORANDOM

namespace dra{

	template<class T>
	class hashTable
	{
	private:
		bucket<T>* bucket_;
		size_t sz_;

		unsigned hash_mode_;
		unsigned probe_mode_;

	public:
		hashTable();
		~hashTable();

	};

}

#endif // HASHTABLE