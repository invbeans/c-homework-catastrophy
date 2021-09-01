#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>

#include "editinfotable.h"
#include "commonfuncs.h"
#include "tabletoclass.h"
#include "tabletofile.h"

#include "employee.h"
#include "author.h"
#include "schedule.h"
#include "genre.h"
#include "position.h"
#include "record.h"

using namespace std;

void EditInfoTable::editEmp(Employee* lst) {
    system("cls");
    CommonFuncs function;
    TableToClass reader;
    TableToFile writer;

    string fileName;
    fstream fout;
    fstream fin;
    fileName = function.streamCheck(fout, fin);
    system("cls");

    char choiceAction;
    bool inputCheck = true;
    string tempEmpCode, tempFIO, tempAge, tempGender, tempAdress, tempPhone, tempPassport, tempPosCode;
    
    while (inputCheck) {
        string findByCode;
        cout << "Введите код сотрудника для редактирования: ";
        getline(cin, findByCode);
        if (findByCode.length() < 8) for (int i = 0; i < 7; i++) findByCode += ' ';
        int noteNum = -1;
        
        for (int i = 0; i < 10; i++) {
            if (fin.peek() != EOF) {
                reader.empToClass(fin, lst + i);
                if (findByCode == (lst + i)->empCode) { noteNum = i; }
            }
        }

        if (noteNum == -1) {
            cout << "Соответствующая запись не найдена. Ввести код заново? (Y/N)";
            cin >> choiceAction;
            if (choiceAction != 'Y') break;
            else { system("PAUSE"); continue; }
        }

        cout << "Для редактирования напишите значение. Если поле" << endl;
        cout << "должно остаться неизменным, нажмите <<ENTER>>" << endl;
        system("PAUSE");
        system("cls");
        bool skipCheck = false;

        cout << "ФИО сотрудника: ";
        cout << (lst + noteNum)->FIO << endl;
        getline(cin, tempFIO);
        if (!tempFIO.empty()) {
            cout << "Вы ввели <<" << tempFIO << ">>, продолжить? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->FIO = tempFIO; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "Возраст: ";
        cout << (lst + noteNum)->age << endl;
        getline(cin, tempAge);
        if (!tempAge.empty()) {
            cout << "Вы ввели <<" << tempAge << ">>, продолжить? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->age = tempAge; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "Пол: ";
        cout << (lst + noteNum)->gender << endl;
        getline(cin, tempGender);
        if (!tempGender.empty()) {
            cout << "Вы ввели <<" << tempGender << ">>, продолжить? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->gender = tempGender; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "Адрес: ";
        cout << (lst + noteNum)->adress << endl;
        getline(cin, tempAdress);
        if (!tempAdress.empty()) {
            cout << "Вы ввели <<" << tempAdress << ">>, продолжить? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->adress = tempAdress; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "Телефон: ";
        cout << (lst + noteNum)->phone << endl;
        getline(cin, tempPhone);
        if (!tempPhone.empty()) {
            cout << "Вы ввели <<" << tempPhone << ">>, продолжить? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->phone = tempPhone; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "Паспортные данные: ";
        cout << (lst + noteNum)->passport << endl;
        getline(cin, tempPassport);
        if (!tempPassport.empty()) {
            cout << "Вы ввели <<" << tempPassport << ">>, продолжить? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->passport = tempPassport; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "Код должности: ";
        cout << (lst + noteNum)->posCode << endl;
        getline(cin, tempPosCode);
        if (!tempPosCode.empty()) {
            cout << "Вы ввели <<" << tempPosCode << ">>, продолжить? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->posCode = tempPosCode; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "Сохранить? (Y) Перезаписать? (E) Отмена? (N)"; cin >> choiceAction;
        if (choiceAction == 'Y') {
            fout.close();
            fstream newInfo(fileName, ios::out);

            for (int i = 0; i < 10; i++) {
                if (i != 0) newInfo << "\n";
                writer.empToFile(newInfo, (lst + i));
                
            }
            newInfo.close();
            fin.close();
        }
        else if(choiceAction == 'E') { system("PAUSE"); continue; }
        else if(choiceAction == 'N') { system("PAUSE"); fin.close(); fout.close(); inputCheck == false; }
        else { system("PAUSE"); fout.close(); fin.close(); }

        break;
    }

}

void EditInfoTable::editPos(Position* lst) {
    system("cls");
    CommonFuncs function;
    TableToClass reader;
    TableToFile writer;

    string fileName;
    fstream fout;
    fstream fin;
    fileName = function.streamCheck(fout, fin);
    system("cls");

    char choiceAction;
    bool inputCheck = true;
    string tempPosCode, tempPosName, tempSalary, tempResponses, tempRequires;

    while (inputCheck) {
        string findByCode;
        cout << "Введите код должности для редактирования: ";
        getline(cin, findByCode);
        if (findByCode.length() < 8) for (int i = 0; i < 7; i++) findByCode += ' ';
        int noteNum = -1;

        for (int i = 0; i < 5; i++) {
            if (fin.peek() != EOF) {
                reader.posToClass(fin, lst + i);
                if (findByCode == (lst + i)->posCode) { noteNum = i; }
            }
        }

        if (noteNum == -1) {
            cout << "Соответствующая запись не найдена. Ввести код заново? (Y/N)";
            cin >> choiceAction;
            if (choiceAction != 'Y') break;
            else { system("PAUSE"); continue; }
        }

        cout << "Для редактирования напишите значение. Если поле" << endl;
        cout << "должно остаться неизменным, нажмите <<ENTER>>" << endl;
        system("PAUSE");
        system("cls");
        bool skipCheck = false;

        //cin.ignore();
        cout << "Наименование должности: ";
        cout << (lst + noteNum)->posName << endl;
        getline(cin, tempPosName);
        if (!tempPosName.empty()) {
            cout << "Вы ввели <<" << tempPosName << ">>, продолжить? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->posName = tempPosName; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "Оклад: ";
        cout << (lst + noteNum)->salary << endl;
        getline(cin, tempSalary);
        if (!tempSalary.empty()) {
            cout << "Вы ввели <<" << tempSalary << ">>, продолжить? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->salary = tempSalary; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "Обязанности: ";
        cout << (lst + noteNum)->responses << endl;
        getline(cin, tempResponses);
        if (!tempResponses.empty()) {
            cout << "Вы ввели <<" << tempResponses << ">>, продолжить? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->responses = tempResponses; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "Требования: ";
        cout << (lst + noteNum)->requires << endl;
        getline(cin, tempRequires);
        if (!tempRequires.empty()) {
            cout << "Вы ввели <<" << tempRequires << ">>, продолжить? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->requires = tempRequires; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "Сохранить? (Y) Перезаписать? (E) Отмена? (N)"; cin >> choiceAction;
        if (choiceAction == 'Y') {
            fout.close();
            fstream newInfo(fileName, ios::out);

            for (int i = 0; i < 5; i++) {
                if (i != 0) newInfo << "\n";
                writer.posToFile(newInfo, (lst + i));

            }
            newInfo.close();
            fin.close();
        }
        else if (choiceAction == 'E') { system("PAUSE"); continue; }
        else if (choiceAction == 'N') { system("PAUSE"); fin.close(); fout.close(); inputCheck == false; }
        else { system("PAUSE"); fout.close(); fin.close(); }

        break;
    }

}

void EditInfoTable::editAut(Author* lst) {
    system("cls");
    CommonFuncs function;
    TableToClass reader;
    TableToFile writer;

    string fileName;
    fstream fout;
    fstream fin;
    fileName = function.streamCheck(fout, fin);
    system("cls");

    char choiceAction;
    bool inputCheck = true;
    string tempAutCode, tempAutName, tempAutDescrip;

    while (inputCheck) {
        string findByCode;
        cout << "Введите код исполнителя для редактирования: ";
        getline(cin, findByCode);
        if (findByCode.length() < 8) for (int i = 0; i < 7; i++) findByCode += ' ';
        int noteNum = -1;

        for (int i = 0; i < 5; i++) {
            if (fin.peek() != EOF) {
                reader.autToClass(fin, lst + i);
                if (findByCode == (lst + i)->autCode) { noteNum = i; }
            }
        }

        if (noteNum == -1) {
            cout << "Соответствующая запись не найдена. Ввести код заново? (Y/N)";
            cin >> choiceAction;
            if (choiceAction != 'Y') break;
            else { system("PAUSE"); continue; }
        }

        cout << "Для редактирования напишите значение. Если поле" << endl;
        cout << "должно остаться неизменным, нажмите <<ENTER>>" << endl;
        system("PAUSE");
        system("cls");
        bool skipCheck = false;

        cout << "Наименование исполнителя: ";
        cout << (lst + noteNum)->autName << endl;
        getline(cin, tempAutName);
        if (!tempAutName.empty()) {
            cout << "Вы ввели <<" << tempAutName << ">>, продолжить? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->autName = tempAutName; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "Описание: ";
        cout << (lst + noteNum)->autDescrip << endl;
        getline(cin, tempAutDescrip);
        if (!tempAutDescrip.empty()) {
            cout << "Вы ввели <<" << tempAutDescrip << ">>, продолжить? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->autDescrip = tempAutDescrip; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "Сохранить? (Y) Перезаписать? (E) Отмена? (N)"; cin >> choiceAction;
        if (choiceAction == 'Y') {
            fout.close();
            fstream newInfo(fileName, ios::out);

            for (int i = 0; i < 5; i++) {
                if (i != 0) newInfo << "\n";
                writer.autToFile(newInfo, (lst + i));

            }
            newInfo.close();
            fin.close();
        }
        else if (choiceAction == 'E') { system("PAUSE"); continue; }
        else if (choiceAction == 'N') { system("PAUSE"); fin.close(); fout.close(); inputCheck == false; }
        else { system("PAUSE"); fout.close(); fin.close(); }

        break;
    }

}

void EditInfoTable::editGen(Genre* lst) {
    system("cls");
    CommonFuncs function;
    TableToClass reader;
    TableToFile writer;

    string fileName;
    fstream fout;
    fstream fin;
    fileName = function.streamCheck(fout, fin);
    system("cls");

    char choiceAction;
    bool inputCheck = true;
    string tempGenCode, tempGenName, tempGenDescrip;

    while (inputCheck) {
        string findByCode;
        cout << "Введите код жанра для редактирования: ";
        getline(cin, findByCode);
        if (findByCode.length() < 8) for (int i = 0; i < 7; i++) findByCode += ' ';
        int noteNum = -1;

        for (int i = 0; i < 5; i++) {
            if (fin.peek() != EOF) {
                reader.genToClass(fin, lst + i);
                if (findByCode == (lst + i)->genCode) { noteNum = i; }
            }
        }

        if (noteNum == -1) {
            cout << "Соответствующая запись не найдена. Ввести код заново? (Y/N)";
            cin >> choiceAction;
            if (choiceAction != 'Y') break;
            else { system("PAUSE"); continue; }
        }

        cout << "Для редактирования напишите значение. Если поле" << endl;
        cout << "должно остаться неизменным, нажмите <<ENTER>>" << endl;
        system("PAUSE");
        system("cls");
        bool skipCheck = false;

        cout << "Наименование жанра: ";
        cout << (lst + noteNum)->genName << endl;
        getline(cin, tempGenName);
        if (!tempGenName.empty()) {
            cout << "Вы ввели <<" << tempGenName << ">>, продолжить? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->genName = tempGenName; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "Описание: ";
        cout << (lst + noteNum)->genDescrip << endl;
        getline(cin, tempGenDescrip);
        if (!tempGenDescrip.empty()) {
            cout << "Вы ввели <<" << tempGenDescrip << ">>, продолжить? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->genDescrip = tempGenDescrip; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "Сохранить? (Y) Перезаписать? (E) Отмена? (N)"; cin >> choiceAction;
        if (choiceAction == 'Y') {
            fout.close();
            fstream newInfo(fileName, ios::out);

            for (int i = 0; i < 5; i++) {
                if (i != 0) newInfo << "\n";
                writer.genToFile(newInfo, (lst + i));

            }
            newInfo.close();
            fin.close();
        }
        else if (choiceAction == 'E') { system("PAUSE"); continue; }
        else if (choiceAction == 'N') { system("PAUSE"); fin.close(); fout.close(); inputCheck == false; }
        else { system("PAUSE"); fout.close(); fin.close(); }

        break;
    }

}

void EditInfoTable::editRec(Record* lst) {
    system("cls");
    CommonFuncs function;
    TableToClass reader;
    TableToFile writer;

    string fileName;
    fstream fout;
    fstream fin;
    fileName = function.streamCheck(fout, fin);
    system("cls");

    char choiceAction;
    bool inputCheck = true;
    string tempRecCode, tempRecName, tempAutCode, tempAlbum, tempYear, tempGenCode, tempRecDate, tempDuration, tempRating;

    while (inputCheck) {
        string findByCode;
        cout << "Введите код записи для редактирования: ";
        getline(cin, findByCode);
        if (findByCode.length() < 8) for (int i = 0; i < 7; i++) findByCode += ' ';
        int noteNum = -1;

        for (int i = 0; i < 10; i++) {
            if (fin.peek() != EOF) {
                reader.recToClass(fin, lst + i);
                if (findByCode == (lst + i)->recCode) { noteNum = i; }
            }
        }

        if (noteNum == -1) {
            cout << "Соответствующая запись не найдена. Ввести код заново? (Y/N)";
            cin >> choiceAction;
            if (choiceAction != 'Y') break;
            else { system("PAUSE"); continue; }
        }

        cout << "Для редактирования напишите значение. Если поле" << endl;
        cout << "должно остаться неизменным, нажмите <<ENTER>>" << endl;
        system("PAUSE");
        system("cls");
        bool skipCheck = false;

        cout << "Наименование записи: ";
        cout << (lst + noteNum)->recName << endl;
        getline(cin, tempRecName);
        if (!tempRecName.empty()) {
            cout << "Вы ввели <<" << tempRecName << ">>, продолжить? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->recName = tempRecName; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "Код исполнителя: ";
        cout << (lst + noteNum)->autCode << endl;
        getline(cin, tempAutCode);
        if (!tempAutCode.empty()) {
            cout << "Вы ввели <<" << tempAutCode << ">>, продолжить? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->autCode = tempAutCode; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "Альбом: ";
        cout << (lst + noteNum)->album << endl;
        getline(cin, tempAlbum);
        if (!tempAlbum.empty()) {
            cout << "Вы ввели <<" << tempAlbum << ">>, продолжить? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->album = tempAlbum; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "Год: ";
        cout << (lst + noteNum)->year << endl;
        getline(cin, tempYear);
        if (!tempYear.empty()) {
            cout << "Вы ввели <<" << tempYear << ">>, продолжить? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->year = tempYear; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "Код жанра: ";
        cout << (lst + noteNum)->genCode << endl;
        getline(cin, tempGenCode);
        if (!tempGenCode.empty()) {
            cout << "Вы ввели <<" << tempGenCode << ">>, продолжить? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->genCode = tempGenCode; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "Дата записи: ";
        cout << (lst + noteNum)->recDate << endl;
        getline(cin, tempRecDate);
        if (!tempRecDate.empty()) {
            cout << "Вы ввели <<" << tempRecDate << ">>, продолжить? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->recDate = tempRecDate; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "Длительность: ";
        cout << (lst + noteNum)->duration << endl;
        getline(cin, tempDuration);
        if (!tempDuration.empty()) {
            cout << "Вы ввели <<" << tempDuration << ">>, продолжить? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->duration = tempDuration; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "Рейтинг: ";
        cout << (lst + noteNum)->rating << endl;
        getline(cin, tempRating);
        if (!tempRating.empty()) {
            cout << "Вы ввели <<" << tempRating << ">>, продолжить? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->rating = tempRating; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "Сохранить? (Y) Перезаписать? (E) Отмена? (N)"; cin >> choiceAction;
        if (choiceAction == 'Y') {
            fout.close();
            fstream newInfo(fileName, ios::out);

            for (int i = 0; i < 10; i++) {
                if (i != 0) newInfo << "\n";
                writer.recToFile(newInfo, (lst + i));

            }
            newInfo.close();
            fin.close();
        }
        else if (choiceAction == 'E') { system("PAUSE"); continue; }
        else if (choiceAction == 'N') { system("PAUSE"); fin.close(); fout.close(); inputCheck == false; }
        else { system("PAUSE"); fout.close(); fin.close(); }

        break;
    }

}

void EditInfoTable::editSch(Schedule* lst) {
    system("cls");
    CommonFuncs function;
    TableToClass reader;
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
        string findByDate;
        cout << "Введите дату графика для редактирования: ";
        getline(cin, findByDate);
        if (findByDate.length() < 15) for (int i = 0; i < 14; i++) findByDate += ' ';
        int noteNum = -1;

        for (int i = 0; i < 10; i++) {
            if (fin.peek() != EOF) {
                reader.schToClass(fin, lst + i);
                if (findByDate == (lst + i)->schDate) { noteNum = i; }
            }
        }

        if (noteNum == -1) {
            cout << "Соответствующая запись не найдена. Ввести код заново? (Y/N)";
            cin >> choiceAction;
            if (choiceAction != 'Y') break;
            else { system("PAUSE"); continue; }
        }

        cout << "Для редактирования напишите значение. Если поле" << endl;
        cout << "должно остаться неизменным, нажмите <<ENTER>>" << endl;
        system("PAUSE");
        system("cls");
        bool skipCheck = false;

        cout << "Код сотрудника: ";
        cout << (lst + noteNum)->empCode << endl;
        getline(cin, tempEmpCode);
        if (!tempEmpCode.empty()) {
            cout << "Вы ввели <<" << tempEmpCode << ">>, продолжить? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->empCode = tempEmpCode; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "Время 1: ";
        cout << (lst + noteNum)->time1 << endl;
        getline(cin, tempTime1);
        if (!tempTime1.empty()) {
            cout << "Вы ввели <<" << tempTime1 << ">>, продолжить? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->time1 = tempTime1; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "Код записи 1: ";
        cout << (lst + noteNum)->recCode1 << endl;
        getline(cin, tempRecCode1);
        if (!tempRecCode1.empty()) {
            cout << "Вы ввели <<" << tempRecCode1 << ">>, продолжить? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->recCode1 = tempRecCode1; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "Время 2: ";
        cout << (lst + noteNum)->time2 << endl;
        getline(cin, tempTime2);
        if (!tempTime2.empty()) {
            cout << "Вы ввели <<" << tempTime2 << ">>, продолжить? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->time2 = tempTime2; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "Код записи 2: ";
        cout << (lst + noteNum)->recCode2 << endl;
        getline(cin, tempRecCode2);
        if (!tempRecCode2.empty()) {
            cout << "Вы ввели <<" << tempRecCode2 << ">>, продолжить? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->recCode2 = tempRecCode2; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "Время 3: ";
        cout << (lst + noteNum)->time3 << endl;
        getline(cin, tempTime3);
        if (!tempTime3.empty()) {
            cout << "Вы ввели <<" << tempTime3 << ">>, продолжить? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->time3 = tempTime3; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "Код записи 3: ";
        cout << (lst + noteNum)->recCode3 << endl;
        getline(cin, tempRecCode3);
        if (!tempRecCode3.empty()) {
            cout << "Вы ввели <<" << tempRecCode3 << ">>, продолжить? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->recCode3 = tempRecCode3; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "Сохранить? (Y) Перезаписать? (E) Отмена? (N)"; cin >> choiceAction;
        if (choiceAction == 'Y') {
            fout.close();
            fstream newInfo(fileName, ios::out);

            for (int i = 0; i < 10; i++) {
                if (i != 0) newInfo << "\n";
                writer.schToFile(newInfo, (lst + i));

            }
            newInfo.close();
            fin.close();
        }
        else if (choiceAction == 'E') { system("PAUSE"); continue; }
        else if (choiceAction == 'N') { system("PAUSE"); fin.close(); fout.close(); inputCheck == false; }
        else { system("PAUSE"); fout.close(); fin.close(); }

        break;
    }

}