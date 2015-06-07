#ifndef KEYHUMANDNI
#define KEYHUMANDNI

#include "utils/common.hpp"
#include "key/keyHuman.hpp"
#include "examples/human.hpp"

namespace dra{
	class keyHumanDNI : public keyHuman{
	public:
		keyHumanDNI(human*);
		virtual ~keyHumanDNI();
	private:
		virtual void generate(void);
	};

	keyHumanDNI::keyHumanDNI(human* h):
	keyHuman(h)
	{
		generate();
	}

	keyHumanDNI::~keyHumanDNI(void)
	{}

	void keyHumanDNI::generate(void)
	{
		key_ = human_ptr_->dni();
	}
}

#endif // KEYHUMANDNI