// database.h

#include <iostream>
#include "car.h"

namespace Records {

  const int kMaxCars = 100;
  const int kFirstCarNumber = 1000;
    class Database
      {
      public:
    Car mCars[kMaxCars];
    Database();
    ~Database();

    void addCar(std::string brandCode, std::string registrationNumber,
                std::string bodyNumber, std::string engineNumber,
                int issueYear, int mileageKm, std::string employeeDriverCode,
                std::string dateLastMOT, std::string mechanicsEmployeeCode,
                std::string specialMarks);
    Car& getCar(int inEmployeeNumber);
    void displayAll();
    void displayValidForWorking();
    void displayUnvalidForWorking();
    void saveDatabase(std::string fileName);
    void connectToDatabase(std::string fileName);
    int getIndexForNewCar();
      protected:
    int         mNextSlot;
    int         mNextCarNumber;
      };
}
