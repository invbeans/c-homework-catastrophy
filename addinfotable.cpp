#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>

#include "addinfotable.h"
#include "commonfuncs.h"
#include "tabletofile.h"

#include "employee.h"
#include "author.h"
#include "schedule.h"
#include "genre.h"
#include "position.h"
#include "record.h"

using namespace std;

void AddInfoTable::addEmp(Employee* lst) {
    system("cls");
    CommonFuncs function;
    TableToFile writer;

    string fileName;
    fstream fout;
    fstream fin;
    fileName = function.streamCheck(fout, fin);
    system("cls");

    char choiceAction;
    bool inputCheck = true, sameEmpCode = false;
    string tempEmpCode, tempFIO, tempAge, tempGender, tempAdress, tempPhone, tempPassport, tempPosCode;

    while (inputCheck) {
        int noteNum = -1;
        for (int i = 0; i < 10; i++) {
            if ((lst + i)->posCode.empty()) noteNum = i;
        }

        if (noteNum == -1) { cout << "Таблица переполнена (10 записей). Удалите предыдущие записи, чтобы ввести новые"; break; }
        cout << "Введите код сотрудника: "; cin >> tempEmpCode;
        string cmpEmpCode;
        for (int i = 0; i < 10; i++) {
            getline(fin, cmpEmpCode);
            if (cmpEmpCode == "") break;
            cmpEmpCode.erase(8);
            if (cmpEmpCode.length() < 8) for (int i = 0; i < 7; i++) cmpEmpCode += ' ';
            if (cmpEmpCode == (lst + i)->empCode) { sameEmpCode = true; break; }
        }
        if (sameEmpCode) {
            cout << "Код такого сотрудника уже присутствует в таблице" << endl;
            cout << "Повторить ввод?(Y/N) "; cin >> choiceAction;
            sameEmpCode = false;
            if (choiceAction != 'Y') break;
            else { system("PAUSE"); continue; }
        }
        cout << "Вы ввели <<" << tempEmpCode << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->empCode = tempEmpCode; }

        cin.ignore();
        cout << "ФИО: "; getline(cin, tempFIO);
        cout << "Вы ввели <<" << tempFIO << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->FIO = tempFIO; }

        cout << "Возраст: "; cin >> tempAge;
        cout << "Вы ввели <<" << tempAge << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->age = tempAge; }

        cout << "Пол: "; cin >> tempGender;
        cout << "Вы ввели <<" << tempGender << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->gender = tempGender; }

        cin.ignore();
        cout << "Адрес: "; getline(cin, tempAdress);
        cout << "Вы ввели <<" << tempAdress << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->adress = tempAdress; }

        cout << "Телефон: "; cin >> tempPhone;
        cout << "Вы ввели <<" << tempPhone << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->phone = tempPhone; }

        cout << "Паспортные данные: "; cin >> tempPassport;
        cout << "Вы ввели <<" << tempPassport << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->passport = tempPassport; }

        cout << "Код должности: "; cin >> tempPosCode;
        cout << "Вы ввели <<" << tempPosCode << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->posCode = tempPosCode; }


        cout << "Сохранить? (Y) Перезаписать? (E) Отмена? (N)"; cin >> choiceAction;
        if (choiceAction == 'Y') {
            if (noteNum != 0) fout << "\n";
            writer.empToFile(fout, (lst + noteNum));

        }
        if (choiceAction == 'E') { system("PAUSE"); continue; }
        if (choiceAction == 'N') { system("PAUSE"); fin.close(); fout.close(); inputCheck == false; }
        fout.close();
        fin.close();
        system("PAUSE");
        break;
    }

}

