#pragma once
#include <string>
#include <string.h>

#include "employee.h"
#include "author.h"
#include "schedule.h"
#include "genre.h"
#include "position.h"
#include "record.h"

#include "personneldepartment.h"
#include "musicarchieve.h"
#include "broadcastinggrid.h"

class Query : public Employee, public Position, public Author, public Genre, public Record, public Schedule, public PersonnelDepartment, public MusicArchieve, public BroadcastingGrid{
public:
	void persDep(Employee* empList, Position* posList, PersonnelDepartment* persDepList);
	void musicArc(Record* recList, Author* autList, Genre* genList, MusicArchieve* musicArcList);
	void broadGrid(Schedule* schList, Employee* empList, Record* recList, BroadcastingGrid* broadGridList);
};