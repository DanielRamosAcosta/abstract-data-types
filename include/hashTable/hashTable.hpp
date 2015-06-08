#ifndef HASHTABLE
#define HASHTABLE

#include <iostream>

#include <utils/common.hpp>
#include <hashTable/bucket.hpp>
#include <utils/exceptions.hpp>

#define HASH_MODULE 0
#define HASH_PLUS 1
#define HASH_PSEUDORANDOM 2

#define LINEAR_PROBING 0

namespace dra{

	class hashTable
	{
	private:
		bucket** bucket_;
		size_t sz_;

		hash_mode_t hash_mode_;
		probe_mode_t probe_mode_;
	public:
		hashTable(index_t, index_t, hash_mode_t, probe_mode_t);
		~hashTable(void);

		void insert(key*);
		index_t probe(key*);

		std::ostream& toStream(std::ostream&);
	private:
		index_t hash(key*);
		index_t hashModule(key*);
		index_t hashPlus(key*);
		index_t hashPseudoRandom(key*);

		index_t linearProbing(key*);
	};

	hashTable::hashTable(index_t n, index_t m, hash_mode_t hm, probe_mode_t pm):
	sz_(n),
	hash_mode_(hm),
	probe_mode_(pm)
	{
		bucket_ = new bucket*[n];
		for(unsigned i = 0; i < sz_; i++)
			bucket_[i] = new bucket(m);
	}

	hashTable::~hashTable(void)
	{
		for(unsigned i = 0; i < sz_; i++){
			if(bucket_[i] != nullptr){
				delete bucket_[i];
				bucket_[i] = nullptr;
			}
		}
		delete[] bucket_;
	}

	void hashTable::insert(key* mkey)
	{
		index_t place = hash(mkey);

		if(!bucket_[place]->insert(mkey)){
			#ifdef _DEBUG
				std::clog << "Can't insert in the bucket #" << place << " (it's full)!" << std::endl;
			#endif //_DEBUG
			place = probe(mkey);

			bucket_[place]->insert(mkey);
			std::clog << "I found other place in bucket #" << place << std::endl;
		}
		else
			std::clog << "Inserted correctly in bucket #" << place << std::endl;
	}

	index_t hashTable::probe(key* mkey)
	{
		switch(probe_mode_){
			case LINEAR_PROBING: return linearProbing(mkey);
		}
		return -1; //TODO: Throw exception
	}

	index_t hashTable::hash(key* mkey)
	{
		switch(hash_mode_){
			case HASH_MODULE: return hashModule(mkey);
		}
		return -1; //TODO: Throw exception
	}

	index_t hashTable::hashModule(key* mkey)
	{
		//std::clog << "Module hashing..." << std::endl;
		return mkey->value() % sz_;
	}

	index_t hashTable::linearProbing(key* mkey)
	{
		unsigned i = 1;

		index_t seek;

		while(true)
		{
			if(i > sz_) //all buckets where checked with no luck
				break;

			seek = (hash(mkey) + i) % sz_;

			if(!bucket_[seek]->full())
				return seek;
			i++;
		}
		throw exception::overflow_error(sz_); //TODO: Throw exception
	}

	std::ostream& hashTable::toStream(std::ostream& os)
	{
		os << "================" << std::endl;
		for(unsigned i = 0; i < sz_; i++){
			bucket_[i]->toStream(os);
			os << "================" << std::endl;
		}
		return os;
	}
}

#endif // HASHTABLE