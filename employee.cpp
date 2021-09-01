#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "employee.h"

using namespace std;

Employee::Employee() {}
Employee::~Employee() {}

void Employee::setEmpCode(int tempEmpCode) { empCode = tempEmpCode; }
void Employee::setFIO(string tempFIO) { FIO = tempFIO; }
void Employee::setAge(int tempAge) { age = tempAge; }
void Employee::setGender(string tempGender) { gender = tempGender; }
void Employee::setAdress(string tempAdress) { adress = tempAdress; }
void Employee::setPhone(string tempPhone) { phone = tempPhone; }
void Employee::setPassport(string tempPassport) { passport = tempPassport; }
void Employee::setPosCode(int tempPosCode) { posCode = tempPosCode; }

//геттеры отдельных полей класса========================================
int Employee::getEmpCode() { return empCode; }
string Employee::getFIO() { return FIO; }
int Employee::getAge() { return age; }
string Employee::getGender() { return gender; }
string Employee::getAdress() { return adress; }
string Employee::getPhone() { return phone; }
string Employee::getPassport() { return passport; }
int Employee::getPosCode() { return posCode; }