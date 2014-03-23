#pragma once

#include "auxillary.h"

class Student {
private:
    vector<unsigned int> IDs;
    unsigned int ID;
    //unsigned int grade;

public:
    Student(unsigned int);
    vector<unsigned int> Courses;

    unsigned int getID(void) const;
};
