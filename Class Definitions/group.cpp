#include "Headers/includes.h"

Group::Group() {
}

Group::~Group() {
}

void Group::createStudent(unsigned int ID) {
    for(unsigned int i = 0; i < this->Students.size(); i++)
        assert(ID != Students[i].getID());
    this->Students.emplace_back(ID);
}

void Group::createClass(unsigned int ID) {
    for(unsigned int i = 0; i < this->Classes.size(); i++)
        assert(ID != Classes[i].getID());
    this->Classes.push_back(ID);
}

const Student * Group::getStudent(unsigned int ID) const {
    for(unsigned int i = 0; i < this->Students.size(); i++) {
        if(ID == this->Students[i].getID())
            return &Students[i];
    }
    return NULL;
}

const Class * Group::getClass(unsigned int ID) const {
    for(unsigned int i = 0; i < this->Classes.size(); i++) {
        if(ID == this->Classes[i].getID())
            return &Classes[i];
    }
    return NULL;
}

Group assignClasses(const Group & Arg) {
    Group Base = Arg;
    for(unsigned int i = 0; i < Base.Classes.size(); i++) {
        for(unsigned int j = 0; j < Base.Students.size(); j++) {
            for(unsigned int k = 0; k < Base.Students[j].Courses.size(); k++) {
                if(Base.Students[j].Courses[k] == Base.Classes[i].getID())
                    Base.Classes[i].Roster.push_back(Base.Students[j].getID());
            }
        }
    }
    return Base;
}

/*
Group scheduleClasses(const Group & Arg) {
    Group Base = Arg;
    for(unsigned int j = 0; j < Base.Students.size(); j++) {
        int p = 0;
        for(unsigned int i = 0; i < Base.Classes.size(); i++) {
            for(unsigned int k = 0; k < Base.Students[i].Courses.size(); k++) {
                if(Base.Classes[i].getID() == Base.Students[j].Courses[k] && Base.Classes[i].period == 0) {
                    Base.Classes[i].period = ++p;
                    Base.Students[j].Schedule.push_back(make_pair(Base.Classes[i].getID(),0));
                } /// Figure out the sectioning
                else if(Base.Classes[i].getID() == Base.Students[j].Courses[k]) {
                    p++;
                    Base.Students[j].Schedule.push_back(make_pair(Base.Classes[i].getID(),0);
                }
            }
        }
    }
    return Base;
}
*/

Group scheduleClasses(const Group & Arg) {
    Group Base = Arg;
    for(unsigned int j = 0; j < Base.Students.size(); j++) {
        int p = 0;
        for(unsigned int i = 0; i < Base.Classes.size(); i++) {
            for(unsigned int k = 0; k < Base.Students[i].Courses.size(); k++) {
                if(Base.Classes[i].getID() == Base.Students[j].Courses[k] && Base.Classes[i].Sections.size() < 3) {
                    Base.Classes[i].createSection(++p);
                    Base.Students[j].Schedule.push_back(make_pair(Base.Classes[i].getID(),p));
                    Base.Classes[i].Sections[Base.Classes[i].Sections.size()-1].Roster.push_back(Base.Students[j].getID());
                }
                else if(Base.Classes[i].getID() == Base.Students[j].Courses[k]) {
                    p++;
                    for(int m = 0; m < Base.Classes[i].Sections.size(); m++) {
                        if(Base.Classes[i].Sections[m].period == p) {
                            Base.Students[j].Schedule.push_back(make_pair(Base.Classes[i].getID(),p));
                            Base.Classes[i].Sections[Base.Classes[i].Sections.size()-1].Roster.push_back(Base.Students[j].getID());
                        }
                    }
                }
            }
        }
    }
    return Base;
}

Group randomizeGroup(const Group & Arg) {
    Group Base = Arg;
    for(unsigned int j = 0; j < Base.Students.size(); j++) {
        shuffle(Base.Classes.begin(),Base.Classes.end(),gen);
        shuffle(Base.Students.begin(),Base.Students.end(),gen);
        for(unsigned int i = 0; i < Base.Students.size(); i++) {
            shuffle(Base.Students[i].Courses.begin(),Base.Students[i].Courses.end(),gen);
        }
    }
    return Base;
}

/*
unsigned int getConflicts(const Group & Arg) {
    unsigned int count = 0;
    for(unsigned int i = 0; i < Arg.Students.size(); i++) {
        for(unsigned int j = 0; j < Arg.Students[i].Courses.size()-1; j++) {
            for(unsigned int k = j+1; k < Arg.Students[i].Courses.size(); k++) {
                if(Arg.getClass(Arg.Students[i].Courses[j])->period
                   == Arg.getClass(Arg.Students[i].Courses[k])->period ) {
                    count++;
                }
            }
        }
    }
    return count;
}
*/

unsigned int getConflicts(const Group & Arg) {
    unsigned int count = 0;
    for(unsigned int i = 0; i < Arg.Students.size(); i++) {
        count += 6 - Arg.Students[i].Schedule.size();
    }
    return count;
}
