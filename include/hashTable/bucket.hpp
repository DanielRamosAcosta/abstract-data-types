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

		std::ostream& toStream(std::ostream&);
	};

	bucket::bucket(size_t sz):
	sz_(sz)
	{
		cell_ = new key*[sz_];
	}

	bucket::~bucket(void)
	{
		if(cell_ != nullptr)
			delete[] cell_;
	}

	bool bucket::insert(key* record)
	{
		for(size_t i = 0; i < sz_; i++){
        	if(cell_[i] == nullptr){
            	cell_[i] = record;
            	return true;
        	}
    	}
    	return false;
	}

	bool bucket::search(key* record)
	{
		for(size_t i = 0; i < sz_; i++){
			if(cell_[i] == record)
				return true;
			else if(cell_[i] == nullptr)
				return false;
		}
		return false;
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