void AddInfoTable::addPos(Position* lst) {
    system("cls");
    CommonFuncs function;
    TableToFile writer;

    string fileName;
    fstream fout;
    fstream fin;
    fileName = function.streamCheck(fout, fin);
    system("cls");

    char choiceAction;
    bool inputCheck = true, samePosCode = false;
    string tempPosCode, tempPosName, tempSalary, tempResponses, tempRequires;

    while (inputCheck) {
        int noteNum = -1;
        for (int i = 0; i < 5; i++) {
            if ((lst + i)->posCode.empty()) noteNum = i;
        }

        if (noteNum == -1) { cout << "Таблица переполнена (5 записей). Удалите предыдущие записи, чтобы ввести новые"; break; }
        cout << "Введите код должности: "; cin >> tempPosCode;
        string cmpPosCode;
        for (int i = 0; i < 5; i++) {
            getline(fin, cmpPosCode);
            if (cmpPosCode == "") break;
            cmpPosCode.erase(8);
            if (cmpPosCode.length() < 8) for (int i = 0; i < 7; i++) cmpPosCode += ' ';
            if (cmpPosCode == tempPosCode) { samePosCode = true; break; }
        }
        if (samePosCode) {
            cout << "Код такой должности уже присутствует в таблице" << endl;
            cout << "Повторить ввод?(Y/N) "; cin >> choiceAction;
            samePosCode = false;
            if (choiceAction != 'Y') break;
            else { system("PAUSE"); continue; }
        }
        cout << "Вы ввели <<" << tempPosCode << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->posCode = tempPosCode; }

        cin.ignore();
        cout << "Наименование: "; getline(cin, tempPosName);
        cout << "Вы ввели <<" << tempPosName << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->posName = tempPosName; }

        cout << "Оклад: "; cin >> tempSalary;
        cout << "Вы ввели <<" << tempSalary << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->salary = tempSalary; }

        cin.ignore();
        cout << "Обязанности: "; getline(cin, tempResponses);
        cout << "Вы ввели <<" << tempResponses << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->responses = tempResponses; }

        cin.ignore();
        cout << "Требования: "; getline(cin, tempRequires);
        cout << "Вы ввели <<" << tempRequires << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->requires = tempRequires; }

        cout << "Сохранить? (Y) Перезаписать? (E) Отмена? (N)"; cin >> choiceAction;
        if (choiceAction == 'Y') {
            if (noteNum != 0) fout << "\n";
            writer.posToFile(fout, (lst + noteNum));

        }
        if (choiceAction == 'E') { system("PAUSE"); continue; }
        if (choiceAction == 'N') { system("PAUSE"); fin.close(); fout.close(); inputCheck == false; }
        fout.close();
        fin.close();
        system("PAUSE");
        break;
    }

}

void AddInfoTable::addAut(Author* lst) {
    system("cls");
    CommonFuncs function;
    TableToFile writer;

    string fileName;
    fstream fout;
    fstream fin;
    fileName = function.streamCheck(fout, fin);
    system("cls");

    char choiceAction;
    bool inputCheck = true, sameAutCode = false;
    string tempAutCode, tempAutName, tempDescrip;

    while (inputCheck) {
        int noteNum = -1;
        for (int i = 0; i < 5; i++) {
            if ((lst + i)->autCode.empty()) noteNum = i;
        }

        if (noteNum == -1) { cout << "Таблица переполнена (5 записей). Удалите предыдущие записи, чтобы ввести новые"; break; }
        cout << "Введите код исполнителя: "; cin >> tempAutCode;
        string cmpAutCode;
        for (int i = 0; i < 5; i++) {
            getline(fin, cmpAutCode);
            if (cmpAutCode == "") break;
            cmpAutCode.erase(8);
            if (cmpAutCode.length() < 8) for (int i = 0; i < 7; i++) cmpAutCode += ' ';
            if (cmpAutCode == tempAutCode) { sameAutCode = true; break; }
        }
        if (sameAutCode) {
            cout << "Код такого исполнителя уже присутствует в таблице" << endl;
            cout << "Повторить ввод?(Y/N) "; cin >> choiceAction;
            sameAutCode = false;
            if (choiceAction != 'Y') break;
            else { system("PAUSE"); continue; }
        }
        cout << "Вы ввели <<" << tempAutCode << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->autCode = tempAutCode; }

        cin.ignore();
        cout << "Наименование: "; getline(cin, tempAutName);
        cout << "Вы ввели <<" << tempAutName << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->autName = tempAutName; }

        cin.ignore();
        cout << "Описание: "; getline(cin, tempDescrip);
        cout << "Вы ввели <<" << tempDescrip << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->autDescrip = tempDescrip; }

        cout << "Сохранить? (Y) Перезаписать? (E) Отмена? (N)"; cin >> choiceAction;
        if (choiceAction == 'Y') {
            if (noteNum != 0) fout << "\n";
            writer.autToFile(fout, (lst + noteNum));

        }
        if (choiceAction == 'E') { system("PAUSE"); continue; }
        if (choiceAction == 'N') { system("PAUSE"); fin.close(); fout.close(); inputCheck == false; }
        fout.close();
        fin.close();
        system("PAUSE");
        break;
    }

}

