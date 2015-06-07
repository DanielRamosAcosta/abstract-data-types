#ifndef KEY
#define KEY

#include <iostream>

#include "utils/common.hpp"

namespace dra{
	class key{
	protected:
		index_t key_;
	public:
		key(void);
		virtual ~key(void);

		index_t value(void) const;

		virtual std::ostream& toStream(std::ostream&)=0;
	protected:
		virtual void generate(void)=0;
	};

	key::key(void):
	key_(UNINITIALIZED_INDEX)
	{}

	key::~key(void)
	{}

	index_t key::value(void) const
	{
		return key_;
	}

	std::ostream& operator<<(std::ostream& os, key* key_ptr)
	{
   		key_ptr->toStream(os);
    	return os;
	}
}

#endif // KEY