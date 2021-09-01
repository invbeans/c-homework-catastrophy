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

class TableToFile : public Employee, public Position, public Author, public Genre, public Record, public Schedule{
public:
	void empToFile(std::fstream& fout, Employee* lst);
	void posToFile(std::fstream& fout, Position* lst);
	void autToFile(std::fstream& fout, Author* lst);
	void genToFile(std::fstream& fout, Genre* lst);
	void recToFile(std::fstream& fout, Record* lst);
	void schToFile(std::fstream& fout, Schedule* lst);
};
