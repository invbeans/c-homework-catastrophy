#pragma once
#include <string.h>
#include <string>
#include <fstream>
#include "employee.h"
#include "author.h"
#include "schedule.h"
#include "genre.h"
#include "position.h"
#include "record.h"

class AddInfoTable : public Employee, public Position, public Author, public Genre, public Record, public Schedule{
public:
	void addEmp(Employee* lst);
	void addPos(Position* lst);
	void addAut(Author* lst);
	void addGen(Genre* lst);
	void addRec(Record* lst);
	void addSch(Schedule* lst);
};
