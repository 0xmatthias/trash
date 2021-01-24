#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

#include "Datum.hpp"



Datum::Datum(int tag, int monat, int jahr){
	if(tag<32 && tag>0 && monat>0 && monat<13){ 
		this->tag=tag;
		this->monat=monat;
		this->jahr=jahr;
	}
	else{
		cout << "Datum falsch eingegeben, Eingabe überprüfen." << endl;
	}
}

string Datum::getTT()
{
	stringstream ss;
	ss << setw(2) << setfill('0') << tag;
	string s = ss.str();
	return s;
}

string Datum::getMM()
{
	stringstream ss;
	ss << setw(2) << setfill('0') << monat;
	string s = ss.str();
	return s;
}

string Datum::getJahr()
{
	stringstream ss;
	ss << jahr;
	string s = ss.str();
	return s;
}











