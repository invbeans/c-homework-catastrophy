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

class ShowInfoTable : public Employee, public Position, public Author, public Genre, public Record, public Schedule {
public:
	void showEmp(Employee* lst);
	void showPos(Position* lst);
	void showAut(Author* lst);
	void showGen(Genre* lst);
	void showRec(Record* lst);
	void showSch(Schedule* lst);
};
