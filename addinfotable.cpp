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

        if (noteNum == -1) { cout << "������� ����������� (10 �������). ������� ���������� ������, ����� ������ �����"; break; }
        cout << "������� ��� ����������: "; cin >> tempEmpCode;
        string cmpEmpCode;
        for (int i = 0; i < 10; i++) {
            getline(fin, cmpEmpCode);
            if (cmpEmpCode == "") break;
            cmpEmpCode.erase(8);
            if (cmpEmpCode.length() < 8) for (int i = 0; i < 7; i++) cmpEmpCode += ' ';
            if (cmpEmpCode == (lst + i)->empCode) { sameEmpCode = true; break; }
        }
        if (sameEmpCode) {
            cout << "��� ������ ���������� ��� ������������ � �������" << endl;
            cout << "��������� ����?(Y/N) "; cin >> choiceAction;
            sameEmpCode = false;
            if (choiceAction != 'Y') break;
            else { system("PAUSE"); continue; }
        }
        cout << "�� ����� <<" << tempEmpCode << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->empCode = tempEmpCode; }

        cin.ignore();
        cout << "���: "; getline(cin, tempFIO);
        cout << "�� ����� <<" << tempFIO << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->FIO = tempFIO; }

        cout << "�������: "; cin >> tempAge;
        cout << "�� ����� <<" << tempAge << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->age = tempAge; }

        cout << "���: "; cin >> tempGender;
        cout << "�� ����� <<" << tempGender << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->gender = tempGender; }

        cin.ignore();
        cout << "�����: "; getline(cin, tempAdress);
        cout << "�� ����� <<" << tempAdress << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->adress = tempAdress; }

        cout << "�������: "; cin >> tempPhone;
        cout << "�� ����� <<" << tempPhone << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->phone = tempPhone; }

        cout << "���������� ������: "; cin >> tempPassport;
        cout << "�� ����� <<" << tempPassport << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->passport = tempPassport; }

        cout << "��� ���������: "; cin >> tempPosCode;
        cout << "�� ����� <<" << tempPosCode << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->posCode = tempPosCode; }


        cout << "���������? (Y) ������������? (E) ������? (N)"; cin >> choiceAction;
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

        if (noteNum == -1) { cout << "������� ����������� (5 �������). ������� ���������� ������, ����� ������ �����"; break; }
        cout << "������� ��� ���������: "; cin >> tempPosCode;
        string cmpPosCode;
        for (int i = 0; i < 5; i++) {
            getline(fin, cmpPosCode);
            if (cmpPosCode == "") break;
            cmpPosCode.erase(8);
            if (cmpPosCode.length() < 8) for (int i = 0; i < 7; i++) cmpPosCode += ' ';
            if (cmpPosCode == tempPosCode) { samePosCode = true; break; }
        }
        if (samePosCode) {
            cout << "��� ����� ��������� ��� ������������ � �������" << endl;
            cout << "��������� ����?(Y/N) "; cin >> choiceAction;
            samePosCode = false;
            if (choiceAction != 'Y') break;
            else { system("PAUSE"); continue; }
        }
        cout << "�� ����� <<" << tempPosCode << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->posCode = tempPosCode; }

        cin.ignore();
        cout << "������������: "; getline(cin, tempPosName);
        cout << "�� ����� <<" << tempPosName << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->posName = tempPosName; }

        cout << "�����: "; cin >> tempSalary;
        cout << "�� ����� <<" << tempSalary << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->salary = tempSalary; }

        cin.ignore();
        cout << "�����������: "; getline(cin, tempResponses);
        cout << "�� ����� <<" << tempResponses << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->responses = tempResponses; }

        cin.ignore();
        cout << "����������: "; getline(cin, tempRequires);
        cout << "�� ����� <<" << tempRequires << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->requires = tempRequires; }

        cout << "���������? (Y) ������������? (E) ������? (N)"; cin >> choiceAction;
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

        if (noteNum == -1) { cout << "������� ����������� (5 �������). ������� ���������� ������, ����� ������ �����"; break; }
        cout << "������� ��� �����������: "; cin >> tempAutCode;
        string cmpAutCode;
        for (int i = 0; i < 5; i++) {
            getline(fin, cmpAutCode);
            if (cmpAutCode == "") break;
            cmpAutCode.erase(8);
            if (cmpAutCode.length() < 8) for (int i = 0; i < 7; i++) cmpAutCode += ' ';
            if (cmpAutCode == tempAutCode) { sameAutCode = true; break; }
        }
        if (sameAutCode) {
            cout << "��� ������ ����������� ��� ������������ � �������" << endl;
            cout << "��������� ����?(Y/N) "; cin >> choiceAction;
            sameAutCode = false;
            if (choiceAction != 'Y') break;
            else { system("PAUSE"); continue; }
        }
        cout << "�� ����� <<" << tempAutCode << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->autCode = tempAutCode; }

        cin.ignore();
        cout << "������������: "; getline(cin, tempAutName);
        cout << "�� ����� <<" << tempAutName << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->autName = tempAutName; }

        cin.ignore();
        cout << "��������: "; getline(cin, tempDescrip);
        cout << "�� ����� <<" << tempDescrip << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->autDescrip = tempDescrip; }

        cout << "���������? (Y) ������������? (E) ������? (N)"; cin >> choiceAction;
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

        if (noteNum == -1) { cout << "������� ����������� (5 �������). ������� ���������� ������, ����� ������ �����"; break; }
        cout << "������� ��� �����: "; cin >> tempGenCode;
        string cmpGenCode;
        for (int i = 0; i < 5; i++) {
            getline(fin, cmpGenCode);
            if (cmpGenCode == "") break;
            cmpGenCode.erase(8);
            if (cmpGenCode.length() < 8) for (int i = 0; i < 7; i++) cmpGenCode += ' ';
            if (cmpGenCode == tempGenCode) { sameGenCode = true; break; }
        }
        if (sameGenCode) {
            cout << "��� ������ ����� ��� ������������ � �������" << endl;
            cout << "��������� ����?(Y/N) "; cin >> choiceAction;
            sameGenCode = false;
            if (choiceAction != 'Y') break;
            else { system("PAUSE"); continue; }
        }
        cout << "�� ����� <<" << tempGenCode << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->genCode = tempGenCode; }

        cin.ignore();
        cout << "������������: "; getline(cin, tempGenName);
        cout << "�� ����� <<" << tempGenName << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->genName = tempGenName; }

        cin.ignore();
        cout << "��������: "; getline(cin, tempDescrip);
        cout << "�� ����� <<" << tempDescrip << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->genDescrip = tempDescrip; }

        cout << "���������? (Y) ������������? (E) ������? (N)"; cin >> choiceAction;
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

        if (noteNum == -1) { cout << "������� ����������� (10 �������). ������� ���������� ������, ����� ������ �����"; break; }
        cout << "������� ��� ������: "; cin >> tempRecCode;
        string cmpRecCode;
        for (int i = 0; i < 10; i++) {
            getline(fin, cmpRecCode);
            if (cmpRecCode == "") break;
            cmpRecCode.erase(8);
            if (cmpRecCode.length() < 8) for (int i = 0; i < 7; i++) cmpRecCode += ' ';
            if (cmpRecCode == tempRecCode) { sameRecCode = true; break; }
        }
        if (sameRecCode) {
            cout << "��� ����� ������ ��� ������������ � �������" << endl;
            cout << "��������� ����?(Y/N) "; cin >> choiceAction;
            sameRecCode = false;
            if (choiceAction != 'Y') break;
            else { system("PAUSE"); continue; }
        }
        cout << "�� ����� <<" << tempRecCode << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->recCode = tempRecCode; }

        cin.ignore();
        cout << "������������: "; getline(cin, tempRecName);
        cout << "�� ����� <<" << tempRecName << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->recName = tempRecName; }

        cout << "��� �����������: "; cin >> tempAutCode;
        cout << "�� ����� <<" << tempAutCode << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->autCode = tempAutCode; }
        
        cin.ignore();
        cout << "������: "; getline(cin, tempAlbum);
        cout << "�� ����� <<" << tempAlbum << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->album = tempAlbum; }

        cout << "���: "; getline(cin, tempYear);
        cout << "�� ����� <<" << tempYear << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->year = tempYear; }

        cout << "��� �����: "; cin >> tempAutCode;
        cout << "�� ����� <<" << tempAutCode << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->autCode = tempAutCode; }

        cout << "���� ������: "; cin >> tempRecDate;
        cout << "�� ����� <<" << tempRecDate << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->recDate = tempRecDate; }

        cout << "������������: "; cin >> tempDuration;
        cout << "�� ����� <<" << tempDuration << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->duration = tempDuration; }

        cout << "�������: "; cin >> tempRating;
        cout << "�� ����� <<" << tempRating << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->rating = tempRating; }

        cout << "���������? (Y) ������������? (E) ������? (N)"; cin >> choiceAction;
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

        if (noteNum == -1) { cout << "������� ����������� (10 �������). ������� ���������� ������, ����� ������ �����"; break; }
        cout << "������� ����: "; cin >> tempSchDate;
        cout << "�� ����� <<" << tempSchDate << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->schDate = tempSchDate; }

        cout << "��� ����������: "; getline(cin, tempEmpCode);
        cout << "�� ����� <<" << tempEmpCode << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->empCode = tempEmpCode; }

        cout << "����� 1: "; cin >> tempTime1;
        cout << "�� ����� <<" << tempTime1 << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->time1 = tempTime1; }

        cout << "��� ������ 1: "; cin >> tempRecCode1;
        cout << "�� ����� <<" << tempRecCode1 << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->recCode1 = tempRecCode1; }

        cout << "����� 2: "; cin >> tempTime2;
        cout << "�� ����� <<" << tempTime2 << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->time2 = tempTime2; }

        cout << "��� ������ 2: "; cin >> tempRecCode2;
        cout << "�� ����� <<" << tempRecCode2 << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->recCode2 = tempRecCode2; }

        cout << "����� 3: "; cin >> tempTime3;
        cout << "�� ����� <<" << tempTime3 << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->time3 = tempTime3; }

        cout << "��� ������ 3: "; cin >> tempRecCode3;
        cout << "�� ����� <<" << tempRecCode3 << ">>, ����������? (Y) ";
        cin >> choiceAction;
        if (choiceAction != 'Y') continue;
        else { (lst + noteNum)->recCode3 = tempRecCode3; }

        cout << "���������? (Y) ������������? (E) ������? (N)"; cin >> choiceAction;
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