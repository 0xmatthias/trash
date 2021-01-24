#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

#include "DatumISO.hpp"

DatumISO::DatumISO(int tag, int monat, int jahr) : Datum(tag, monat, jahr) {}

string DatumISO::formatiere()
{
	stringstream ss;
	ss << getJahr() << "." << getMM() << "." << getTT();
    string s = ss.str();
	return s;
}
