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
		bucket** bucket_;
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

	hashTable::hashTable(index_t n, index_t m, hash_mode_t hm, probe_mode_t pm):
	sz_(n),
	hash_mode_(hm),
	probe_mode_(pm)
	{
		bucket_ = new bucket*[n];
		for(auto &i : bucket_)
			i = new bucket(m);
	}
}

#endif // HASHTABLE