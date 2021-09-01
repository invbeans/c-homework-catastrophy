#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "showinfotable.h"
#include "commonfuncs.h"
#include "tabletoclass.h"

#include "record.h"
#include "position.h"
#include "employee.h"
#include "schedule.h"
#include "genre.h"
#include "author.h"

using namespace std;

void ShowInfoTable::showEmp(Employee* lst) {
    system("cls");
    CommonFuncs function;
    TableToClass reader;

    string fileName;
    fstream fout;
    fstream fin;
    fileName = function.streamCheck(fout, fin);
    system("cls");
    int empCount = 0;

    for (int i = 0; i < 10; i++) {
        reader.empToClass(fin, (lst + i));
        if (empCount % 3 == 0 && empCount != 0) {
            system("PAUSE");
            system("cls");
        }
        if (!(lst + i)->empCode.empty()) {
            cout << "Код сотрудника: " << (lst + i)->empCode << endl;
            cout << "ФИО: " << (lst + i)->FIO << endl;
            cout << "Возраст: " << (lst + i)->age << endl;
            cout << "Пол: " << (lst + i)->gender << endl;
            cout << "Адрес: " << (lst + i)->adress << endl;
            cout << "Телефон: " << (lst + i)->phone << endl;
            cout << "Паспорт: " << (lst + i)->passport << endl;cout << "Код должности: " << (lst + i)->posCode << endl;
            cout << endl;
            empCount++;
        }
    }
    fin.close();
    fout.close();
}

void ShowInfoTable::showPos(Position* lst) {
    system("cls");
    CommonFuncs function;
    TableToClass reader;

    string fileName;
    fstream fout;
    fstream fin;
    fileName = function.streamCheck(fout, fin);
    system("cls");
    int posCount = 0;

    for (int i = 0; i < 5; i++) {
        reader.posToClass(fin, (lst + i));
        if (posCount % 4 == 0 && posCount != 0) {
            system("PAUSE");
            system("cls");
        }
        if (!(lst + i)->posCode.empty()) {
            cout << "Код должности: " << (lst + i)->posCode << endl;
            cout << "Наименование: " << (lst + i)->posName << endl;
            cout << "Оклад: " << (lst + i)->salary << endl;
            cout << "Обязанности: " << (lst + i)->responses << endl;
            cout << "Требования: " << (lst + i)->requires << endl;
            cout << endl;
            posCount++;
        }
    }
    fin.close();
    fout.close();
}

void ShowInfoTable::showAut(Author* lst) {
    system("cls");
    CommonFuncs function;
    TableToClass reader;

    string fileName;
    fstream fout;
    fstream fin;
    fileName = function.streamCheck(fout, fin);
    system("cls");
    //int autCount = 0;

    for (int i = 0; i < 5; i++) {
        reader.autToClass(fin, (lst + i));
        /*if (posCount % 4 == 0 && posCount != 0) {
            system("PAUSE");
            system("cls");
        }*/
        if (!(lst + i)->autCode.empty()) {
            cout << "Код автора: " << (lst + i)->autCode << endl;
            cout << "Наименование: " << (lst + i)->autName << endl;
            cout << "Описание: " << (lst + i)->autDescrip << endl;
            cout << endl;
            //posCount++;
        }
    }
    fin.close();
    fout.close();
}

void ShowInfoTable::showGen(Genre* lst) {
    system("cls");
    CommonFuncs function;
    TableToClass reader;

    string fileName;
    fstream fout;
    fstream fin;
    fileName = function.streamCheck(fout, fin);
    system("cls");
    //int autCount = 0;

    for (int i = 0; i < 5; i++) {
        reader.genToClass(fin, (lst + i));
        /*if (posCount % 4 == 0 && posCount != 0) {
            system("PAUSE");
            system("cls");
        }*/
        if (!(lst + i)->genCode.empty()) {
            cout << "Код жанра: " << (lst + i)->genCode << endl;
            cout << "Наименование: " << (lst + i)->genName << endl;
            cout << "Описание: " << (lst + i)->genDescrip << endl;
            cout << endl;
            //posCount++;
        }
    }
    fin.close();
    fout.close();
}

void ShowInfoTable::showRec(Record* lst) {
    system("cls");
    CommonFuncs function;
    TableToClass reader;

    string fileName;
    fstream fout;
    fstream fin;
    fileName = function.streamCheck(fout, fin);
    system("cls");
    int recCount = 0;

    for (int i = 0; i < 10; i++) {
        reader.recToClass(fin, (lst + i));
        if (recCount % 2 == 0 && recCount != 0) {
            system("PAUSE");
            system("cls");
        }
        if (!(lst + i)->recCode.empty()) {
            cout << "Код записи: " << (lst + i)->recCode << endl;
            cout << "Наименование: " << (lst + i)->recName << endl;
            cout << "Код исполнителя: " << (lst + i)->autCode << endl;
            cout << "Альбом: " << (lst + i)->album << endl;
            cout << "Год: " << (lst + i)->year << endl;
            cout << "Код жанра: " << (lst + i)->genCode << endl;
            cout << "Дата записи: " << (lst + i)->recDate << endl;
            cout << "Длительность: " << (lst + i)->duration << endl;
            cout << "Рейтинг: " << (lst + i)->rating << endl;
            cout << endl;
            recCount++;
        }
    }
    fin.close();
    fout.close();
}

void ShowInfoTable::showSch(Schedule* lst) {
    system("cls");
    CommonFuncs function;
    TableToClass reader;

    string fileName;
    fstream fout;
    fstream fin;
    fileName = function.streamCheck(fout, fin);
    system("cls");
    int schCount = 0;

    for (int i = 0; i < 10; i++) {
        reader.schToClass(fin, (lst + i));
        if (schCount % 3 == 0 && schCount != 0) {
            system("PAUSE");
            system("cls");
        }
        if (!(lst + i)->schDate.empty()) {
            cout << "Дата: " << (lst + i)->schDate << endl;
            cout << "Код сотрудника: " << (lst + i)->empCode << endl;
            cout << "Время 1: " << (lst + i)->time1 << endl;
            cout << "Код записи 1: " << (lst + i)->recCode1 << endl;
            cout << "Время 2: " << (lst + i)->time2 << endl;
            cout << "Код записи 2: " << (lst + i)->recCode2 << endl;
            cout << "Время 3: " << (lst + i)->time3 << endl;
            cout << "Код записи 3: " << (lst + i)->recCode3 << endl;
            cout << endl;
            schCount++;
        }
    }
    fin.close();
    fout.close();
}