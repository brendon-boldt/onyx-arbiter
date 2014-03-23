#pragma once

#include "auxillary.h"
#include "group.h"

Group readGroupFromFile(const string &);
vector<unsigned int> readLine(ifstream &);
