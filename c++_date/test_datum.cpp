#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Datum.hpp"
#include "DatumDE.hpp"
#include "DatumISO.hpp"
#include "DatumUSA.hpp"
using namespace std;


int main(){
	cout << "Erzeuge Objekte und gebe korrektes Datum in den dre Formaten aus:" << endl;
	Datum *datde1 = new DatumDE(1, 12, 2021);
	cout << "Deutsche Formatierung: " << datde1->formatiere() << endl;
	Datum *datiso1 = new DatumISO(1, 12, 2021);
	cout << "ISO-Formatierung: " << datiso1->formatiere() << endl;
	Datum *datusa1 = new DatumUSA(1, 12, 2021);
	cout << "USA-Formatierung: " << datusa1->formatiere() << endl;
	
	cout << "Erzeuge Objekte und gebe falsches Datum in den drei Formaten aus:" << endl;
	Datum *datde2 = new DatumDE(4, 20, 2000);
	cout << "Deutsche Formatierung: " <<datde2->formatiere() << endl;
	Datum *datiso2 = new DatumISO(4, 20, 2000);
	cout << "ISO-Formatierung: " << datiso2->formatiere() << endl;
	Datum *datusa2 = new DatumUSA(4, 20, 2000);
	cout << "ISO-Formatierung: " << datiso2->formatiere() << endl;
	
	
	delete datde1, datiso1, datusa1, datde2, datiso2, datusa2;
	return 0;
}
