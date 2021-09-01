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

class DeleteInfoTable : public Employee, public Position, public Author, public Genre, public Record, public Schedule {
public:
	void deleteEmp(Employee* lst);
	void deletePos(Position* lst);
	void deleteAut(Author* lst);
	void deleteGen(Genre* lst);
	void deleteRec(Record* lst);
	void deleteSch(Schedule* lst);
};