void AddInfoTable::addGen(Genre* lst) {
    system("cls");
    CommonFuncs function;
    TableToFile writer;

    string fileName;
    fstream fout;
    fstream fin;
    fileName = function.streamCheck(fout, fin);
    system("cls");

    char choiceAction;
    bool inputCheck = true, sameGenCode = false;
    string tempGenCode, tempGenName, tempDescrip;

    while (inputCheck) {
        int noteNum = -1;
        for (int i = 0; i < 5; i++) {
            if ((lst + i)->genCode.empty()) noteNum = i;
        }

        if (noteNum == -1) { cout << "Таблица переполнена (5 записей). Удалите предыдущие записи, чтобы ввести новые"; break; }
        cout << "Введите код жанра: "; cin >> tempGenCode;
        string cmpGenCode;
        for (int i = 0; i < 5; i++) {
            getline(fin, cmpGenCode);
            if (cmpGenCode == "") break;
            cmpGenCode.erase(8);
            if (cmpGenCode.length() < 8) for (int i = 0; i < 7; i++) cmpGenCode += ' ';
            if (cmpGenCode == tempGenCode) { sameGenCode = true; break; }
        }
        if (sameGenCode) {
            cout << "Код такого жанра уже присутствует в таблице" << endl;
            cout << "Повторить ввод?(Y/N) "; cin >> choiceAction;
            sameGenCode = false;
            if (choiceAction != 'Y') break;
            else { system("PAUSE"); continue; }
        }
        cout << "Вы ввели <<" << tempGenCode << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->genCode = tempGenCode; }

        cin.ignore();
        cout << "Наименование: "; getline(cin, tempGenName);
        cout << "Вы ввели <<" << tempGenName << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->genName = tempGenName; }

        cin.ignore();
        cout << "Описание: "; getline(cin, tempDescrip);
        cout << "Вы ввели <<" << tempDescrip << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->genDescrip = tempDescrip; }

        cout << "Сохранить? (Y) Перезаписать? (E) Отмена? (N)"; cin >> choiceAction;
        if (choiceAction == 'Y') {
            if (noteNum != 0) fout << "\n";
            writer.genToFile(fout, (lst + noteNum));

        }
        if (choiceAction == 'E') { system("PAUSE"); continue; }
        if (choiceAction == 'N') { system("PAUSE"); fin.close(); fout.close(); inputCheck == false; }
        fout.close();
        fin.close();
        system("PAUSE");
        break;
    }

}

void AddInfoTable::addRec(Record* lst) {
    system("cls");
    CommonFuncs function;
    TableToFile writer;

    string fileName;
    fstream fout;
    fstream fin;
    fileName = function.streamCheck(fout, fin);
    system("cls");

    char choiceAction;
    bool inputCheck = true, sameRecCode = false;
    string tempRecCode, tempRecName, tempAutCode, tempAlbum, tempYear, tempGenCode, tempRecDate, tempDuration, tempRating;

    while (inputCheck) {
        int noteNum = -1;
        for (int i = 0; i < 10; i++) {
            if ((lst + i)->recCode.empty()) noteNum = i;
        }

        if (noteNum == -1) { cout << "Таблица переполнена (10 записей). Удалите предыдущие записи, чтобы ввести новые"; break; }
        cout << "Введите код записи: "; cin >> tempRecCode;
        string cmpRecCode;
        for (int i = 0; i < 10; i++) {
            getline(fin, cmpRecCode);
            if (cmpRecCode == "") break;
            cmpRecCode.erase(8);
            if (cmpRecCode.length() < 8) for (int i = 0; i < 7; i++) cmpRecCode += ' ';
            if (cmpRecCode == tempRecCode) { sameRecCode = true; break; }
        }
        if (sameRecCode) {
            cout << "Код такой записи уже присутствует в таблице" << endl;
            cout << "Повторить ввод?(Y/N) "; cin >> choiceAction;
            sameRecCode = false;
            if (choiceAction != 'Y') break;
            else { system("PAUSE"); continue; }
        }
        cout << "Вы ввели <<" << tempRecCode << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->recCode = tempRecCode; }

        cin.ignore();
        cout << "Наименование: "; getline(cin, tempRecName);
        cout << "Вы ввели <<" << tempRecName << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->recName = tempRecName; }

        cout << "Код исполнителя: "; cin >> tempAutCode;
        cout << "Вы ввели <<" << tempAutCode << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->autCode = tempAutCode; }
        
        cin.ignore();
        cout << "Альбом: "; getline(cin, tempAlbum);
        cout << "Вы ввели <<" << tempAlbum << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->album = tempAlbum; }

        cout << "Год: "; getline(cin, tempYear);
        cout << "Вы ввели <<" << tempYear << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->year = tempYear; }

        cout << "Код жанра: "; cin >> tempAutCode;
        cout << "Вы ввели <<" << tempAutCode << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->autCode = tempAutCode; }

        cout << "Дата записи: "; cin >> tempRecDate;
        cout << "Вы ввели <<" << tempRecDate << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->recDate = tempRecDate; }

        cout << "Длительность: "; cin >> tempDuration;
        cout << "Вы ввели <<" << tempDuration << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->duration = tempDuration; }

        cout << "Рейтинг: "; cin >> tempRating;
        cout << "Вы ввели <<" << tempRating << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->rating = tempRating; }

        cout << "Сохранить? (Y) Перезаписать? (E) Отмена? (N)"; cin >> choiceAction;
        if (choiceAction == 'Y') {
            if (noteNum != 0) fout << "\n";
            writer.recToFile(fout, (lst + noteNum));

        }
        if (choiceAction == 'E') { system("PAUSE"); continue; }
        if (choiceAction == 'N') { system("PAUSE"); fin.close(); fout.close(); inputCheck == false; }
        fout.close();
        fin.close();
        system("PAUSE");
        break;
    }

}

