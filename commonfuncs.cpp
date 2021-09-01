#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "commonfuncs.h"

#include "record.h"
#include "position.h"
#include "employee.h"
#include "schedule.h"
#include "genre.h"
#include "author.h"

using namespace std;

string CommonFuncs::streamCheck(fstream &fout, fstream &fin) {
    string fileName;
    bool fileCheck = false;
    while (!fileCheck) {
        system("cls");
        cout << "Введите название файла: ";
        //.getline(fileName);
        getline(cin, fileName);
        //cin.
        if (fileName.empty()) { system("cls"); cout << "Введите название файла еще раз: "; continue; }

        fin.open(fileName);
        if (!fin) { cout << "Файла не существует" << endl; } //fileCheck = false; }
        else {
            fout.open(fileName, ios::out | ios::app);
            if (!fout) { cout << "Не удается открыть файл" << endl; } //fileCheck = false; }
            else { cout << "Успешное открытие файла" << endl; system("PAUSE"); fileCheck = true; }
        }
        if (!fileCheck) {
            cout << "Попробуйте еще раз" << endl;
            system("PAUSE");
        }

        //fin.close();
    }
    return fileName;
}
