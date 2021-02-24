// car.h

#ifndef CAR_H
#define CAR_H

#include <string>

namespace  Records {

  class Car
    {
    public:

      Car();
      ~Car();

      bool isValidForWorking();
      void addDistanceToMileageKm(int distance); // add new distance to mileage
      void display(); // outputs car info to the console
      void fromString(std::string line);
      std::string toString();


      //Getters and Setters
      int getCarNumber();
      void setCarNumber(int carNumber);
      std::string getBrandCode();
      void setBrandCode(std::string brandCode);
      std::string getRegistrationNumber();
      void setRegistrationNumber(std::string registrationNumber);
      std::string getBodyNumber();
      void setBodyNumber(std::string bodyNumber);
      std::string getEngineNumber();
      void setEngineNumber(std::string engineNumber);
      int getIssueYear();
      void setIssueYear(int issueYear);
      int getMileageKm();
      void setMileageKm(int mileage);
      std::string getEmployeeDriverCode();
      void setEmployeeDriverCode(std::string employeeDriverCode);
      std::string getDateLastMOT();
      void setDateLastMOT(std::string dateLastMOT);
      std::string getMechanicsEmployeeCode();
      void setMechanicsEmployeeCode(std::string mechanicsEmployeeCode);
      std::string getSpecialMarks();
      void setSpecialMarks(std::string specialMarks);

    private:
      int mCarNumber;
      std::string mBrandCode;
      std::string mRegistrationNumber;
      std::string mBodyNumber;
      std::string mEngineNumber;
      int mIssueYear;
      int mMileageKm;
      std::string mEmployeeDriverCode;
      std::string mDateLastMOT;
      std::string mMechanicsEmployeeCode;
      std::string mSpecialMarks;
    };

}
#endif // CAR_H
