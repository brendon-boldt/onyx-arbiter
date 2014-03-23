#include "includes.h"



Group::Group() {
}

Group::~Group() {
}

Student Group::getStudent(unsigned int ID) const {
    for(int i = 0; i < this->Students.size(); i++) {
        if(ID == this->Students[i].getID())
            return Students[i];
    }
    return NULL;
}

Class Group::getClass(unsigned int ID) const {
    for(int i = 0; i < this->Classes.size(); i++) {
        if(ID == this->Classes[i].getID())
            return Classes[i];
    }
    return NULL;
}

Group assignClasses(const Group & Arg) {
    Group Base = Arg;
    for(int i = 0; i < Base.Classes.size(); i++) {
        for(int j = 0; j < Base.Students.size(); j++) {
            for(int k = 0; k < Base.Students[j].Courses.size(); k++) {
                if(Base.Students[j].Courses[k] == Base.Classes[i].getID())
                    Base.Classes[i].Roster.push_back(Base.Students[j].getID());
            }
        }
    }
    return Base;
}

Group scheduleClasses(const Group & Arg) {
    Group Base = Arg;

    for(int j = 0; j < Base.Students.size(); j++) {
        int p = 0;
        for(int i = 0; i < Base.Classes.size(); i++) {
            for(int k = 0; k < Base.Students[i].Courses.size(); k++) {
                if(Base.Classes[i].getID() == Base.Students[j].Courses[k] && Base.Classes[i].period == 0) {
                    Base.Classes[i].period = ++p;
                }
                else if(Base.Classes[i].getID() == Base.Students[j].Courses[k]) {
                    p++;
                }
            }
        }
    }
    return Base;
}

Group randomizeGroup(const Group & Arg) {
    Group Base = Arg;
    for(int j = 0; j < Base.Students.size(); j++) {
        shuffle(Base.Classes.begin(),Base.Classes.end(),gen);
        shuffle(Base.Students.begin(),Base.Students.end(),gen);
        for(int i = 0; i < Base.Students.size(); i++) {
            shuffle(Base.Students[i].Courses.begin(),Base.Students[i].Courses.end(),
                    gen);
        }
    }
    return Base;
}

unsigned int getConflicts(const Group & Arg) {
    unsigned int count = 0;
    for(int i = 0; i < Arg.Students.size(); i++) {
        for(int j = 0; j < Arg.Students[i].Courses.size()-1; j++) {
            for(int k = j+1; k < Arg.Students[i].Courses.size(); k++) {
                if(Arg.getClass(Arg.Students[i].Courses[j]).period
                   == Arg.getClass(Arg.Students[i].Courses[k]).period ) {
                    count++;
                }
            }
        }
    }
    return count;
}
