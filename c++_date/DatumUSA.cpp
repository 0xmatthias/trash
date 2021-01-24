#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

#include "DatumUSA.hpp"

DatumUSA::DatumUSA(int tag, int monat, int jahr) : Datum(tag, monat, jahr) {}

string DatumUSA::formatiere()
{
	stringstream ss;
	ss << getMM() << "." << getTT() << "." << getJahr();
    string s = ss.str();
	return s;
}
