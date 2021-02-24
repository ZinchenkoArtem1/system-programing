// car.cpp

#include <iostream>
#include "car.h"
#include "ctime"

using namespace std;

namespace  Records {

    Car::Car()
    {

     // initialize data members
        mCarNumber = -1;
        mBrandCode = "Unknown";
        mRegistrationNumber = "Unknown";
        mBodyNumber = "Unknown";
        mEngineNumber = "Unknown";
        mIssueYear = 0;
        mMileageKm = 0;
        mEmployeeDriverCode = "Unknown";
        mDateLastMOT = "Unknown";
        mMechanicsEmployeeCode = "Unknown";
        mSpecialMarks = "Unknown";
    }

    Car::~Car()
    {
     // nothing much to do in terms of cleanup
    }

    bool Car::isValidForWorking()
    {
        if(mIssueYear > 2000 && mMileageKm < 100000 ) {
            return true;
        } else {
            return false;
        }
    }

    void Car::addDistanceToMileageKm(int distance)
    {
        setMileageKm(getMileageKm() + distance);
    }

    void Car::display()
    {
      cout << "Car: " << getBrandCode() << "(" << getRegistrationNumber()<< ")" << endl;
      cout << "-------------------------" << endl;
      cout << "Car Number: " << getCarNumber() << endl;
      cout << (isValidForWorking() ? "Valid for work" : "Not valid for work") << endl;
      cout << "Mileage: " << getMileageKm() << "km" << endl;
      cout << "Issue year: $" << getIssueYear() << endl;
      cout << "Date of last MOT: $" << getDateLastMOT() << endl;
      cout << endl;
    }

    void Car::fromString(std::string line)
    {
        std::string data[11]; // array with object data
        int dataIndex = 0;   // index of object data
        std::string buffer = "";      // buffer line

        for(int i=0; i < line.size(); i++){
            if(line[i] != '|') {      // '|' -  splitter
                  buffer += (line[i]);     //if we don't have splitter we add char to buffer
            }
            else {
                  data[dataIndex] = buffer; //if we have splitter we add our data from buffer to array with object data
                  dataIndex++;
                  buffer = ""; // reset to zero buffer
            }
        }
        // set our data from array to object
        setCarNumber(std::stoi(data[0])); //string to int
        setBrandCode(data[1]);
        setRegistrationNumber(data[2]);
        setBodyNumber(data[3]);
        setEngineNumber(data[4]);
        setIssueYear(std::stoi(data[5]));  //string to int
        setMileageKm(std::stoi(data[6]));  //string to int
        setEmployeeDriverCode(data[7]);
        setDateLastMOT(data[8]);
        setMechanicsEmployeeCode(data[9]);
        setSpecialMarks(data[10]);
    }

    std::string Car::toString() {
        char splitter = '|';
        return (std::to_string(mCarNumber).append(
                    splitter + mBrandCode).append(
                    splitter + mRegistrationNumber).append(
                    splitter + mBodyNumber).append(
                    splitter + mEngineNumber).append(
                    splitter + std::to_string(mIssueYear)).append(
                    splitter + std::to_string(mMileageKm)).append(
                    splitter + mEmployeeDriverCode).append(
                    splitter + mDateLastMOT).append(
                    splitter + mMechanicsEmployeeCode).append(
                    splitter + mSpecialMarks + splitter));  //we need add  "|" in the end for checking last data
    }

    int Car::getCarNumber()
    {
        return mCarNumber;
    }

    void Car::setCarNumber(int carNumber)
    {
        mCarNumber = carNumber;
    }

    std::string Car::getBrandCode()
    {
        return mBrandCode;
    }

    void Car::setBrandCode(std::string brandCode)
    {
        mBrandCode = brandCode;
    }

    std::string Car::getRegistrationNumber()
    {
        return mRegistrationNumber;
    }

    void Car::setRegistrationNumber(std::string registrationNumber)
    {
        mRegistrationNumber = registrationNumber;
    }

    std::string Car::getBodyNumber()
    {
        return mBodyNumber;
    }

    void Car::setBodyNumber(std::string bodyNumber)
    {
        mBodyNumber = bodyNumber;
    }

    std::string Car::getEngineNumber()
    {
        return mEngineNumber;
    }

    void Car::setEngineNumber( std::string engineNumber)
    {
        mEngineNumber = engineNumber;
    }

    int Car::getIssueYear()
    {
        return mIssueYear;
    }

    void Car::setIssueYear(int issueYear)
    {
        mIssueYear = issueYear;
    }

    int Car::getMileageKm()
    {
        return mMileageKm;
    }

    void Car::setMileageKm(int mileage)
    {
        mMileageKm = mileage;
    }

    std::string Car::getEmployeeDriverCode()
    {
        return mEmployeeDriverCode;
    }

    void Car::setEmployeeDriverCode(std::string employeeDriverCode)
    {
        mEmployeeDriverCode = employeeDriverCode;
    }

    std::string Car::getDateLastMOT()
    {
        return mDateLastMOT;
    }

    void Car::setDateLastMOT(std::string dateLastMOT)
    {
        mDateLastMOT = dateLastMOT;
    }

    std::string Car::getMechanicsEmployeeCode()
    {
        return mMechanicsEmployeeCode;
    }

    void Car::setMechanicsEmployeeCode(std::string mechanicsEmployeeCode)
    {
        mMechanicsEmployeeCode = mechanicsEmployeeCode;
    }

    std::string Car::getSpecialMarks()
    {
        return mSpecialMarks;
    }

    void Car::setSpecialMarks(std::string specialMarks)
    {
        mSpecialMarks = specialMarks;
    }
}
