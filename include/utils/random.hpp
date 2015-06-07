#ifndef RANDOM
#define RANDOM

#include <ctime>
#include <unistd.h>
#include <cstdlib>

namespace dra{

	template<class T>
	class random{
	private:
		static T mix(T a, T b, T c);
	public:
		static T rand(void);
	};

	template<class T>
	T random<T>::mix(T a, T b, T c)
	{
		a=a-b;  a=a-c;  a=a^(c >> 13);
		b=b-c;  b=b-a;  b=b^(a << 8);
		c=c-a;  c=c-b;  c=c^(b >> 13);
		a=a-b;  a=a-c;  a=a^(c >> 12);
		b=b-c;  b=b-a;  b=b^(a << 16);
		c=c-a;  c=c-b;  c=c^(b >> 5);
		a=a-b;  a=a-c;  a=a^(c >> 3);
		b=b-c;  b=b-a;  b=b^(a << 10);
		c=c-a;  c=c-b;  c=c^(b >> 15);
		return c;
	}

	template<class T>
	T random<T>::rand(void)
	{
		return mix(clock(), time(NULL), getpid());
	}
}

#endif // RANDOM