#ifndef DatumUSA_HPP
#define DatumUSA_HPP

#include <string>

#include "Datum.hpp"



using namespace std;

class DatumUSA : public Datum{
	public:
    DatumUSA(int tag, int monat, int jahr);
	string formatiere();
};

#endif