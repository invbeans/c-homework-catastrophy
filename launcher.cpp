#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
#include <windows.h>

#include "record.h"
#include "position.h"
#include "employee.h"
#include "schedule.h"
#include "genre.h"
#include "author.h"

#include "addinfotable.h"
#include "editinfotable.h"
#include "deleteinfotable.h"
#include "showinfotable.h"
#include "filter.h"
#include "query.h"
#include "broadcastinggrid.h"
#include "musicarchieve.h"
#include "personneldepartment.h"

using namespace std;

//прототипы функций
void addInfo();
void editInfo();
void deleteInfo();
void showInfo();
void queryTable();
void filterTable();

Employee* employeeList = new Employee[10];
Position* positionList = new Position[5];
Author* authorList = new Author[5];
Genre* genreList = new Genre[5];
Record* recordList = new Record[10];
Schedule* scheduleList = new Schedule[10];

BroadcastingGrid* broadGridList = new BroadcastingGrid[10];
MusicArchieve* musicArcList = new MusicArchieve[10];
PersonnelDepartment* persDepList = new PersonnelDepartment[10];

int main()
{
    system("chcp 1251>null");
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);

    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 850, 500, true);

    cout.setf(ios::left);
    bool mainFinish = false;
    bool firstSeen = true;
    int choice = 0;
    while (!mainFinish) {
        system("cls");
        if (firstSeen) {
            cout << "Разработчик: Васильева Влада Алексеевна 1-ИАИТ-9" << endl << endl;
            cout << "Список таблиц:" << endl;
            cout << "---------------------------" << endl;
            cout << "1: Сотрудники" << endl;
            cout << "2: Должности" << endl;
            cout << "3: Исполнители" << endl;
            cout << "4: Жанры" << endl;
            cout << "5: Записи" << endl;
            cout << "6: График работы" << endl;
            cout << "Выберите действие:____" << endl;
            cout << "---------------------------" << endl;
            system("PAUSE");
        }
        firstSeen = false;
        system("cls");
        cout << "МЕНЮ" << endl;
        cout << "---------------------------" << endl;
        cout << "1: Добавить информацию в файл" << endl;
        cout << "2: Редактировать информацию в файле" << endl;
        cout << "3: Удалить запись из таблицы" << endl;
        cout << "4: Вывести из файла" << endl;
        cout << "5: Запросить из нескольких таблиц" << endl;
        cout << "6: Поиск в таблице по фильтру" << endl;
        cout << "7: Вернуться в главное меню" << endl;
        cout << "Выберите действие:____" << endl;
        cout << "---------------------------" << endl;
        cin >> choice;
        //system("PAUSE");
        switch (choice) {
        case 1: addInfo(); continue;
        case 2: editInfo(); system("PAUSE"); continue;
        case 3: deleteInfo(); continue; //старая концовка была как ниже
        case 4: showInfo(); system("PAUSE"); continue;
        case 5: queryTable(); system("PAUSE"); continue;
        case 6: filterTable(); system("PAUSE"); continue;
        case 7: firstSeen = true; break;
        }
    }
    system("PAUSE");
}

void menuPrint() {
    cout << "----------------------------------------" << endl;
    cout << "1: Сотрудники" << endl;
    cout << "2: Должности" << endl;
    cout << "3: Исполнители" << endl;
    cout << "4: Жанры" << endl;
    cout << "5: Записи" << endl;
    cout << "6: График работы" << endl;
    cout << "7: Вернуться в меню выбора действий" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Выберите действие:_____" << endl;
}

void addInfo() {
    int addChoice = 0;
    system("cls");
    cout << "Выберите таблицу для добавления записи:" << endl;
    menuPrint();
    cin >> addChoice;

    switch (addChoice) {
    case 1: { AddInfoTable action; action.addEmp(employeeList); break;}
    case 2: { AddInfoTable action; action.addPos(positionList); break;}
    case 3: { AddInfoTable action; action.addAut(authorList); break;}
    case 4: { AddInfoTable action; action.addGen(genreList); break;}
    case 5: { AddInfoTable action; action.addRec(recordList); break;}
    case 6: { AddInfoTable action; action.addSch(scheduleList); break;}
    case 7: break;
    }
}

