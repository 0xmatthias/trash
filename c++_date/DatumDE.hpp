#ifndef DatumDE_HPP
#define DatumDE_HPP

#include <string>

#include "Datum.hpp"
using namespace std;


class DatumDE : public Datum {
	public:
    DatumDE(int tag, int monat, int jahr);
	string formatiere();
};

#endif
