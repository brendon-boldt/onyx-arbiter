#include "includes.h"

Student::Student(unsigned int x) : ID(x) {
    for(int i = 0; i < this->IDs.size(); i++)
        assert(this->ID != this->IDs[i]);
    this->IDs.push_back(this->ID);
}

unsigned int Student::getID(void) const {
    return this->ID;
}
