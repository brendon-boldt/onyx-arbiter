#pragma once

#include "class.h"
#include "auxillary.h"

class Group {
private:
    vector<unsigned int> IDs;

public:
    Group();
    ~Group();
    vector<Student> Students;
    vector<Class> Classes;
    void createStudent(unsigned int);
    void createClass(unsigned int);

    const Student * getStudent(unsigned int) const;
    const Class   * getClass  (unsigned int) const;
};

Group scheduleClassesAlt (const Group &);
Group scheduleClasses    (const Group &);
Group assignClasses      (const Group &);
Group randomizeGroup     (const Group &);
unsigned int getConflicts(const Group &);