void AddInfoTable::addSch(Schedule* lst) {
    system("cls");
    CommonFuncs function;
    TableToFile writer;

    string fileName;
    fstream fout;
    fstream fin;
    fileName = function.streamCheck(fout, fin);
    system("cls");

    char choiceAction;
    bool inputCheck = true;
    string tempSchDate, tempEmpCode, tempTime1, tempRecCode1, tempTime2, tempRecCode2, tempTime3, tempRecCode3;

    while (inputCheck) {
        int noteNum = -1;
        for (int i = 0; i < 14; i++) {
            if ((lst + i)->schDate.empty()) noteNum = i;
        }

        if (noteNum == -1) { cout << "Таблица переполнена (10 записей). Удалите предыдущие записи, чтобы ввести новые"; break; }
        cout << "Введите дату: "; cin >> tempSchDate;
        cout << "Вы ввели <<" << tempSchDate << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->schDate = tempSchDate; }

        cout << "Код сотрудника: "; getline(cin, tempEmpCode);
        cout << "Вы ввели <<" << tempEmpCode << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->empCode = tempEmpCode; }

        cout << "Время 1: "; cin >> tempTime1;
        cout << "Вы ввели <<" << tempTime1 << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->time1 = tempTime1; }

        cout << "Код записи 1: "; cin >> tempRecCode1;
        cout << "Вы ввели <<" << tempRecCode1 << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->recCode1 = tempRecCode1; }

        cout << "Время 2: "; cin >> tempTime2;
        cout << "Вы ввели <<" << tempTime2 << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->time2 = tempTime2; }

        cout << "Код записи 2: "; cin >> tempRecCode2;
        cout << "Вы ввели <<" << tempRecCode2 << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->recCode2 = tempRecCode2; }

        cout << "Время 3: "; cin >> tempTime3;
        cout << "Вы ввели <<" << tempTime3 << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->time3 = tempTime3; }

        cout << "Код записи 3: "; cin >> tempRecCode3;
        cout << "Вы ввели <<" << tempRecCode3 << ">>, продолжить? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->recCode3 = tempRecCode3; }

        cout << "Сохранить? (Y) Перезаписать? (E) Отмена? (N)"; cin >> choiceAction;
        if (choiceAction == 'Y') {
            if (noteNum != 0) fout << "\n";
            writer.schToFile(fout, (lst + noteNum));

        }
        if (choiceAction == 'E') { system("PAUSE"); continue; }
        if (choiceAction == 'N') { system("PAUSE"); fin.close(); fout.close(); inputCheck == false; }
        fout.close();
        fin.close();
        system("PAUSE");
        break;
    }

}