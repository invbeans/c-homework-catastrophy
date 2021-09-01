#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "tabletoclass.h"

#include "record.h"
#include "position.h"
#include "employee.h"
#include "schedule.h"
#include "genre.h"
#include "author.h"

using namespace std;

void TableToClass::empToClass(fstream& fin, Employee* lst) {
    string readInfo;
    getline(fin, readInfo);
    if (!readInfo.empty()) {
        (lst)->empCode = "";
        for (int j = 0; j < 8; j++) (lst)->empCode += readInfo[j];
        (lst)->FIO = "";
        for (int j = 8; j < 38; j++) (lst)->FIO += readInfo[j];
        (lst)->age = "";
        for (int j = 38; j < 45; j++) (lst)->age += readInfo[j];
        (lst)->gender = "";
        for (int j = 45; j < 52; j++) (lst)->gender += readInfo[j]; 
        (lst)->adress = "";
        for (int j = 52; j < 82; j++) (lst)->adress += readInfo[j];
        (lst)->phone = "";
        for (int j = 82; j < 97; j++) (lst)->phone += readInfo[j]; 
        (lst)->passport = "";
        for (int j = 97; j < 112; j++) (lst)->passport += readInfo[j];
        (lst)->posCode = "";
        for (int j = 112; j < 120; j++) (lst)->posCode += readInfo[j];
    }
}

void TableToClass::posToClass(fstream& fin, Position* lst) {
    string readInfo;
    getline(fin, readInfo);
    if (!readInfo.empty()) {
        (lst)->posCode = "";
        for (int j = 0; j < 8; j++) (lst)->posCode += readInfo[j]; 
        (lst)->posName = "";
        for (int j = 8; j < 38; j++) (lst)->posName += readInfo[j];
        (lst)->salary = "";
        for (int j = 38; j < 48; j++) (lst)->salary += readInfo[j];
        (lst)->responses = "";
        for (int j = 48; j < 78; j++) (lst)->responses += readInfo[j];
        (lst)->requires = "";
        for (int j = 78; j < 108; j++) (lst)->requires += readInfo[j];
    }
}

void TableToClass::autToClass(fstream& fin, Author* lst) {
    string readInfo;
    getline(fin, readInfo);
    if (!readInfo.empty()) {
        (lst)->autCode = "";
        for (int j = 0; j < 8; j++) (lst)->autCode += readInfo[j];
        (lst)->autName = "";
        for (int j = 8; j < 38; j++) (lst)->autName += readInfo[j];
        (lst)->autDescrip = "";
        for (int j = 38; j < 68; j++) (lst)->autDescrip += readInfo[j];
    }
}

void TableToClass::genToClass(fstream& fin, Genre* lst) {
    string readInfo;
    getline(fin, readInfo);
    if (!readInfo.empty()) {
        (lst)->genCode = "";
        for (int j = 0; j < 8; j++) (lst)->genCode += readInfo[j];
        (lst)->genName = "";
        for (int j = 8; j < 38; j++) (lst)->genName += readInfo[j];
        (lst)->genDescrip = "";
        for (int j = 38; j < 68; j++) (lst)->genDescrip += readInfo[j];
    }
}

void TableToClass::recToClass(fstream& fin, Record* lst) {
    string readInfo;
    getline(fin, readInfo);
    if (!readInfo.empty()) {
        (lst)->recCode = "";
        for (int j = 0; j < 8; j++) (lst)->recCode += readInfo[j];
        (lst)->recName = "";
        for (int j = 8; j < 38; j++) (lst)->recName += readInfo[j];
        (lst)->autCode = "";
        for (int j = 38; j < 46; j++) (lst)->autCode += readInfo[j];
        (lst)->album = "";
        for (int j = 46; j < 76; j++) (lst)->album += readInfo[j];
        (lst)->year = "";
        for (int j = 76; j < 86; j++) (lst)->year += readInfo[j];
        (lst)->genCode = "";
        for (int j = 86; j < 94; j++) (lst)->genCode += readInfo[j];
        (lst)->recDate = "";
        for (int j = 94; j < 109; j++) (lst)->recDate += readInfo[j];
        (lst)->duration = "";
        for (int j = 109; j < 119; j++) (lst)->duration += readInfo[j];
        (lst)->rating = "";
        for (int j = 119; j < 124; j++) (lst)->rating += readInfo[j];
    }
}

void TableToClass::schToClass(fstream& fin, Schedule* lst) {
    string readInfo;
    getline(fin, readInfo);
    if (!readInfo.empty()) {
        (lst)->schDate = "";
        for (int j = 0; j < 15; j++) (lst)->schDate += readInfo[j];
        (lst)->empCode = "";
        for (int j = 15; j < 23; j++) (lst)->empCode += readInfo[j];
        (lst)->time1 = "";
        for (int j = 23; j < 33; j++) (lst)->time1 += readInfo[j];
        (lst)->recCode1 = "";
        for (int j = 33; j < 41; j++) (lst)->recCode1 += readInfo[j];
        (lst)->time2 = "";
        for (int j = 41; j < 51; j++) (lst)->time2 += readInfo[j];
        (lst)->recCode2 = "";
        for (int j = 51; j < 59; j++) (lst)->recCode2 += readInfo[j];
        (lst)->time3 = "";
        for (int j = 59; j < 69; j++) (lst)->time3 += readInfo[j];
        (lst)->recCode3 = "";
        for (int j = 69; j < 77; j++) (lst)->recCode3 += readInfo[j];
    }
}