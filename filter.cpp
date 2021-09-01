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
    cout << "Код сотрудника: " << (persDepList)->empCode << endl;
    cout << "ФИО: " << (persDepList)->FIO << endl;
    cout << "Возраст: " << (persDepList)->age << endl;
    cout << "Пол: " << (persDepList)->gender << endl;
    cout << "Адрес: " << (persDepList)->adress << endl;
    cout << "Телефон: " << (persDepList)->phone << endl;
    cout << "Паспортные данные: " << (persDepList)->passport << endl;
    cout << "Название должности: " << (persDepList)->posName << endl;
    cout << "Код должности: " << (persDepList)->posCode << endl;
    cout << endl;
}

void Filter::persDepPosition(PersonnelDepartment* persDepList) {
    system("cls");
    char choiceSearch;
    bool found = false;
    int printed = 0;
    cout << "Найти должность по коду (C) или по названию (N)?: ";
    cin >> choiceSearch;

    if (choiceSearch == 'C') {
        string findByCode;
        cout << "Введите код для поиска: ";
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
        cout << "Введите название для поиска: ";
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
    if (found == false) cout << "Не удалось найти этого исполнителя" << endl;
}

void musicArcPrinter(MusicArchieve* musicArcList) {
    cout << "Код записи: " << (musicArcList)->recCode << endl;
    cout << "Название записи: " << (musicArcList)->recName << endl;
    cout << "Код автора: " << (musicArcList)->autCode << endl;
    cout << "Наименование автора: " << (musicArcList)->autName << endl;
    cout << "Альбом: " << (musicArcList)->album << endl;
    cout << "Год: " << (musicArcList)->year << endl;
    cout << "Код жанра: " << (musicArcList)->genCode << endl;
    cout << "Наименование жанра: " << (musicArcList)->genName << endl;
    cout << "Дата записи: " << (musicArcList)->recDate << endl;
    cout << "Длительность: " << (musicArcList)->duration << endl;
    cout << "Рейтинг: " << (musicArcList)->rating << endl;
    cout << endl;
}

void Filter::musicArcGenre(MusicArchieve* musicArcList) {
    system("cls");
    char choiceSearch;
    bool found = false;
    int printed = 0;
    cout << "Найти жанр по коду (C) или по названию (N)?: ";
    cin >> choiceSearch;
    
    if (choiceSearch == 'C') {
        string findByCode;
        cout << "Введите код для поиска: ";
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
        cout << "Введите название для поиска: ";
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
    if (found == false) cout << "Не удалось найти этот жанр" << endl;
}

void Filter::musicArcAuthor(MusicArchieve* musicArcList) {
    system("cls");
    char choiceSearch;
    bool found = false;
    int printed = 0;
    cout << "Найти исполнителя по коду (C) или по названию (N)?: ";
    cin >> choiceSearch;

    if (choiceSearch == 'C') {
        string findByCode;
        cout << "Введите код для поиска: ";
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
        cout << "Введите название для поиска: ";
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
    if (found == false) cout << "Не удалось найти этого автора" << endl;
}

void broadGridPrinter(BroadcastingGrid* broadGridList) {
    cout << "Дата: " << (broadGridList)->schDate << endl;
    cout << "Код работника: " << (broadGridList)->empCode << endl;
    cout << "ФИО работника: " << (broadGridList)->FIO << endl;
    cout << "Время 1: " << (broadGridList)->time1 << endl;
    cout << "Код записи 1: " << (broadGridList)->recCode1 << endl;
    cout << "Наименование записи 1: " << (broadGridList)->recName1 << endl;
    cout << "Время 2: " << (broadGridList)->time2 << endl;
    cout << "Код записи 2: " << (broadGridList)->recCode2 << endl;
    cout << "Наименование записи 2: " << (broadGridList)->recName2 << endl;
    cout << "Время 3: " << (broadGridList)->time3 << endl;
    cout << "Код записи 3: " << (broadGridList)->recCode3 << endl;
    cout << "Наименование записи 3: " << (broadGridList)->recName3 << endl;
    cout << endl;
}

void Filter::broadGridDate(BroadcastingGrid* broadGridList) {
    system("cls");
    bool found = false;
    int printed = 0;
    cout << "Найти дату: ";
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

    if (found == false) cout << "Не удалось найти эту дату" << endl;
}

void Filter::broadGridEmployee(BroadcastingGrid* broadGridList) {
    system("cls");
    char choiceSearch;
    bool found = false;
    int printed = 0;
    cout << "Найти сотрудника по коду (C) или по названию (N)?: ";
    cin >> choiceSearch;

    if (choiceSearch == 'C') {
        string findByCode;
        cout << "Введите код для поиска: ";
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
        cout << "Введите ФИО для поиска: ";
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
    if (found == false) cout << "Не удалось найти этого сотрудника" << endl;
}