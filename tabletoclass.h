#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <fstream>

#include "record.h"
#include "position.h"
#include "employee.h"
#include "schedule.h"
#include "genre.h"
#include "author.h"

class TableToClass : public Employee, public Position, public Author, public Genre, public Record, public Schedule {
public:
	void empToClass(std::fstream& fin, Employee* lst);
	void posToClass(std::fstream& fin, Position* lst);
	void autToClass(std::fstream& fin, Author* lst);
	void genToClass(std::fstream& fin, Genre* lst);
	void recToClass(std::fstream& fin, Record* lst);
	void schToClass(std::fstream& fin, Schedule* lst);
};