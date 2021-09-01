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
#include "query.h"

class Filter : public Employee, public Position, public Author, public Genre, public Record, public Schedule, public PersonnelDepartment, public MusicArchieve, public BroadcastingGrid {
public:
	void persDepPosition(PersonnelDepartment* persDepList);
	void musicArcAuthor(MusicArchieve* musicArcList);
	void musicArcGenre(MusicArchieve* musicArcList);
	void broadGridDate(BroadcastingGrid* broadGridList);
	void broadGridEmployee(BroadcastingGrid* broadGridList);
};