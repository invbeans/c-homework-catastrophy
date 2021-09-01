#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "tabletoclass.h"
#include "filter.h"
#include "query.h"

#include "employee.h"
#include "author.h"
#include "schedule.h"
#include "genre.h"
#include "position.h"
#include "record.h"

#include "personneldepartment.h"
#include "musicarchieve.h"
#include "broadcastinggrid.h"

using namespace std;

void persDepPrinter(PersonnelDepartment* persDepList) {
    cout << "��� ����������: " << (persDepList)->empCode << endl;
    cout << "���: " << (persDepList)->FIO << endl;
    cout << "�������: " << (persDepList)->age << endl;
    cout << "���: " << (persDepList)->gender << endl;
    cout << "�����: " << (persDepList)->adress << endl;
    cout << "�������: " << (persDepList)->phone << endl;
    cout << "���������� ������: " << (persDepList)->passport << endl;
    cout << "�������� ���������: " << (persDepList)->posName << endl;
    cout << "��� ���������: " << (persDepList)->posCode << endl;
    cout << endl;
}

void Filter::persDepPosition(PersonnelDepartment* persDepList) {
    system("cls");
    char choiceSearch;
    bool found = false;
    int printed = 0;
    cout << "����� ��������� �� ���� (C) ��� �� �������� (N)?: ";
    cin >> choiceSearch;

    if (choiceSearch == 'C') {
        string findByCode;
        cout << "������� ��� ��� ������: ";
        getline(cin, findByCode);
        for (int i = 0; i < 10; i++) {
            if (printed % 2 == 0 && printed != 0) {
                system("PAUSE");
                system("cls");
            }
            if ((persDepList + i)->posCode == findByCode) {
                found = true;
                persDepPrinter(persDepList + i);
                printed++;
            }
        }
    }

    if (choiceSearch == 'N') {
        string findByName;
        cout << "������� �������� ��� ������: ";
        getline(cin, findByName);
        for (int i = 0; i < 10; i++) {
            if (printed % 2 == 0 && printed != 0) {
                system("PAUSE");
                system("cls");
            }
            if ((persDepList + i)->posName == findByName) {
                found = true;
                persDepPrinter(persDepList + i);
                printed++;
            }
        }
    }
    if (found == false) cout << "�� ������� ����� ����� �����������" << endl;
}

void musicArcPrinter(MusicArchieve* musicArcList) {
    cout << "��� ������: " << (musicArcList)->recCode << endl;
    cout << "�������� ������: " << (musicArcList)->recName << endl;
    cout << "��� ������: " << (musicArcList)->autCode << endl;
    cout << "������������ ������: " << (musicArcList)->autName << endl;
    cout << "������: " << (musicArcList)->album << endl;
    cout << "���: " << (musicArcList)->year << endl;
    cout << "��� �����: " << (musicArcList)->genCode << endl;
    cout << "������������ �����: " << (musicArcList)->genName << endl;
    cout << "���� ������: " << (musicArcList)->recDate << endl;
    cout << "������������: " << (musicArcList)->duration << endl;
    cout << "�������: " << (musicArcList)->rating << endl;
    cout << endl;
}

void Filter::musicArcGenre(MusicArchieve* musicArcList) {
    system("cls");
    char choiceSearch;
    bool found = false;
    int printed = 0;
    cout << "����� ���� �� ���� (C) ��� �� �������� (N)?: ";
    cin >> choiceSearch;
    
    if (choiceSearch == 'C') {
        string findByCode;
        cout << "������� ��� ��� ������: ";
        getline(cin, findByCode);
        for (int i = 0; i < 10; i++) {
            if (printed % 2 == 0 && printed != 0) {
                system("PAUSE");
                system("cls");
            }
            if ((musicArcList + i)->genCode == findByCode) {
                found = true;
                musicArcPrinter(musicArcList + i);
                printed++;
            }
        }
    }

    if (choiceSearch == 'N') {
        string findByName;
        cout << "������� �������� ��� ������: ";
        getline(cin, findByName);
        for (int i = 0; i < 10; i++) {
            if (printed % 2 == 0 && printed != 0) {
                system("PAUSE");
                system("cls");
            }
            if ((musicArcList + i)->genName == findByName) {
                found = true;
                musicArcPrinter(musicArcList + i);
                printed++;
            }
        }
    }
    if (found == false) cout << "�� ������� ����� ���� ����" << endl;
}

