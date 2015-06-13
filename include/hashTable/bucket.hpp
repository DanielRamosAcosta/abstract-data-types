#ifndef BUCKET
#define BUCKET

#include <iostream>

#include "utils/common.hpp"

#include "key/key.hpp"

namespace dra{
	class bucket
	{
	private:
		key** cell_;
		size_t sz_;
	public:
		bucket(size_t);
		~bucket(void);

		bool insert(key*);
		bool search(key*);

		bool full(void);
		bool empty(void);

		std::ostream& toStream(std::ostream&);
	};

	bucket::bucket(size_t sz):
	sz_(sz)
	{
		cell_ = new key*[sz_];
		for(unsigned i = 0; i < sz_; i++)
			cell_[i] = nullptr;
	}

	bucket::~bucket(void)
	{
		for(unsigned i = 0; i < sz_; i++){
			if(cell_[i] != nullptr){
				delete cell_[i];
				cell_[i] = nullptr;
			}
		}
		delete[] cell_;

	}

	bool bucket::insert(key* mkey)
	{
		for(size_t i = 0; i < sz_; i++){
        	if(cell_[i] == nullptr){
            	cell_[i] = mkey;
            	return true;
        	}
    	}
    	return false;
	}

	bool bucket::search(key* mkey)
	{
		for(size_t i = 0; i < sz_; i++){
			if(cell_[i] == mkey)
				return true;
			else if(cell_[i] == nullptr)
				return false;
		}
		return false;
	}

	bool bucket::full(void)
	{
		return cell_[sz_-1] != nullptr;
	}

	bool bucket::empty(void)
	{
		return cell_[0] == nullptr;
	}

	std::ostream& bucket::toStream(std::ostream& os)
	{
		for(size_t i = 0; i < sz_; i++){
			if(cell_[i] == nullptr)
				os << "NULL" << std::endl;
			else
				os << cell_[i] << std::endl;
		}
		return os;
	}
}

#endif // BUCKET
