#ifndef HASHTABLE
#define HASHTABLE

#include <iostream>

#include <utils/common.hpp>
#include <hashTable/bucket.hpp>
#include <utils/exceptions.hpp>

#ifdef _DEBUG
	#include <unistd.h>
#endif // _DEBUG

#define HASH_MODULE 0
#define HASH_PLUS 1
#define HASH_PSEUDORANDOM 2

#define PROBE_LINEAR 0
#define PROBE_QUADRATIC 1
#define PROBE_DOUBLE_HASHING 2
#define PROBE_REHASHING 3

#define STOP_LIMIT 256
#define DOUBLE_HASHING_CONSTANT 7

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
		bool search(key*);

		std::ostream& toStream(std::ostream&);
	private:
		index_t hash(key*);
		index_t hashModule(key*);
		index_t hashPlus(key*);
		index_t hashPseudoRandom(key*);

		index_t probe(key*, unsigned);
		index_t probeLinear(key*, unsigned);
		index_t probeQuadratic(key*, unsigned);
		index_t probeDoubleHashing(key*, unsigned);
		index_t probeReHashing(key*, unsigned);
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
			std::clog << "I couldn't insert it in the bucket #" << place << std::endl;
			for(unsigned i = 1; bucket_[place]->full(); i++){
				place = probe(mkey, i);
				std::clog << "Let's check bucket #" << place << std::endl;
			}

			bucket_[place]->insert(mkey);
			std::clog << "I found other place in bucket #" << place << std::endl;
		}
		else
			std::clog << "Inserted correctly in bucket #" << place << std::endl;
	}

	bool hashTable::search(key* mkey)
	{
		index_t place = hash(mkey);

		if(!bucket_[place]->search(mkey)){
			std::clog << "I didn't found the key in the bucket #" << place << std::endl;
			for(unsigned i = 1; bucket_[place]->search(mkey); i++){
				place = probe(mkey, i);
				std::clog << "Let's check bucket #" << place << std::endl;
			}
			std::cout << "I finally found it in the bucket #" << place << std::endl;
			return true;
		}
		else{
			std::cout << "I found it in the bucket #" << place << std::endl;
			return true;
		}
	}

	index_t hashTable::probe(key* mkey, unsigned i)
	{
		switch(probe_mode_){
			case PROBE_LINEAR:			return probeLinear(mkey, i); break;
			case PROBE_QUADRATIC:		return probeQuadratic(mkey, i); break;
			case PROBE_DOUBLE_HASHING:	return probeDoubleHashing(mkey, i); break;
			case PROBE_REHASHING:		return probeReHashing(mkey, i); break;
		}
		throw exception::bad_usage_error("Bad probe number code");
	}

	index_t hashTable::hash(key* mkey)
	{
		switch(hash_mode_){
			case HASH_MODULE:		return hashModule(mkey); break;
			case HASH_PLUS:			return hashPlus(mkey); break;
			case HASH_PSEUDORANDOM:	return hashPseudoRandom(mkey); break;
		}
		throw exception::bad_usage_error("Bad hash number code");
	}

	index_t hashTable::hashModule(key* mkey)
	{
		return mkey->value() % sz_;
	}

	index_t hashTable::hashPlus(key* mkey)
	{
		unsigned aux = mkey->value();
		unsigned sum = 0;
		while(aux != 0)
		{
			unsigned reminder = aux % 10;
			sum += reminder;
			aux /= 10;
		}
		return sum % sz_;
	}
	
	index_t hashTable::hashPseudoRandom(key* mkey)
	{
		srand(mkey->value());
		return rand() % sz_;
	}

	index_t hashTable::probeLinear(key* mkey, unsigned i)
	{
		if(i > sz_)
			throw exception::overflow_error(sz_);
		return (hash(mkey) + i) % sz_;
	}

	index_t hashTable::probeQuadratic(key* mkey, unsigned i)
	{
		if(i > (sz_/2)) //quadratic probing won't check all buckets: http://en.wikipedia.org/wiki/Quadratic_probing#Limitations
			throw exception::overflow_error("Passed sz_/2 value in probing");
		return (hash(mkey) + (i*i)) % sz_;
	}

	index_t hashTable::probeDoubleHashing(key* mkey, unsigned i)
	{
		if(i > STOP_LIMIT)
			throw exception::overflow_error("Passed STOP_LIMIT value in probing");
		return (hash(mkey) + i * ((mkey->value() % DOUBLE_HASHING_CONSTANT)+1)) % sz_;
	}

	index_t hashTable::probeReHashing(key* mkey, unsigned i)
	{
		hash_mode_t aux = hash_mode_; //save hashing mode

		hash_mode_ = i -1; //set the hash function to the iteration number

		index_t place;

		try{
			place = hash(mkey); //catch if it is the last function
		}
		catch(...){
			throw exception::overflow_error("Reached hash types limit");
		}

		hash_mode_ = aux;
		return place;
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