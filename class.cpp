#include "includes.h"

/// Write a better way to assign this->ID
Class::Class(unsigned int x) : ID(x) {
    for(int i = 0; i < this->IDs.size(); i++)
        assert(this->ID != this->IDs[i]);
    this->IDs.push_back(this->ID);
    this->period = 0;
}

void Class::printRoster(void) const {
    for(int i = 0; i < this->Roster.size(); i++) {
        cout << Roster[i] << " ";
    }
}

unsigned int Class::getID(void) const {
    return this->ID;
}


