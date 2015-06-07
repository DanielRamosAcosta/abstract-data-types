#ifndef HUMAN
#define HUMAN

#include <iostream>
#include <string>

#include "utils/random.hpp"

namespace dra{

	typedef unsigned long dni_t;

	class human
	{
	private:
		std::string name_;
		std::string surname_;
		dni_t dni_;
		char character_;
	public:
		human(void);
		human(std::string, std::string, dni_t);
		~human(void);

		std::string name(void) const;
		std::string surname(void) const;
		dni_t dni(void) const;

		std::ostream& toStream(std::ostream&) const;

		bool operator==(human& h);
		bool operator!=(human& h);
		bool operator<(human& h);
		bool operator>(human& h);
		bool operator<=(human& h);
		bool operator>=(human& h);
	};

	human::human(void)
	{
		srand(random<unsigned long>::rand());

		unsigned name = rand() % 100;

		srand(rand());
		unsigned surname = rand() % 100;

		srand(rand());
		dni_ = rand() % 50000000 + 30000000;

		srand(rand());
		character_ = rand() % 25 + 65;

		switch(name){
			case 0: name_ = "Divina"; break;
			case 1: name_ = "Sheron"; break;
			case 2: name_ = "Kathryne"; break;
			case 3: name_ = "Pennie"; break;
			case 4: name_ = "Shaunte"; break;
			case 5: name_ = "Fidel"; break;
			case 6: name_ = "Adele"; break;
			case 7: name_ = "Jarod"; break;
			case 8: name_ = "Sherilyn"; break;
			case 9: name_ = "Luann"; break;
			case 10: name_ = "Elvis"; break;
			case 11: name_ = "Claude"; break;
			case 12: name_ = "Clyde"; break;
			case 13: name_ = "Lorraine"; break;
			case 14: name_ = "Carter"; break;
			case 15: name_ = "Tona"; break;
			case 16: name_ = "Leandra"; break;
			case 17: name_ = "Janeyv"; break;
			case 18: name_ = "Ilene"; break;
			case 19: name_ = "Eduardo"; break;
			case 20: name_ = "Garth"; break;
			case 21: name_ = "Jamie"; break;
			case 22: name_ = "Neta"; break;
			case 23: name_ = "Trinidad"; break;
			case 24: name_ = "Luciano"; break;
			case 25: name_ = "Yuri"; break;
			case 26: name_ = "Kaylene"; break;
			case 27: name_ = "Vincent"; break;
			case 28: name_ = "Mohamed"; break;
			case 29: name_ = "Roxana"; break;
			case 30: name_ = "Son"; break;
			case 31: name_ = "Nikole"; break;
			case 32: name_ = "Jena"; break;
			case 33: name_ = "Stefany"; break;
			case 34: name_ = "Maya"; break;
			case 35: name_ = "Dorene"; break;
			case 36: name_ = "Johnathan"; break;
			case 37: name_ = "Maxima"; break;
			case 38: name_ = "Dionna"; break;
			case 39: name_ = "Twanna"; break;
			case 40: name_ = "Kittie"; break;
			case 41: name_ = "Rosalina"; break;
			case 42: name_ = "Miles"; break;
			case 43: name_ = "Ardelle"; break;
			case 44: name_ = "Maryalice"; break;
			case 45: name_ = "Lauran"; break;
			case 46: name_ = "Jesusita"; break;
			case 47: name_ = "Elton"; break;
			case 48: name_ = "Lester"; break;
			case 49: name_ = "Chan"; break;
			case 50: name_ = "Georgina"; break;
			case 51: name_ = "Mike"; break;
			case 52: name_ = "Lupe"; break;
			case 53: name_ = "Bertram"; break;
			case 54: name_ = "Georgetta"; break;
			case 55: name_ = "Telma"; break;
			case 56: name_ = "Floria"; break;
			case 57: name_ = "Darren"; break;
			case 58: name_ = "Carson"; break;
			case 59: name_ = "Lorene"; break;
			case 60: name_ = "Dorian"; break;
			case 61: name_ = "Carlota"; break;
			case 62: name_ = "Jackeline"; break;
			case 63: name_ = "Marcelo"; break;
			case 64: name_ = "Cathryn"; break;
			case 65: name_ = "Alvera"; break;
			case 66: name_ = "Elvera"; break;
			case 68: name_ = "Pamelia"; break;
			case 69: name_ = "Mckinley"; break;
			case 70: name_ = "Rufus"; break;
			case 71: name_ = "Monte"; break;
			case 72: name_ = "Emmett"; break;
			case 73: name_ = "Zulema"; break;
			case 74: name_ = "Wilbert"; break;
			case 75: name_ = "Janise"; break;
			case 76: name_ = "Ariane"; break;
			case 77: name_ = "Felice"; break;
			case 78: name_ = "Julienne"; break;
			case 79: name_ = "Kaci"; break;
			case 80: name_ = "Guillermina"; break;
			case 81: name_ = "Vennie"; break;
			case 82: name_ = "Lachelle"; break;
			case 83: name_ = "Maryrose"; break;
			case 84: name_ = "Shandra"; break;
			case 85: name_ = "Akiko"; break;
			case 86: name_ = "Pamala"; break;
			case 87: name_ = "Eric"; break;
			case 88: name_ = "Skye"; break;
			case 89: name_ = "Marissa"; break;
			case 90: name_ = "Denna"; break;
			case 91: name_ = "Wes"; break;
			case 92: name_ = "Many"; break;
			case 93: name_ = "Kris"; break;
			case 94: name_ = "Toshia"; break;
			case 95: name_ = "Athena"; break;
			case 96: name_ = "Janis"; break;
			case 97: name_ = "Myrtie"; break;
			case 98: name_ = "Maximo"; break;
			case 99: name_ = "Jamel"; break;
			default: name_ = "???"; break;
		}

		switch(surname){
			case 0: surname_ = "Conte"; break;
			case 1: surname_ = "Helgeson"; break;
			case 2: surname_ = "Baise"; break;
			case 3: surname_ = "Parnes"; break;
			case 4: surname_ = "Kuosmanen"; break;
			case 5: surname_ = "De lima"; break;
			case 6: surname_ = "Tenney"; break;
			case 7: surname_ = "Davol"; break;
			case 8: surname_ = "Warren"; break;
			case 9: surname_ = "Schussler fiore"; break;
			case 10: surname_ = "Paek"; break;
			case 11: surname_ = "Wells"; break;
			case 12: surname_ = "Bruckner"; break;
			case 13: surname_ = "Pellichero"; break;
			case 14: surname_ = "Perron"; break;
			case 15: surname_ = "Ritchie-copass"; break;
			case 16: surname_ = "Vanderleeden"; break;
			case 17: surname_ = "Goodarzy"; break;
			case 18: surname_ = "Wolfsfeld"; break;
			case 19: surname_ = "Cerva"; break;
			case 20: surname_ = "Miesbauer"; break;
			case 21: surname_ = "Bracey"; break;
			case 22: surname_ = "Coleman"; break;
			case 23: surname_ = "Geisser"; break;
			case 24: surname_ = "Zaidi"; break;
			case 25: surname_ = "Holtzclaw"; break;
			case 26: surname_ = "Zapatka"; break;
			case 27: surname_ = "Stimpfle"; break;
			case 28: surname_ = "De sena"; break;
			case 29: surname_ = "Metz"; break;
			case 30: surname_ = "Veronesi"; break;
			case 31: surname_ = "Smit"; break;
			case 32: surname_ = "Diddley"; break;
			case 33: surname_ = "Kraytsberg"; break;
			case 34: surname_ = "Pasternak"; break;
			case 35: surname_ = "Splaine"; break;
			case 36: surname_ = "Pasquini"; break;
			case 37: surname_ = "Shalala"; break;
			case 38: surname_ = "Kondylis"; break;
			case 39: surname_ = "Szentgyorgyi"; break;
			case 40: surname_ = "Dufour"; break;
			case 41: surname_ = "Naviaux"; break;
			case 42: surname_ = "Halperin"; break;
			case 43: surname_ = "Cardin"; break;
			case 44: surname_ = "Busetta"; break;
			case 45: surname_ = "Pitman"; break;
			case 46: surname_ = "Stearns"; break;
			case 47: surname_ = "Colby"; break;
			case 48: surname_ = "Scully"; break;
			case 49: surname_ = "Jeffries"; break;
			case 50: surname_ = "Yesson"; break;
			case 51: surname_ = "Carnahan"; break;
			case 52: surname_ = "Quintilian"; break;
			case 53: surname_ = "Coveney"; break;
			case 54: surname_ = "Orru'"; break;
			case 55: surname_ = "Chupasko"; break;
			case 56: surname_ = "Menninger"; break;
			case 57: surname_ = "Tiago"; break;
			case 58: surname_ = "Sands"; break;
			case 59: surname_ = "Tucker"; break;
			case 60: surname_ = "Girard"; break;
			case 61: surname_ = "Buday"; break;
			case 62: surname_ = "Elvis"; break;
			case 63: surname_ = "Hertz"; break;
			case 64: surname_ = "Balderson"; break;
			case 65: surname_ = "Prince"; break;
			case 66: surname_ = "Lipscomb"; break;
			case 67: surname_ = "Chervenik"; break;
			case 68: surname_ = "Kostoris"; break;
			case 69: surname_ = "Mathers"; break;
			case 70: surname_ = "Tatar"; break;
			case 71: surname_ = "Mayo"; break;
			case 72: surname_ = "Silva"; break;
			case 73: surname_ = "Gamble"; break;
			case 74: surname_ = "Suleiman"; break;
			case 75: surname_ = "Kazmierczak"; break;
			case 76: surname_ = "Sarno"; break;
			case 77: surname_ = "De castro brun"; break;
			case 78: surname_ = "Karpouzes"; break;
			case 79: surname_ = "Sacks"; break;
			case 80: surname_ = "Nair"; break;
			case 81: surname_ = "Hakesley"; break;
			case 82: surname_ = "Marso"; break;
			case 83: surname_ = "Arriero"; break;
			case 84: surname_ = "Cortese"; break;
			case 85: surname_ = "Farahmand"; break;
			case 86: surname_ = "Chafe"; break;
			case 87: surname_ = "Steuernagel"; break;
			case 88: surname_ = "Steinbeck"; break;
			case 89: surname_ = "Ying"; break;
			case 90: surname_ = "Van baalen"; break;
			case 91: surname_ = "Verghese"; break;
			case 92: surname_ = "Soep"; break;
			case 93: surname_ = "Studier"; break;
			case 94: surname_ = "Boyden"; break;
			case 95: surname_ = "Mortensen"; break;
			case 96: surname_ = "Gillyat"; break;
			case 97: surname_ = "Pace"; break;
			case 98: surname_ = "Kleinfelder"; break;
			case 99: surname_ = "Silverberg"; break;
			default: surname_ = "???"; break;
		}
	};

	human::human(std::string name, std::string surname, dni_t dni):
	name_(name),
	surname_(surname),
	dni_(dni) //TODO: Check if 0 <= dni <= 99999999
	{}

	human::~human(void)
	{}

	std::string human::name(void) const
	{
		return name_;
	}
	
	std::string human::surname(void) const
	{
		return surname_;	
	}

	dni_t human::dni(void) const
	{
		return dni_;
	}

	std::ostream& human::toStream(std::ostream& os) const
	{
		os << name_ << " " << surname_ << " " << dni_ << character_;
		return os;
	}

	bool human::operator==(human& h)
	{
		return dni_ == h.dni_;
	}

	bool human::operator!=(human& h)
	{
		return dni_ != h.dni_;
	}

	bool human::operator<(human& h)
	{
		return dni_ < h.dni_;
	}

	bool human::operator>(human& h)
	{
		return dni_ > h.dni_;
	}

	bool human::operator<=(human& h)
	{
		return dni_ <= h.dni_;
	}

	bool human::operator>=(human& h)
	{
		return dni_ >= h.dni_;
	}

	std::ostream& operator<<(std::ostream& os, const human& it)
	{
		return it.toStream(os);
	}
}

#endif // HUMAN