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

class EditInfoTable : public Employee, public Position, public Author, public Genre, public Record, public Schedule {
public:
	void editEmp(Employee* lst);
	void editPos(Position* lst);
	void editAut(Author* lst);
	void editGen(Genre* lst);
	void editRec(Record* lst);
	void editSch(Schedule* lst);
};