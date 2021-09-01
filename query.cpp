#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "tabletoclass.h"

#include "employee.h"
#include "author.h"
#include "schedule.h"
#include "genre.h"
#include "position.h"
#include "record.h"

#include "personneldepartment.h"
#include "musicarchieve.h"
#include "broadcastinggrid.h"
#include "query.h"

using namespace std;

void Query::persDep(Employee* empList, Position* posList, PersonnelDepartment* persDepList) {
    system("cls");
    TableToClass reader;
    int persDepCount = 0;

    fstream readEmp("empl.txt", ios::in);
    Employee tempEmpList[10];

    fstream readPos("posi.txt", ios::in);
    Position tempPosList[5];

    for (int i = 0; i < 10; i++) {
        reader.empToClass(readEmp, (tempEmpList + i));
    }
    for (int i = 0; i < 5; i++) {
        reader.posToClass(readPos, (tempPosList + i));
    }

    for (int i = 0; i < 10; i++) {
        if (persDepCount % 3 == 0 && persDepCount != 0) {
            system("PAUSE");
            system("cls");
        }
        cout << "��� ����������: " << (tempEmpList + i)->empCode << endl;
        (persDepList + i)->empCode = (tempEmpList + i)->empCode;
        cout << "���: " << (tempEmpList + i)->FIO << endl;
        (persDepList + i)->FIO = (tempEmpList + i)->FIO;
        cout << "�������: " << (tempEmpList + i)->age << endl;
        (persDepList + i)->age = (tempEmpList + i)->age;
        cout << "���: " << (tempEmpList + i)->gender << endl;
        (persDepList + i)->gender = (tempEmpList + i)->gender;
        cout << "�����: " << (tempEmpList + i)->adress << endl;
        (persDepList + i)->adress = (tempEmpList + i)->adress;
        cout << "�������: " << (tempEmpList + i)->phone << endl;
        (persDepList + i)->phone = (tempEmpList + i)->phone;
        cout << "���������� ������: " << (tempEmpList + i)->passport << endl;
        (persDepList + i)->passport = (tempEmpList + i)->passport;
        for (int k = 0; k < 5; k++) {
            if ((tempEmpList + i)->posCode == (tempPosList + k)->posCode) {
                cout << "��������� ����������: " << (tempPosList + k)->posName << endl;
                (persDepList + i)->posName = (tempPosList + k)->posName;
                (persDepList + i)->posCode = (tempEmpList + i)->posCode;
            }
            else
                cout << "��������� � ������ ����� �� �������" << endl;
        }
        cout << endl;
        
        persDepCount++;
    }
}

void Query::musicArc(Record* recList, Author* autList, Genre* genList, MusicArchieve* musicArcList) {
    system("cls");
    TableToClass reader;
    int musicArcCount = 0;

    fstream readRec("reco.txt", ios::in);
    Record tempRecList[10];

    fstream readAut("auth.txt", ios::in);
    Author tempAutList[5];

    fstream readGen("genr.txt", ios::in);
    Genre tempGenList[5];

    for (int i = 0; i < 10; i++) {
        reader.recToClass(readRec, (tempRecList + i));
    }
    for (int i = 0; i < 5; i++) {
        reader.autToClass(readAut, (tempAutList + i));
    }
    for (int i = 0; i < 5; i++) {
        reader.genToClass(readGen, (tempGenList + i));
    }

    for (int i = 0; i < 10; i++) {
        if (musicArcCount % 2 == 0 && musicArcCount != 0) {
            system("PAUSE");
            system("cls");
        }
        cout << "��� ������: " << (tempRecList + i)->recCode << endl;
        (musicArcList + i)->recCode = (tempRecList + i)->recCode;
        cout << "������������: " << (tempRecList + i)->recName << endl;
        (musicArcList + i)->recName = (tempRecList + i)->recName;
        for (int k = 0; k < 5; k++) {
            if ((tempRecList + i)->autCode == (tempAutList + k)->autCode) {
                cout << "�����������: " << (tempAutList + k)->autName << endl;
                (musicArcList + i)->autCode = (tempAutList + k)->autCode;
                (musicArcList + i)->autName = (tempAutList + k)->autName;
            }
            else
                cout << "����������� � ������ ����� �� ������" << endl;
        }
        cout << "������: " << (tempRecList + i)->album << endl;
        (musicArcList + i)->album = (tempRecList + i)->album;
        cout << "���: " << (tempRecList + i)->year << endl;
        (musicArcList + i)->year = (tempRecList + i)->year;
        for (int k = 0; k < 5; k++) {
            if ((tempRecList + i)->genCode == (tempGenList + k)->genCode) {
                cout << "����: " << (tempGenList + k)->genName << endl;
                (musicArcList + i)->genCode = (tempGenList + k)->genCode;
                (musicArcList + i)->genName = (tempGenList + k)->genName;
            }
            else
                cout << "���� � ������ ����� �� ������" << endl;
        }
        cout << "���� ������: " << (tempRecList + i)->recDate << endl;
        (musicArcList + i)->recDate = (tempRecList + i)->recDate;
        cout << "������������: " << (tempRecList + i)->duration << endl;
        (musicArcList + i)->duration = (tempRecList + i)->duration;
        cout << "�������: " << (tempRecList + i)->rating << endl;
        (musicArcList + i)->rating = (tempRecList + i)->rating;
        cout << endl;

        musicArcCount++;
    }
}