void editInfo() {
    int editChoice = 0;
    system("cls");
    cout << "Выберите таблицу для редактирования записей:" << endl;
    menuPrint();
    cin >> editChoice;

    switch (editChoice) {
    case 1: { EditInfoTable action; action.editEmp(employeeList); break;}
    case 2: { EditInfoTable action; action.editPos(positionList); break;}
    case 3: { EditInfoTable action; action.editAut(authorList); break;}
    case 4: { EditInfoTable action; action.editGen(genreList); break;}
    case 5: { EditInfoTable action; action.editRec(recordList); break;}
    case 6: { EditInfoTable action; action.editSch(scheduleList); break;}
    case 7: break;
    }
}

void deleteInfo() {
    int deleteChoice = 0;
    system("cls");
    cout << "Выберите таблицу для удаления записей:" << endl;
    menuPrint();
    cin >> deleteChoice;

    switch (deleteChoice) {
    case 1: { DeleteInfoTable action; action.deleteEmp(employeeList); break;}
    case 2: { DeleteInfoTable action; action.deletePos(positionList); break;}
    case 3: { DeleteInfoTable action; action.deleteAut(authorList); break;}
    case 4: { DeleteInfoTable action; action.deleteGen(genreList); break;}
    case 5: { DeleteInfoTable action; action.deleteRec(recordList); break;}
    case 6: { DeleteInfoTable action; action.deleteSch(scheduleList); break;}
    case 7: break;
    }
}

void showInfo() {
    int showChoice = 0;
    system("cls");
    cout << "Выберите таблицу для показа записей:" << endl;
    menuPrint();
    cin >> showChoice;

    switch (showChoice) {
    case 1: { ShowInfoTable action; action.showEmp(employeeList); break;}
    case 2: { ShowInfoTable action; action.showPos(positionList); break;}
    case 3: { ShowInfoTable action; action.showAut(authorList); break;}
    case 4: { ShowInfoTable action; action.showGen(genreList); break;}
    case 5: { ShowInfoTable action; action.showRec(recordList); break;}
    case 6: { ShowInfoTable action; action.showSch(scheduleList); break;}
    case 7: break;
    }
}

void queryTable() {
    int queryChoice = 0;
    system("cls");
    cout << "Выберите запрос, который хотите сформировать:" << endl;
    cout << "----------------------------------------" << endl;
    cout << "1: Отдел кадров" << endl;
    cout << "2: Музыкальный архив" << endl;
    cout << "3: Сетка вещания" << endl;
    cout << "4: Вернуться в меню выбора действий" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Выберите действие:_____" << endl;

    cin >> queryChoice;

    switch (queryChoice) {
    case 1: { Query formTable; formTable.persDep(employeeList, positionList, persDepList); break;}
    case 2: { Query formTable; formTable.musicArc(recordList, authorList, genreList, musicArcList); break;}
    case 3: { Query formTable; formTable.broadGrid(scheduleList, employeeList, recordList, broadGridList); break;}
    case 4: break;
    }
}

void filterTable() {
    int filterChoice = 0;
    system("cls");
    cout << "Выберите фильтр, по которому хотите просмотреть таблицы:" << endl;
    cout << "----------------------------------------" << endl;
    cout << "1: Сотрудники отдельных должностей" << endl;
    cout << "2: Записи отдельных исполнителей" << endl;
    cout << "3: Записи отдельных жанров" << endl;
    cout << "4: Сетка вещания по отдельным датам" << endl;
    cout << "5: Сетка вещания по отдельным сотрудникам" << endl;
    cout << "6: Выйти в главное меню" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Выберите действие:_____" << endl;

    cin >> filterChoice;

    switch (filterChoice) {
    case 1: { Query formTable; formTable.persDep(employeeList, positionList, persDepList); Filter filterTab; filterTab.persDepPosition(persDepList); break;}
    case 2: { Query formTable; formTable.musicArc(recordList, authorList, genreList, musicArcList); Filter filterTab; filterTab.musicArcAuthor(musicArcList); break;}
    case 3: { Query formTable; formTable.musicArc(recordList, authorList, genreList, musicArcList); Filter filterTab; filterTab.musicArcGenre(musicArcList); break;}
    case 4: { Query formTable; formTable.broadGrid(scheduleList, employeeList, recordList, broadGridList); Filter filterTab; filterTab.broadGridDate(broadGridList); break;}
    case 5: { Query formTable; formTable.broadGrid(scheduleList, employeeList, recordList, broadGridList); Filter filterTab; filterTab.broadGridEmployee(broadGridList); break;}
    case 6: break;
    }
}
    

