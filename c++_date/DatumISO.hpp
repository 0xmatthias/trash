#ifndef DatumISO_HPP
#define DatumISO_HPP

#include <string>

#include "Datum.hpp"

using namespace std;

class DatumISO : public Datum{
	public:
    DatumISO(int tag, int monat, int jahr);
	string formatiere();
};

#endif