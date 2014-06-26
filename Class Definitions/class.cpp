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

bool Class::sectionExists(unsigned int x) {
    for(int i = 0; i < this->Sections.size(); i++) {
        if(this->Sections[i].period == x)
            return true;
    }
    return false;
}

bool operator== (const Class & a, const Class & b) {
    return a.getID() == b.getID();
}

unsigned int Class::getID(void) const {
    return this->ID;
}


