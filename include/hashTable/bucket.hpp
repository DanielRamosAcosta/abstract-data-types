#ifndef BUCKET
#define BUCKET

#include <iostream>

#include <utils/common.hpp>

namespace dra{

	template<class T>
	class bucket
	{
	private:
		T** cell_;
		size_t sz_;
	public:
		bucket(size_t);
		~bucket(void);

		bool insert(T*);
		bool search(T*);

		std::ostream& toStream(std::ostream&);
	};

	template<class T>
	bucket<T>::bucket(size_t sz):
	sz_(sz)
	{
		cell_ = new T*[sz_];
	}

	template<class T>
	bucket<T>::~bucket(void)
	{
		if(cell_ == nullptr)
			return;

		for(size_t i = 0; i < sz_; i++)
			if( cell_[i] != nullptr)
				delete cell_[i];
			else
				break;

		delete[] cell_;
	}

	template<class T>
	bool bucket<T>::insert(T* record)
	{
		for(size_t i = 0; i < sz_; i++){
        	if(cell_[i] == nullptr){
            	cell_[i] = record;
            	return true;
        	}
    	}
    	return false;
	}

	template<class T>
	bool bucket<T>::search(T* record)
	{
		for(size_t i = 0; i < sz_; i++){
			if(cell_[i] == record)
				return true;
			else if(cell_[i] == nullptr)
				return false;
		}
		return false;
	}

	template<class T>
	std::ostream& bucket<T>::toStream(std::ostream& os)
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
