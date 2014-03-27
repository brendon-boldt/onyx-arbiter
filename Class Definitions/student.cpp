#include "Headers/includes.h"

Student::Student(unsigned int x) : ID(x) {
}

bool operator== (const Student & a, const Student & b) {
    return a.getID() == b.getID();
}

unsigned int Student::getID(void) const {
    return this->ID;
}
