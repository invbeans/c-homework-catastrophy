#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "tabletofile.h"

#include "record.h"
#include "position.h"
#include "employee.h"
#include "schedule.h"
#include "genre.h"
#include "author.h"

using namespace std;

void TableToFile::empToFile(fstream& fout, Employee* lst) {
    string resultString;

    resultString.append((lst)->empCode);
    if ((lst)->empCode.length() < 8) for (int i = 0; i < 8 - (lst)->empCode.length(); i++) resultString += " ";
    resultString.append((lst)->FIO);
    if ((lst)->FIO.length() < 30) for (int i = 0; i < 30 - (lst)->FIO.length(); i++) resultString += " ";
    resultString.append((lst)->age);
    if ((lst)->age.length() < 7) for (int i = 0; i < 7 - (lst)->age.length(); i++) resultString += " ";
    resultString.append((lst)->gender);
    if ((lst)->gender.length() < 7) for (int i = 0; i < 7 - (lst)->gender.length(); i++) resultString += " ";
    resultString.append((lst)->adress);
    if ((lst)->adress.length() < 30) for (int i = 0; i < 30 - (lst)->adress.length(); i++) resultString += " ";
    resultString.append((lst)->phone);
    if ((lst)->phone.length() < 15) for (int i = 0; i < 15 - (lst)->phone.length(); i++) resultString += " ";
    resultString.append((lst)->passport);
    if ((lst)->passport.length() < 15) for (int i = 0; i < 15 - (lst)->passport.length(); i++) resultString += " ";
    resultString.append((lst)->posCode);
    if ((lst)->posCode.length() < 8) for (int i = 0; i < 8 - (lst)->posCode.length(); i++) resultString += " ";

    fout << resultString;
}

void TableToFile::posToFile(fstream& fout, Position* lst) {
    string resultString;

    resultString.append((lst)->posCode);
    if ((lst)->posCode.length() < 8) for (int k = 0; k < 8 - (lst)->posCode.length(); k++) resultString += " ";
    resultString.append((lst)->posName);
    if ((lst)->posName.length() < 30) for (int k = 0; k < 30 - (lst)->posName.length(); k++) resultString += " ";
    resultString.append((lst)->salary);
    if ((lst)->salary.length() < 10) for (int k = 0; k < 10 - (lst)->salary.length(); k++) resultString += " ";
    resultString.append((lst)->responses);
    if ((lst)->responses.length() < 30) for (int k = 0; k < 30 - (lst)->responses.length(); k++) resultString += " ";
    resultString.append((lst)->requires);
    if ((lst)->requires.length() < 30) for (int k = 0; k < 30 - (lst)->requires.length(); k++) resultString += " ";

    fout << resultString;
}

void TableToFile::autToFile(fstream& fout, Author* lst) {
    string resultString;

    resultString.append((lst)->autCode);
    if ((lst)->autCode.length() < 8) for (int i = 0; i < 8 - (lst)->autCode.length(); i++) resultString += " ";
    resultString.append((lst)->autName);
    if ((lst)->autName.length() < 30) for (int i = 0; i < 30 - (lst)->autName.length(); i++) resultString += " ";
    resultString.append((lst)->autDescrip);
    if ((lst)->autDescrip.length() < 30) for (int i = 0; i < 30 - (lst)->autDescrip.length(); i++) resultString += " ";

    fout << resultString;
}

void TableToFile::genToFile(fstream& fout, Genre* lst) {
    string resultString;

    resultString.append((lst)->genCode);
    if ((lst)->genCode.length() < 8) for (int i = 0; i < 8 - (lst)->genCode.length(); i++) resultString += " ";
    resultString.append((lst)->genName);
    if ((lst)->genName.length() < 30) for (int i = 0; i < 30 - (lst)->genName.length(); i++) resultString += " ";
    resultString.append((lst)->genDescrip);
    if ((lst)->genDescrip.length() < 30) for (int i = 0; i < 30 - (lst)->genDescrip.length(); i++) resultString += " ";

    fout << resultString;
}

void TableToFile::recToFile(fstream& fout, Record* lst) {
    string resultString;

    resultString.append((lst)->recCode);
    if ((lst)->recCode.length() < 8) for (int i = 0; i < 8 - (lst)->recCode.length(); i++) resultString += " ";
    resultString.append((lst)->recName);
    if ((lst)->recName.length() < 30) for (int i = 0; i < 30 - (lst)->recName.length(); i++) resultString += " ";
    resultString.append((lst)->autCode);
    if ((lst)->autCode.length() < 8) for (int i = 0; i < 8 - (lst)->autCode.length(); i++) resultString += " ";
    resultString.append((lst)->album);
    if ((lst)->album.length() < 30) for (int i = 0; i < 30 - (lst)->album.length(); i++) resultString += " ";
    resultString.append((lst)->year);
    if ((lst)->year.length() < 10) for (int i = 0; i < 10 - (lst)->year.length(); i++) resultString += " ";
    resultString.append((lst)->genCode);
    if ((lst)->genCode.length() < 8) for (int i = 0; i < 8 - (lst)->genCode.length(); i++) resultString += " ";
    resultString.append((lst)->recDate);
    if ((lst)->recDate.length() < 15) for (int i = 0; i < 15 - (lst)->recDate.length(); i++) resultString += " ";
    resultString.append((lst)->duration);
    if ((lst)->duration.length() < 10) for (int i = 0; i < 10 - (lst)->duration.length(); i++) resultString += " ";
    resultString.append((lst)->rating);
    if ((lst)->rating.length() < 5) for (int i = 0; i < 5 - (lst)->rating.length(); i++) resultString += " ";

    fout << resultString;
}

void TableToFile::schToFile(fstream& fout, Schedule* lst) {
    string resultString;

    resultString.append((lst)->schDate);
    if ((lst)->schDate.length() < 15) for (int i = 0; i < 15 - (lst)->schDate.length(); i++) resultString += " ";
    resultString.append((lst)->empCode);
    if ((lst)->empCode.length() < 8) for (int i = 0; i < 8 - (lst)->empCode.length(); i++) resultString += " ";
    resultString.append((lst)->time1);
    if ((lst)->time1.length() < 10) for (int i = 0; i < 10 - (lst)->time1.length(); i++) resultString += " ";
    resultString.append((lst)->recCode1);
    if ((lst)->recCode1.length() < 8) for (int i = 0; i < 8 - (lst)->recCode1.length(); i++) resultString += " ";
    resultString.append((lst)->time2);
    if ((lst)->time2.length() < 10) for (int i = 0; i < 10 - (lst)->time2.length(); i++) resultString += " ";
    resultString.append((lst)->recCode2);
    if ((lst)->recCode2.length() < 8) for (int i = 0; i < 8 - (lst)->recCode2.length(); i++) resultString += " ";
    resultString.append((lst)->time3);
    if ((lst)->time3.length() < 10) for (int i = 0; i < 10 - (lst)->time3.length(); i++) resultString += " ";
    resultString.append((lst)->recCode3);
    if ((lst)->recCode3.length() < 8) for (int i = 0; i < 8 - (lst)->recCode3.length(); i++) resultString += " ";
    
    fout << resultString;
}