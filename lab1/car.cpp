// car.cpp

#include <iostream>
#include "car.h"

using namespace std;

Car::Car()
{
 // initialize data members
    mCarCode = "Unknown";
    mBrandCode = "Unknown";
    mRegistrationNumber = "Unknown";
    mBodyNumber = "Unknown";
    mEngineNumber = "Unknown";
    mIssueYear = 0;
    mMileage = 0;
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
    if(mIssueYear > 2000 && mMileage < 100000 ) {
        return true;
    } else {
        return false;
    }
}

std::string Car::getCarCode()
{
    return mCarCode;
}

void Car::setCarCode(std::string carCode)
{
    mCarCode = carCode;
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

int Car::getMileage()
{
    return mMileage;
}

void Car::setMileage(int mileage)
{
    mMileage = mileage;
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
