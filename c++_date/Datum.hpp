#ifndef Datum_HPP
#define Datum_HPP

#include <string>

//#include "DatumDE.hpp"
//#include "DatumUSA.hpp"
//#include "DatumISO.hpp"
using namespace std;

class Datum{
	private:
	int tag;
	int monat;
	int jahr;
	
	public:
	Datum(int tag, int monat, int jahr);
	string getTT();
	string getMM();
	string getJahr();
	virtual string formatiere() = 0;
};

#endif
