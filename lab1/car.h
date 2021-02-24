// car.h

#ifndef CAR_H
#define CAR_H

#include <string>
#include <ctime>

class Car
{
 public:
 Car();
 ~Car();

 bool isValidForWorking();

 std::string getCarCode();
 void setCarCode(std::string carCode);
 std::string getBrandCode();
 void setBrandCode(std::string brandCode);
 std::string getRegistrationNumber();
 void setRegistrationNumber(std::string registrationNumber);
 std::string getBodyNumber();
 void setBodyNumber(std::string BodyNumber);
 std::string getEngineNumber();
 void setEngineNumber(std::string engineNumber);
 int getIssueYear();
 void setIssueYear(int issueYear);
 int getMileage();
 void setMileage(int mileage);
 std::string getEmployeeDriverCode();
 void setEmployeeDriverCode(std::string employeeDriverCode);
 std::string getDateLastMOT();
 void setDateLastMOT(std::string dateLastMOT);
 std::string getMechanicsEmployeeCode();
 void setMechanicsEmployeeCode(std::string mechanicsEmployeeCode);
 std::string getSpecialMarks();
 void setSpecialMarks(std::string specialMarks);

private:
 std::string mCarCode;
 std::string mBrandCode;
 std::string mRegistrationNumber;
 std::string mBodyNumber;
 std::string mEngineNumber;
 int mIssueYear;
 int mMileage;
 std::string mEmployeeDriverCode;
 std::string mDateLastMOT;
 std::string mMechanicsEmployeeCode;
 std::string mSpecialMarks;
};

#endif // CAR_H
