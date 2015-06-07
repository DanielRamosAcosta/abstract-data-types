#ifndef HASHTABLE
#define HASHTABLE

#include <iostream>

#include <utils/common.hpp>
#include <hashTable/bucket.hpp>

#define HASH_MODULE
#define HASH_PLUS
#define HASH_PSEUDORANDOM

namespace dra{

	class hashTable
	{
	private:
		bucket* bucket_;
		size_t sz_;

		hash_mode_t hash_mode_;
		probe_mode_t probe_mode_;
	private:
		index_t hash(key*);
		index_t hashModule(key*);
		index_t hashPlus(key*);
		index_t hashPseudoRandom(key*);

	public:
		hashTable(index_t, index_t, hash_mode_t, probe_mode_t);
		~hashTable(void);

		void insert(key*);
		void probe(key*);
	};
}

#endif // HASHTABLE