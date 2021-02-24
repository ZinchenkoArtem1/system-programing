// userinterface.cpp

#include <iostream>
#include <stdexcept>
#include <string>

#include "database.h"

using namespace std;
using namespace Records;

int displayMenu();
void addCar(Database& inDB);
void getCar(Database& inDB);
void addDistance(Database& inDB);

int main()
{
  Database employeeDB;

  bool done = false;

  while (!done) {
    int selection = displayMenu();

    switch (selection) {
    case 1:
      addCar(employeeDB);
      break;
    case 2:
      getCar(employeeDB);;
      break;
    case 3:
      addDistance(employeeDB);
      break;
    case 4:
      employeeDB.displayAll();
      break;
    case 5:
      employeeDB.displayValidForWorking();
      break;
    case 6:
      employeeDB.displayUnvalidForWorking();
      break;
    case 0:
      try {
        employeeDB.saveDatabase("output.txt");
      } catch(std::exception) {
          cerr << "Database not save." << endl;
      }
      done = true;
      break;
    default:
      cerr << "Unknown command." << endl;
    }
  }
}

int displayMenu()
{
  int selection;

  cout << endl;
  cout << "Car Database" << endl;
  cout << "-----------------" << endl;
  cout << "1) Add a new car" << endl;
  cout << "2) Get info about car" << endl;
  cout << "3) Add distance to car mileage" << endl;
  cout << "4) List all cars" << endl;
  cout << "5) List all valid cars" << endl;
  cout << "6) List all unvaid cars" << endl;
  cout << "0) Quit" << endl;
  cout << endl;
  cout << "---> ";

  cin >> selection;
  cin.ignore();

  return selection;
}

void addCar(Database& inDB)
{
    string brandCode;
    string registrationNumber;
    string bodyNumber;
    string engineNumber;
    int issueYear;
    int mileageKm;
    string employeeDriverCode;
    string dateLastMOT;
    string mechanicsEmployeeCode;
    string specialMarks;

  cout << "Code of brand? " ;
  std::getline(std::cin, brandCode);
  cout << "Number of registration? ";
  std::getline(std::cin, registrationNumber);
  cout << "Number of body? ";
  std::getline(std::cin, bodyNumber);
  cout << "Number of engine? ";
  std::getline(std::cin, engineNumber);
  cout << "Issue year? ";
  std::string sIssueYear;
  std::getline(std::cin, sIssueYear);
  issueYear = std::stoi(sIssueYear);
  cout << "Mileage in km? ";
  std::string sMileageKm;
  std::getline(std::cin, sMileageKm);
  mileageKm = std::stoi(sMileageKm);
  cout << "Code of employee driver? ";
  std::getline(std::cin, employeeDriverCode);
  cout << "Date of last MOT? ";
  std::getline(std::cin, dateLastMOT);
  cout << "Code of mechanics? ";
  std::getline(std::cin, mechanicsEmployeeCode);
  cout << "Special marks? ";
  std::getline(std::cin, specialMarks);
  try {
    inDB.addCar(brandCode, registrationNumber, bodyNumber,
                engineNumber, issueYear, mileageKm,
                employeeDriverCode, dateLastMOT,
                mechanicsEmployeeCode, specialMarks);
  } catch (std::exception ex) {
    cerr << "Unable to add new car!" << endl;
  }
}

void getCar(Database& inDB)
{
  int carNumber;
  cout << "Car number? ";
  cin >> carNumber;
  cin.ignore();
  try {
    Car& car = inDB.getCar(carNumber);
    car.display();
  } catch (std::exception ex) {
    cerr << "Unable to get car!" << endl;
  }
}

void addDistance(Database& inDB)
{
  int carNumber;
  int raiseAmount;

  cout << "Car number? ";
  cin >> carNumber;

  cout << "How much of a distance? ";
  cin >> raiseAmount;
  cin.ignore();

  try {
    Car& car = inDB.getCar(carNumber);
    car.addDistanceToMileageKm(raiseAmount);
  } catch (std::exception ex) {
    cerr << "Unable to add distance!" << endl;
  }
}