void Filter::musicArcAuthor(MusicArchieve* musicArcList) {
    system("cls");
    char choiceSearch;
    bool found = false;
    int printed = 0;
    cout << "����� ����������� �� ���� (C) ��� �� �������� (N)?: ";
    cin >> choiceSearch;

    if (choiceSearch == 'C') {
        string findByCode;
        cout << "������� ��� ��� ������: ";
        getline(cin, findByCode);
        for (int i = 0; i < 10; i++) {
            if (printed % 2 == 0 && printed != 0) {
                system("PAUSE");
                system("cls");
            }
            if ((musicArcList + i)->autCode == findByCode) {
                found = true;
                musicArcPrinter(musicArcList + i);
                printed++;
            }
        }
    }

    if (choiceSearch == 'N') {
        string findByName;
        cout << "������� �������� ��� ������: ";
        getline(cin, findByName);
        for (int i = 0; i < 10; i++) {
            if (printed % 2 == 0 && printed != 0) {
                system("PAUSE");
                system("cls");
            }
            if ((musicArcList + i)->autName == findByName) {
                found = true;
                musicArcPrinter(musicArcList + i);
                printed++;
            }
        }
    }
    if (found == false) cout << "�� ������� ����� ����� ������" << endl;
}

void broadGridPrinter(BroadcastingGrid* broadGridList) {
    cout << "����: " << (broadGridList)->schDate << endl;
    cout << "��� ���������: " << (broadGridList)->empCode << endl;
    cout << "��� ���������: " << (broadGridList)->FIO << endl;
    cout << "����� 1: " << (broadGridList)->time1 << endl;
    cout << "��� ������ 1: " << (broadGridList)->recCode1 << endl;
    cout << "������������ ������ 1: " << (broadGridList)->recName1 << endl;
    cout << "����� 2: " << (broadGridList)->time2 << endl;
    cout << "��� ������ 2: " << (broadGridList)->recCode2 << endl;
    cout << "������������ ������ 2: " << (broadGridList)->recName2 << endl;
    cout << "����� 3: " << (broadGridList)->time3 << endl;
    cout << "��� ������ 3: " << (broadGridList)->recCode3 << endl;
    cout << "������������ ������ 3: " << (broadGridList)->recName3 << endl;
    cout << endl;
}

void Filter::broadGridDate(BroadcastingGrid* broadGridList) {
    system("cls");
    bool found = false;
    int printed = 0;
    cout << "����� ����: ";
    string findByDate;
    getline(cin, findByDate);
    for (int i = 0; i < 10; i++) {
        if (printed % 2 == 0 && printed != 0) {
            system("PAUSE");
            system("cls");
        }
        if ((broadGridList + i)->schDate == findByDate) {
            found = true;
            broadGridPrinter(broadGridList + i);
            printed++;
        }
    }

    if (found == false) cout << "�� ������� ����� ��� ����" << endl;
}

void Filter::broadGridEmployee(BroadcastingGrid* broadGridList) {
    system("cls");
    char choiceSearch;
    bool found = false;
    int printed = 0;
    cout << "����� ���������� �� ���� (C) ��� �� �������� (N)?: ";
    cin >> choiceSearch;

    if (choiceSearch == 'C') {
        string findByCode;
        cout << "������� ��� ��� ������: ";
        getline(cin, findByCode);
        for (int i = 0; i < 10; i++) {
            if (printed % 2 == 0 && printed != 0) {
                system("PAUSE");
                system("cls");
            }
            if ((broadGridList + i)->empCode == findByCode) {
                found = true;
                broadGridPrinter(broadGridList + i);
                printed++;
            }
        }
    }

    if (choiceSearch == 'N') {
        string findByName;
        cout << "������� ��� ��� ������: ";
        getline(cin, findByName);
        for (int i = 0; i < 10; i++) {
            if (printed % 2 == 0 && printed != 0) {
                system("PAUSE");
                system("cls");
            }
            if ((broadGridList + i)->FIO == findByName) {
                found = true;
                broadGridPrinter(broadGridList + i);
                printed++;
            }
        }
    }
    if (found == false) cout << "�� ������� ����� ����� ����������" << endl;
}