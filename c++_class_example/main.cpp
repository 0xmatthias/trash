#include <iostream>

#include "point3.hpp"
#include "line.hpp"

int main(int argc, char * argv[]){
	Point3 p01 = Point3(7.f, 42.f);
	Point3 p02 = Point3(5.f, 36.f);
	Line myLine = Line(p01, p02);
	std::cout << " Die Linie geht durch den Punkt: (" << myLine.p1.x << ", " << myLine.p1.y << ")." << std::endl;
	return 0;
}
