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

class CommonFuncs : public Employee, public Author {
public:
	std::string streamCheck(std::fstream &fout, std::fstream &fin);
};
