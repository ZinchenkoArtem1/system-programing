// database.cpp

#include <iostream>
#include <stdexcept>
#include <string>
#include<fstream>

#include "database.h"

using namespace std;

namespace Records {

  Database::Database()
  {
    try {
      connectToDatabase("output.txt");
    } catch (std::exception()) {
      cerr << "cannot connect to database" << endl;
    }
    mNextSlot = getIndexForNewCar();

    if(mNextSlot != 0) {
        mNextCarNumber = mCars[mNextSlot - 1].getCarNumber() + 1;
    }
    else {
        mNextCarNumber = kFirstCarNumber;
    }
  }

  Database::~Database()
  {

  }

  void Database::addCar(std::string brandCode, std::string registrationNumber,
                        std::string bodyNumber, std::string engineNumber,
                        int issueYear, int mileageKm, std::string employeeDriverCode,
                        std::string dateLastMOT ,std::string mechanicsEmployeeCode,
                        std::string specialMarks)
  {
    if (mNextSlot >= kMaxCars) {
      cerr << "There is no more place on parking to add the new car!" << endl;
      throw exception();
    }

    Car& theCar = mCars[mNextSlot];
    mNextSlot++;
    theCar.setCarNumber(mNextCarNumber++);
    theCar.setBrandCode(brandCode);
    theCar.setRegistrationNumber(registrationNumber);
    theCar.setBodyNumber(bodyNumber);
    theCar.setEngineNumber(engineNumber);
    theCar.setIssueYear(issueYear);
    theCar.setMileageKm(mileageKm);
    theCar.setEmployeeDriverCode(employeeDriverCode);
    theCar.setDateLastMOT(dateLastMOT);
    theCar.setMechanicsEmployeeCode(mechanicsEmployeeCode);
    theCar.setSpecialMarks(specialMarks);
  }

  Car& Database::getCar(int inCarNumber)
  {
    for (int i = 0; i < mNextSlot; i++) {
      if (mCars[i].getCarNumber() == inCarNumber) {
    return mCars[i];
      }
    }
    cerr << "No car with car number " << inCarNumber << endl;
    throw exception();
  }

  void Database::displayAll()
  {
    for (int i = 0; i < mNextSlot; i++) {
      mCars[i].display();
    }
  }

  void Database::displayValidForWorking()
  {
    for (int i = 0; i < mNextSlot; i++) {
      if (mCars[i].isValidForWorking()) {
    mCars[i].display();
      }
    }
  }

  void Database::displayUnvalidForWorking()
  {
    for (int i = 0; i < mNextSlot; i++) {
      if (!mCars[i].isValidForWorking()) {
    mCars[i].display();
      }
    }
  }

  void Database::saveDatabase(std::string fileName) {
      std::ofstream outf(fileName);
      if (!outf)
          {
              cerr << "file could not be opened for writing!" << endl;
              throw exception();
          }

      for(int i = 0; i < mNextSlot; i++) {
          outf << mCars[i].toString() << endl;
      }
      outf.close();
  }

  void Database::connectToDatabase(std::string fileName) {
      std::ifstream inf(fileName);
      if (!inf)
          {
              cerr << fileName << ": could not be opened for reading!" << endl;
              throw exception();
          }
      int i = 0;
      string line;
      while (inf)
          {
              getline(inf, line);
              if (line == "") {
                  return;
              }
              Car& theCar = mCars[i];
              theCar.fromString(line);
              i++;
          }
       inf.close();
  }

  int Database::getIndexForNewCar() {
      for (int i = 0; i < kMaxCars; i ++) {
          if(mCars[i].getCarNumber() == -1) {
              return i;
          }
      }
      return -1;
  }
}
