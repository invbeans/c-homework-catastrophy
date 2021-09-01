#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>

#include "deleteinfotable.h"
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

void DeleteInfoTable::deleteEmp(Employee* lst) {
    system("cls");
    CommonFuncs function;
    TableToClass reader;
    TableToFile writer;

    bool inputCheck = true;
    string fileName;
    fstream fout;
    fstream fin;
    fileName = function.streamCheck(fout, fin);
    system("cls");

    char choiceAction;
    
    while (inputCheck) {
        string findByCode;
        cout << "������� ��� ���������� ��� ��������: ";
        //cin.ignore();
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


        cout << "�� ����� ������ ������� ���������� �� ������������: " << endl;
        cout << (lst + noteNum)->FIO << ", (Y/N)?" << endl;
        cin >> choiceAction;
        if (choiceAction != 'Y') break;
        else {
            fout.close();
            fstream newInfo(fileName, ios::out);
            
            for (int i = 0; i < 10; i++) {
                if (i != 0) fout << "\n";
                if (i != noteNum && !(lst + i)->empCode.empty()) {
                    writer.empToFile(newInfo, (lst + i));
                }

            }
            newInfo.close();
            fin.close();
            cout << "������ �������" << endl;
            system("PAUSE");
            break;
        }
    }
}

void DeleteInfoTable::deletePos(Position* lst) {
    system("cls");
    CommonFuncs function;
    TableToClass reader;
    TableToFile writer;

    bool inputCheck = true;
    string fileName;
    fstream fout;
    fstream fin;
    fileName = function.streamCheck(fout, fin);
    system("cls");

    char choiceAction;
    string tempPosCode, tempPosName, tempSalary, tempResponses, tempRequires;

    while (inputCheck) {
        string findByCode;
        cout << "������� ��� ��������� ��� ��������: ";
        //cin.ignore();
        getline(cin, findByCode);
        if (findByCode.length() < 8) for (int i = 0; i < 7; i++) findByCode += ' ';
        int noteNum = -1;

        //fin.seekg(0);
        for (int i = 0; i < 5; i++) {
            if (fin.peek() != EOF) {
                reader.posToClass(fin, (lst + i));
                if (findByCode == (lst + i)->posCode) { noteNum = i; }
            }

        }

        if (noteNum == -1) {
            cout << "��������������� ������ �� �������. ������ ��� ������? (Y/N)";
            cin >> choiceAction;
            if (choiceAction != 'Y') break;
            else { system("PAUSE"); continue; }
        }


        cout << "�� ����� ������ ������� ���������� � ���������: " << endl;
        cout << (lst + noteNum)->posName << ", (Y/N)?" << endl;
        cin >> choiceAction;
        if (choiceAction != 'Y') break;
        else {
            fout.close();
            fstream newInfo(fileName, ios::out);

            for (int i = 0; i < 5; i++) {
                if(i != 0) newInfo << "\n";
                if (i != noteNum && !(lst + i)->posCode.empty()) {
                    writer.posToFile(newInfo, (lst + i));
                }

            }
            
            fstream readEmps("empl.txt", ios::in);
            Employee tempEmpList[10];

            for (int i = 0; i < 10; i++) {
                if (readEmps.peek() != EOF) {
                    reader.empToClass(readEmps, (tempEmpList + i));
                }
            }

            fstream deleteEmps("empl.txt", ios::out);
            for (int i = 0; i < 10; i++) {
                if (i != 0) deleteEmps << "\n";
                if (findByCode == (tempEmpList + i)->posCode) (tempEmpList + i)->posCode = "   ";
                if (!(tempEmpList + i)->empCode.empty()) {
                    writer.empToFile(deleteEmps, (tempEmpList + i));
                }
            }
            deleteEmps.close();
            readEmps.close();
            cout << "������ �������" << endl;
            system("PAUSE");
            break;
        }
    }
}

void DeleteInfoTable::deleteAut(Author* lst) {
    system("cls");
    CommonFuncs function;
    TableToClass reader;
    TableToFile writer;

    bool inputCheck = true;
    string fileName;
    fstream fout;
    fstream fin;
    fileName = function.streamCheck(fout, fin);
    system("cls");

    char choiceAction;
    
    while (inputCheck) {
        string findByCode;
        cout << "������� ��� ����������� ��� ��������: ";

        getline(cin, findByCode);
        if (findByCode.length() < 8) for (int i = 0; i < 7; i++) findByCode += ' ';
        int noteNum = -1;

        for (int i = 0; i < 5; i++) {
            if (fin.peek() != EOF) {
                reader.autToClass(fin, (lst + i));
                if (findByCode == (lst + i)->autCode) { noteNum = i; }
            }
        }

        if (noteNum == -1) {
            cout << "��������������� ������ �� �������. ������ ��� ������? (Y/N)";
            cin >> choiceAction;
            if (choiceAction != 'Y') break;
            else { system("PAUSE"); continue; }
        }


        cout << "�� ����� ������ ������� ���������� �� �����������: " << endl;
        cout << (lst + noteNum)->autName << ", (Y/N)?" << endl;
        cin >> choiceAction;
        if (choiceAction != 'Y') break;
        else {
            fout.close();
            fstream newInfo(fileName, ios::out);

            for (int i = 0; i < 5; i++) {
                if (i != 0) fout << "\n";
                if (i != noteNum && !(lst + i)->autCode.empty()) {
                    writer.autToFile(newInfo, (lst + i));
                }

            }
            newInfo.close();
            fin.close();
            cout << "������ �������" << endl;
            system("PAUSE");
            break;
        }
    }
}

