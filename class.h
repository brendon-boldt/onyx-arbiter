#pragma once
#include "auxillary.h"

class Section {
private:

public:
    vector<unsigned int> Roster;
};

class Class {
private:
    unsigned int ID;
    //unsigned int teacherID;
    vector<unsigned int> IDs;

public:
    Class(unsigned int);
    //int sizeLimit;
    unsigned int period;
    vector<unsigned int> Roster; // List of student IDs

    void printRoster(void) const;
    unsigned int getID(void) const;
};
