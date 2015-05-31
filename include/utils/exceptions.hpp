#ifndef EXCEPTIONS
#define EXCEPTIONS

#include <exception>
#include <string>
#include <sstream>

namespace exception{

	class length_error : public std::exception{
	private:
		const char* what_;
	public:
		length_error(void): what_("Length error"){}
		length_error(const char* what_arg): what_(what_arg){}

		const char* what() const throw(){return what_;}
	};

	class neg_error : public std::exception{
	private:
		const char* what_;
	public:
		neg_error(void): what_("Unexcepted negative value"){}
		neg_error(const char* what_arg): what_(what_arg){}

		const char* what() const throw(){return what_;}
	};

	class access_error : public std::exception{
	private:
		const char* what_;
	public:
		access_error(void): what_("That position isn't allocated"){}
		access_error(const char* what_arg): what_(what_arg){}
		access_error(int pos){
			std::stringstream what;
			what << "The position " << pos << " isn't allocated";
			what_ = what.str().c_str();
		}

		const char* what() const throw(){return what_;}
	};
}

#endif // EXCEPTIONS