void DeleteInfoTable::deleteGen(Genre* lst) {
    system("cls");
    CommonFuncs function;
    TableToClass reader;
    TableToFile writer;

    bool inputCheck = true;
    string fileName;
    fstream fout;
    fstream fin;
    fileName = function.streamCheck(fout, fin);
    system("cls");

    char choiceAction;

    while (inputCheck) {
        string findByCode;
        cout << "������� ��� ����� ��� ��������: ";

        getline(cin, findByCode);
        if (findByCode.length() < 8) for (int i = 0; i < 7; i++) findByCode += ' ';
        int noteNum = -1;

        for (int i = 0; i < 5; i++) {
            if (fin.peek() != EOF) {
                reader.genToClass(fin, (lst + i));
                if (findByCode == (lst + i)->genCode) { noteNum = i; }
            }
        }

        if (noteNum == -1) {
            cout << "��������������� ������ �� �������. ������ ��� ������? (Y/N)";
            cin >> choiceAction;
            if (choiceAction != 'Y') break;
            else { system("PAUSE"); continue; }
        }


        cout << "�� ����� ������ ������� ���������� �� �����: " << endl;
        cout << (lst + noteNum)->genName << ", (Y/N)?" << endl;
        cin >> choiceAction;
        if (choiceAction != 'Y') break;
        else {
            fout.close();
            fstream newInfo(fileName, ios::out);

            for (int i = 0; i < 5; i++) {
                if (i != 0) fout << "\n";
                if (i != noteNum && !(lst + i)->genCode.empty()) {
                    writer.genToFile(newInfo, (lst + i));
                }

            }
            newInfo.close();
            fin.close();
            cout << "������ �������" << endl;
            system("PAUSE");
            break;
        }
    }
}

void DeleteInfoTable::deleteRec(Record* lst) {
    system("cls");
    CommonFuncs function;
    TableToClass reader;
    TableToFile writer;

    bool inputCheck = true;
    string fileName;
    fstream fout;
    fstream fin;
    fileName = function.streamCheck(fout, fin);
    system("cls");

    char choiceAction;

    while (inputCheck) {
        string findByCode;
        cout << "������� ��� ������ ��� ��������: ";

        getline(cin, findByCode);
        if (findByCode.length() < 8) for (int i = 0; i < 7; i++) findByCode += ' ';
        int noteNum = -1;

        for (int i = 0; i < 10; i++) {
            if (fin.peek() != EOF) {
                reader.recToClass(fin, (lst + i));
                if (findByCode == (lst + i)->recCode) { noteNum = i; }
            }
        }

        if (noteNum == -1) {
            cout << "��������������� ������ �� �������. ������ ��� ������? (Y/N)";
            cin >> choiceAction;
            if (choiceAction != 'Y') break;
            else { system("PAUSE"); continue; }
        }


        cout << "�� ����� ������ ������� ���������� �� ������: " << endl;
        cout << (lst + noteNum)->recName << ", (Y/N)?" << endl;
        cin >> choiceAction;
        if (choiceAction != 'Y') break;
        else {
            fout.close();
            fstream newInfo(fileName, ios::out);

            for (int i = 0; i < 10; i++) {
                if (i != 0) fout << "\n";
                if (i != noteNum && !(lst + i)->recCode.empty()) {
                    writer.recToFile(newInfo, (lst + i));
                }

            }
            newInfo.close();
            fin.close();
            cout << "������ �������" << endl;
            system("PAUSE");
            break;
        }
    }
}

void DeleteInfoTable::deleteSch(Schedule* lst) {
    system("cls");
    CommonFuncs function;
    TableToClass reader;
    TableToFile writer;

    bool inputCheck = true;
    string fileName;
    fstream fout;
    fstream fin;
    fileName = function.streamCheck(fout, fin);
    system("cls");

    char choiceAction;

    while (inputCheck) {
        string findByDate;
        cout << "������� ���� ������� ��� ��������: ";

        getline(cin, findByDate);
        if (findByDate.length() < 15) for (int i = 0; i < 14; i++) findByDate += ' ';
        int noteNum = -1;

        for (int i = 0; i < 10; i++) {
            if (fin.peek() != EOF) {
                reader.schToClass(fin, (lst + i));
                if (findByDate == (lst + i)->schDate) { noteNum = i; }
            }
        }

        if (noteNum == -1) {
            cout << "��������������� ������ �� �������. ������ ��� ������? (Y/N)";
            cin >> choiceAction;
            if (choiceAction != 'Y') break;
            else { system("PAUSE"); continue; }
        }


        cout << "�� ����� ������ ������� ���������� �� ������� ��: " << endl;
        cout << (lst + noteNum)->schDate << " �����, (Y/N)?" << endl;
        cin >> choiceAction;
        if (choiceAction != 'Y') break;
        else {
            fout.close();
            fstream newInfo(fileName, ios::out);

            for (int i = 0; i < 10; i++) {
                if (i != 0) fout << "\n";
                if (i != noteNum && !(lst + i)->schDate.empty()) {
                    writer.schToFile(newInfo, (lst + i));
                }

            }
            newInfo.close();
            fin.close();
            cout << "������ �������" << endl;
            system("PAUSE");
            break;
        }
    }
}