#ifndef KEYHUMAN
#define KEYHUMAN

#include <iostream>

#include "utils/common.hpp"
#include "key/key.hpp"
#include "examples/human.hpp"


namespace dra{
	class keyHuman : public key{
	protected:
		human* human_ptr_;
	public:
		keyHuman(void);
		keyHuman(human*);
		virtual ~keyHuman(void);
		virtual std::ostream& toStream(std::ostream&);
	};

	keyHuman::keyHuman(void):
	human_ptr_(nullptr)
	{}

	keyHuman::keyHuman(human* h):
	human_ptr_(h)
	{}

	keyHuman::~keyHuman(void)
	{}

	std::ostream& keyHuman::toStream(std::ostream& os)
	{
		return human_ptr_->toStream(os);
	}

}

#endif // KEY