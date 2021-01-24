#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

#include "DatumDE.hpp"

DatumDE::DatumDE(int tag, int monat, int jahr) : Datum(tag, monat, jahr) {}

string DatumDE::formatiere()
{
	stringstream ss;
	ss << getTT() << "." << getMM() << "." << getJahr();
    string s = ss.str();
	return s;
}	
