#pragma once
#include "auxillary.h"

class Section {
private:

public:
    Section(unsigned int);
    vector<unsigned int> Roster;
    unsigned int period;
};

class Class {
private:
    unsigned int ID;
    //unsigned int teacherID;
    vector<unsigned int> IDs;

public:
    Class(unsigned int);
    //unsigned int period;
    vector<unsigned int> Roster; // List of student IDs
    vector<Section> Sections;
    void createSection(unsigned int);

    void printRoster(void) const;
    unsigned int getID(void) const;
};
