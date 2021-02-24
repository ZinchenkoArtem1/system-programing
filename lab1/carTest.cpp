// carTest.cpp

#include <iostream>
#include "car.h"

using namespace std;

int main()
{
 Car car1; // stack-based Car

 car1.setBodyNumber("11DFK1");
 car1.setBrandCode("22KFJ29L");
 car1.setCarCode("11FKD123");
 car1.setDateLastMOT("10:02:2020");
 car1.setEmployeeDriverCode("FFM24LRL");
 car1.setEngineNumber("KGN14LF");
 car1.setIssueYear(2010);
 car1.setMechanicsEmployeeCode("LFKLN14KF");
 car1.setMileage(15000);
 car1.setRegistrationNumber("FKG24KFK");
 car1.setSpecialMarks("Absent");
 if(car1.isValidForWorking()) {
     cout << "The car(" << car1.getCarCode() << ") valid for working" << endl;
 } else {
     cout << "The car(" << car1.getCarCode() << ")no valid for working" << endl;
 }

 Car* car2; // heap-based Car

 car2 = new Car();
 car2->setBodyNumber("115FK1");
 car2->setBrandCode("2245J29L");
 car2->setCarCode("11FKD4523");
 car2->setDateLastMOT("15:02:2020");
 car2->setEmployeeDriverCode("FF2344LRL");
 car2->setEngineNumber("KGN1234F");
 car2->setIssueYear(1990);
 car2->setMechanicsEmployeeCode("LFKL2352354KF");
 car2->setMileage(10000);
 car2->setRegistrationNumber("FKG144KFK");
 car2->setSpecialMarks("Absent");
 if(car2->isValidForWorking()) {
     cout << "The car(" << car2->getCarCode() << ") valid for working" << endl;
 } else {
     cout << "The car(" << car2->getCarCode() << ")no valid for working" << endl;
 }
 delete car2;

 return 0;
}
