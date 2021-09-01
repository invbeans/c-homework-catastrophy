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
            cout << "��� ����������: " << (lst + i)->empCode << endl;
            cout << "���: " << (lst + i)->FIO << endl;
            cout << "�������: " << (lst + i)->age << endl;
            cout << "���: " << (lst + i)->gender << endl;
            cout << "�����: " << (lst + i)->adress << endl;
            cout << "�������: " << (lst + i)->phone << endl;
            cout << "�������: " << (lst + i)->passport << endl;cout << "��� ���������: " << (lst + i)->posCode << endl;
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
            cout << "��� ���������: " << (lst + i)->posCode << endl;
            cout << "������������: " << (lst + i)->posName << endl;
            cout << "�����: " << (lst + i)->salary << endl;
            cout << "�����������: " << (lst + i)->responses << endl;
            cout << "����������: " << (lst + i)->requires << endl;
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
            cout << "��� ������: " << (lst + i)->autCode << endl;
            cout << "������������: " << (lst + i)->autName << endl;
            cout << "��������: " << (lst + i)->autDescrip << endl;
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
            cout << "��� �����: " << (lst + i)->genCode << endl;
            cout << "������������: " << (lst + i)->genName << endl;
            cout << "��������: " << (lst + i)->genDescrip << endl;
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
            cout << "��� ������: " << (lst + i)->recCode << endl;
            cout << "������������: " << (lst + i)->recName << endl;
            cout << "��� �����������: " << (lst + i)->autCode << endl;
            cout << "������: " << (lst + i)->album << endl;
            cout << "���: " << (lst + i)->year << endl;
            cout << "��� �����: " << (lst + i)->genCode << endl;
            cout << "���� ������: " << (lst + i)->recDate << endl;
            cout << "������������: " << (lst + i)->duration << endl;
            cout << "�������: " << (lst + i)->rating << endl;
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
            cout << "����: " << (lst + i)->schDate << endl;
            cout << "��� ����������: " << (lst + i)->empCode << endl;
            cout << "����� 1: " << (lst + i)->time1 << endl;
            cout << "��� ������ 1: " << (lst + i)->recCode1 << endl;
            cout << "����� 2: " << (lst + i)->time2 << endl;
            cout << "��� ������ 2: " << (lst + i)->recCode2 << endl;
            cout << "����� 3: " << (lst + i)->time3 << endl;
            cout << "��� ������ 3: " << (lst + i)->recCode3 << endl;
            cout << endl;
            schCount++;
        }
    }
    fin.close();
    fout.close();
}