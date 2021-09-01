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
        cout << "������� ��� ���������� ��� ��������������: ";
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
            cout << "��������������� ������ �� �������. ������ ��� ������? (Y/N)";
            cin >> choiceAction;
            if (choiceAction != 'Y') break;
            else { system("PAUSE"); continue; }
        }

        cout << "��� �������������� �������� ��������. ���� ����" << endl;
        cout << "������ �������� ����������, ������� <<ENTER>>" << endl;
        system("PAUSE");
        system("cls");
        bool skipCheck = false;

        cout << "��� ����������: ";
        cout << (lst + noteNum)->FIO << endl;
        getline(cin, tempFIO);
        if (!tempFIO.empty()) {
            cout << "�� ����� <<" << tempFIO << ">>, ����������? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->FIO = tempFIO; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "�������: ";
        cout << (lst + noteNum)->age << endl;
        getline(cin, tempAge);
        if (!tempAge.empty()) {
            cout << "�� ����� <<" << tempAge << ">>, ����������? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->age = tempAge; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "���: ";
        cout << (lst + noteNum)->gender << endl;
        getline(cin, tempGender);
        if (!tempGender.empty()) {
            cout << "�� ����� <<" << tempGender << ">>, ����������? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->gender = tempGender; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "�����: ";
        cout << (lst + noteNum)->adress << endl;
        getline(cin, tempAdress);
        if (!tempAdress.empty()) {
            cout << "�� ����� <<" << tempAdress << ">>, ����������? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->adress = tempAdress; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "�������: ";
        cout << (lst + noteNum)->phone << endl;
        getline(cin, tempPhone);
        if (!tempPhone.empty()) {
            cout << "�� ����� <<" << tempPhone << ">>, ����������? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->phone = tempPhone; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "���������� ������: ";
        cout << (lst + noteNum)->passport << endl;
        getline(cin, tempPassport);
        if (!tempPassport.empty()) {
            cout << "�� ����� <<" << tempPassport << ">>, ����������? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->passport = tempPassport; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "��� ���������: ";
        cout << (lst + noteNum)->posCode << endl;
        getline(cin, tempPosCode);
        if (!tempPosCode.empty()) {
            cout << "�� ����� <<" << tempPosCode << ">>, ����������? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->posCode = tempPosCode; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "���������? (Y) ������������? (E) ������? (N)"; cin >> choiceAction;
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
        cout << "������� ��� ��������� ��� ��������������: ";
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
            cout << "��������������� ������ �� �������. ������ ��� ������? (Y/N)";
            cin >> choiceAction;
            if (choiceAction != 'Y') break;
            else { system("PAUSE"); continue; }
        }

        cout << "��� �������������� �������� ��������. ���� ����" << endl;
        cout << "������ �������� ����������, ������� <<ENTER>>" << endl;
        system("PAUSE");
        system("cls");
        bool skipCheck = false;

        //cin.ignore();
        cout << "������������ ���������: ";
        cout << (lst + noteNum)->posName << endl;
        getline(cin, tempPosName);
        if (!tempPosName.empty()) {
            cout << "�� ����� <<" << tempPosName << ">>, ����������? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->posName = tempPosName; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "�����: ";
        cout << (lst + noteNum)->salary << endl;
        getline(cin, tempSalary);
        if (!tempSalary.empty()) {
            cout << "�� ����� <<" << tempSalary << ">>, ����������? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->salary = tempSalary; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "�����������: ";
        cout << (lst + noteNum)->responses << endl;
        getline(cin, tempResponses);
        if (!tempResponses.empty()) {
            cout << "�� ����� <<" << tempResponses << ">>, ����������? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->responses = tempResponses; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "����������: ";
        cout << (lst + noteNum)->requires << endl;
        getline(cin, tempRequires);
        if (!tempRequires.empty()) {
            cout << "�� ����� <<" << tempRequires << ">>, ����������? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->requires = tempRequires; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "���������? (Y) ������������? (E) ������? (N)"; cin >> choiceAction;
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
        cout << "������� ��� ����������� ��� ��������������: ";
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
            cout << "��������������� ������ �� �������. ������ ��� ������? (Y/N)";
            cin >> choiceAction;
            if (choiceAction != 'Y') break;
            else { system("PAUSE"); continue; }
        }

        cout << "��� �������������� �������� ��������. ���� ����" << endl;
        cout << "������ �������� ����������, ������� <<ENTER>>" << endl;
        system("PAUSE");
        system("cls");
        bool skipCheck = false;

        cout << "������������ �����������: ";
        cout << (lst + noteNum)->autName << endl;
        getline(cin, tempAutName);
        if (!tempAutName.empty()) {
            cout << "�� ����� <<" << tempAutName << ">>, ����������? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->autName = tempAutName; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "��������: ";
        cout << (lst + noteNum)->autDescrip << endl;
        getline(cin, tempAutDescrip);
        if (!tempAutDescrip.empty()) {
            cout << "�� ����� <<" << tempAutDescrip << ">>, ����������? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->autDescrip = tempAutDescrip; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "���������? (Y) ������������? (E) ������? (N)"; cin >> choiceAction;
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
        cout << "������� ��� ����� ��� ��������������: ";
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
            cout << "��������������� ������ �� �������. ������ ��� ������? (Y/N)";
            cin >> choiceAction;
            if (choiceAction != 'Y') break;
            else { system("PAUSE"); continue; }
        }

        cout << "��� �������������� �������� ��������. ���� ����" << endl;
        cout << "������ �������� ����������, ������� <<ENTER>>" << endl;
        system("PAUSE");
        system("cls");
        bool skipCheck = false;

        cout << "������������ �����: ";
        cout << (lst + noteNum)->genName << endl;
        getline(cin, tempGenName);
        if (!tempGenName.empty()) {
            cout << "�� ����� <<" << tempGenName << ">>, ����������? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->genName = tempGenName; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "��������: ";
        cout << (lst + noteNum)->genDescrip << endl;
        getline(cin, tempGenDescrip);
        if (!tempGenDescrip.empty()) {
            cout << "�� ����� <<" << tempGenDescrip << ">>, ����������? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->genDescrip = tempGenDescrip; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "���������? (Y) ������������? (E) ������? (N)"; cin >> choiceAction;
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
        cout << "������� ��� ������ ��� ��������������: ";
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
            cout << "��������������� ������ �� �������. ������ ��� ������? (Y/N)";
            cin >> choiceAction;
            if (choiceAction != 'Y') break;
            else { system("PAUSE"); continue; }
        }

        cout << "��� �������������� �������� ��������. ���� ����" << endl;
        cout << "������ �������� ����������, ������� <<ENTER>>" << endl;
        system("PAUSE");
        system("cls");
        bool skipCheck = false;

        cout << "������������ ������: ";
        cout << (lst + noteNum)->recName << endl;
        getline(cin, tempRecName);
        if (!tempRecName.empty()) {
            cout << "�� ����� <<" << tempRecName << ">>, ����������? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->recName = tempRecName; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "��� �����������: ";
        cout << (lst + noteNum)->autCode << endl;
        getline(cin, tempAutCode);
        if (!tempAutCode.empty()) {
            cout << "�� ����� <<" << tempAutCode << ">>, ����������? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->autCode = tempAutCode; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "������: ";
        cout << (lst + noteNum)->album << endl;
        getline(cin, tempAlbum);
        if (!tempAlbum.empty()) {
            cout << "�� ����� <<" << tempAlbum << ">>, ����������? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->album = tempAlbum; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "���: ";
        cout << (lst + noteNum)->year << endl;
        getline(cin, tempYear);
        if (!tempYear.empty()) {
            cout << "�� ����� <<" << tempYear << ">>, ����������? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->year = tempYear; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "��� �����: ";
        cout << (lst + noteNum)->genCode << endl;
        getline(cin, tempGenCode);
        if (!tempGenCode.empty()) {
            cout << "�� ����� <<" << tempGenCode << ">>, ����������? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->genCode = tempGenCode; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "���� ������: ";
        cout << (lst + noteNum)->recDate << endl;
        getline(cin, tempRecDate);
        if (!tempRecDate.empty()) {
            cout << "�� ����� <<" << tempRecDate << ">>, ����������? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->recDate = tempRecDate; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "������������: ";
        cout << (lst + noteNum)->duration << endl;
        getline(cin, tempDuration);
        if (!tempDuration.empty()) {
            cout << "�� ����� <<" << tempDuration << ">>, ����������? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->duration = tempDuration; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "�������: ";
        cout << (lst + noteNum)->rating << endl;
        getline(cin, tempRating);
        if (!tempRating.empty()) {
            cout << "�� ����� <<" << tempRating << ">>, ����������? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->rating = tempRating; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "���������? (Y) ������������? (E) ������? (N)"; cin >> choiceAction;
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
        cout << "������� ���� ������� ��� ��������������: ";
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
            cout << "��������������� ������ �� �������. ������ ��� ������? (Y/N)";
            cin >> choiceAction;
            if (choiceAction != 'Y') break;
            else { system("PAUSE"); continue; }
        }

        cout << "��� �������������� �������� ��������. ���� ����" << endl;
        cout << "������ �������� ����������, ������� <<ENTER>>" << endl;
        system("PAUSE");
        system("cls");
        bool skipCheck = false;

        cout << "��� ����������: ";
        cout << (lst + noteNum)->empCode << endl;
        getline(cin, tempEmpCode);
        if (!tempEmpCode.empty()) {
            cout << "�� ����� <<" << tempEmpCode << ">>, ����������? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->empCode = tempEmpCode; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "����� 1: ";
        cout << (lst + noteNum)->time1 << endl;
        getline(cin, tempTime1);
        if (!tempTime1.empty()) {
            cout << "�� ����� <<" << tempTime1 << ">>, ����������? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->time1 = tempTime1; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "��� ������ 1: ";
        cout << (lst + noteNum)->recCode1 << endl;
        getline(cin, tempRecCode1);
        if (!tempRecCode1.empty()) {
            cout << "�� ����� <<" << tempRecCode1 << ">>, ����������? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->recCode1 = tempRecCode1; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "����� 2: ";
        cout << (lst + noteNum)->time2 << endl;
        getline(cin, tempTime2);
        if (!tempTime2.empty()) {
            cout << "�� ����� <<" << tempTime2 << ">>, ����������? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->time2 = tempTime2; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "��� ������ 2: ";
        cout << (lst + noteNum)->recCode2 << endl;
        getline(cin, tempRecCode2);
        if (!tempRecCode2.empty()) {
            cout << "�� ����� <<" << tempRecCode2 << ">>, ����������? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->recCode2 = tempRecCode2; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "����� 3: ";
        cout << (lst + noteNum)->time3 << endl;
        getline(cin, tempTime3);
        if (!tempTime3.empty()) {
            cout << "�� ����� <<" << tempTime3 << ">>, ����������? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->time3 = tempTime3; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "��� ������ 3: ";
        cout << (lst + noteNum)->recCode3 << endl;
        getline(cin, tempRecCode3);
        if (!tempRecCode3.empty()) {
            cout << "�� ����� <<" << tempRecCode3 << ">>, ����������? (Y) ";
            cin >> choiceAction;
            skipCheck = false;
            if (choiceAction != 'Y') continue;
            else { (lst + noteNum)->recCode3 = tempRecCode3; }
        }
        else if (!skipCheck) { cin.ignore(); skipCheck = true; }

        cout << "���������? (Y) ������������? (E) ������? (N)"; cin >> choiceAction;
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