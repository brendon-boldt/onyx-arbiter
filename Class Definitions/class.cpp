#include "Headers\includes.h"

Section::Section(unsigned int x) : period(x) {
}

Class::Class(unsigned int x) : ID(x) {
}

void Class::createSection(unsigned int x) { // Eventually, this will have to guard against too many sections
    bool flag = false;
    for(int i = 0; i < this->Sections.size(); i++) {
        if(x == this->Sections[i].period)
            flag = true;
    }
    if(!flag)
        this->Sections.push_back(x);
}

/*
/// Write a better way to assign this->ID
Class::Class(unsigned int x) : ID(x) { // Figure out what this means
    for(int i = 0; i < this->IDs.size(); i++)
        assert(this->ID != this->IDs[i]);
    this->IDs.push_back(this->ID);
    this->period = 0;
}
*/

bool operator== (const Class & a, const Class & b) {
    return a.getID() == b.getID();
}

void Class::printRoster(void) const {
    for(int i = 0; i < this->Roster.size(); i++) {
        cout << Roster[i] << " ";
    }
}

unsigned int Class::getID(void) const {
    return this->ID;
}