void Query::broadGrid(Schedule* schList, Employee* empList, Record* recList, BroadcastingGrid* broadGridList) {
    system("cls");
    TableToClass reader;
    int broadGridCount = 0;

    fstream readSch("sche.txt", ios::in);
    Schedule tempSchList[10];

    fstream readEmp("empl.txt", ios::in);
    Employee tempEmpList[10];

    fstream readRec("reco.txt", ios::in);
    Record tempRecList[10];

    for (int i = 0; i < 10; i++) {
        reader.schToClass(readSch, (tempSchList + i));
    }
    for (int i = 0; i < 10; i++) {
        reader.empToClass(readEmp, (tempEmpList + i));
    }
    for (int i = 0; i < 10; i++) {
        reader.recToClass(readRec, (tempRecList + i));
    }

    for (int i = 0; i < 10; i++) {
        if (broadGridCount % 3 == 0 && broadGridCount != 0) {
            system("PAUSE");
            system("cls");
        }
        cout << "����: " << (tempSchList + i)->schDate << endl;
        (broadGridList + i)->schDate = (tempSchList + i)->schDate;
        for (int k = 0; k < 10; k++) {
            if ((tempSchList + i)->empCode == (tempEmpList + k)->empCode) {
                cout << "���������: " << (tempEmpList + k)->FIO << endl;
                (broadGridList + i)->empCode = (tempEmpList + k)->empCode;
                (broadGridList + i)->FIO = (tempEmpList + k)->FIO;
            }
            else
                cout << "��������� � ������ ����� �� ������" << endl;
            }
        cout << "����� 1: " << (tempSchList + i)->time1 << endl;
        (broadGridList + i)->time1 = (tempSchList + i)->time1;
        for (int k = 0; k < 10; k++) {
            if ((tempSchList + i)->recCode1 == (tempRecList + k)->recCode) {
                cout << "������ 1: " << (tempRecList + k)->recName << endl;
                (broadGridList + i)->recCode1 = (tempRecList + k)->recCode;
                (broadGridList + i)->recName1 = (tempRecList + k)->recName;
            }
            else
                cout << "������ � ������ ����� �� �������" << endl;
        }
        cout << "����� 2: " << (tempSchList + i)->time2 << endl;
        (broadGridList + i)->time2 = (tempSchList + i)->time2;
        for (int k = 0; k < 10; k++) {
            if ((tempSchList + i)->recCode2 == (tempRecList + k)->recCode) {
                cout << "������ 2: " << (tempRecList + k)->recName << endl;
                (broadGridList + i)->recCode2 = (tempRecList + k)->recCode;
                (broadGridList + i)->recName2 = (tempRecList + k)->recName;
            }
            else
                cout << "������ � ������ ����� �� �������" << endl;
        }
        cout << "����� 3: " << (tempSchList + i)->time3 << endl;
        (broadGridList + i)->time3 = (tempSchList + i)->time3;
        for (int k = 0; k < 10; k++) {
            if ((tempSchList + i)->recCode3 == (tempRecList + k)->recCode) {
                cout << "������ 3: " << (tempEmpList + k)->FIO << endl;
                (broadGridList + i)->recCode3 = (tempRecList + k)->recCode;
                (broadGridList + i)->recName3 = (tempRecList + k)->recName;
            }
            else
                cout << "������ � ������ ����� �� �������" << endl;
        }
        cout << endl;

        broadGridCount++;
    }
}