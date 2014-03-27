#include "Class Definitions/Headers/includes.h"
#define LIMIT 2

// Should I move this?
mt19937 gen;

void worker(void * Arg) {

    unsigned int minConflicts = INF;
    unsigned int temp;
    Group tempGroup,minGroup;
    unsigned int cycles = 20;
    for(int i = 0; i < cycles; i++) {
    //while(true) {
        tempGroup = scheduleClasses(randomizeGroup(*(Group*)Arg));
        temp = getConflicts(tempGroup);
        if (temp < minConflicts) {
            minConflicts = temp;
            minGroup = tempGroup;
            cout << "\t" << minConflicts << endl;
        }
    }
}





int main() {

    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    gen.seed(t1.time_since_epoch().count());

    Group Academy = readGroupFromFile("pseudo.txt");


    for(int i = 1; i <= 27; i++) {
        Academy.createClass(i);
    }

    Academy = assignClasses(Academy);

    //_beginthread(worker,0,&Academy);

    unsigned int minConflicts = INF;
    //ofstream w("dump.txt",ios_base::out);
    unsigned int temp;
    Group tempGroup,minGroup;
    unsigned int cycles = 20;
    for(int i = 0; i < cycles; i++) {
    //while(true) {
        tempGroup = scheduleClasses(randomizeGroup(Academy));
        temp = getConflicts(tempGroup);

        /*
        for(int i = 0; i < tempGroup.Students.size()-290; i++) {
            w << tempGroup.Students[i].getID() << "\t";
        }
        w << endl;
        */


        //w << temp << endl;
        if (temp < minConflicts) {
            minConflicts = temp;
            minGroup = tempGroup;
            cout << minConflicts << endl;
        }
        //cout << "\r" << i;
    }
    cout << endl;
    cout << minConflicts << endl << endl;

    /*
    for(int i = 0; i < minGroup.Classes.size(); i++) {
        cout << "C" << minGroup.Classes[i].getID() << "\t";
        for(int j = 0; j < minGroup.Classes[i].Sections.size(); j++) {
            cout << minGroup.Classes[i].Sections[j].period << "\t";
        }
        cout << endl;
    }
    */

    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
    cout << endl << "OPS :: " << (float)cycles/time_span.count() << endl;

    for(int i = 0; i < minGroup.Classes.size(); i++) {
        for(int j = 0; j < minGroup.Classes[i].Sections.size(); j++) {
            cout << minGroup.Classes[i].getID()
                 << "."
                 << minGroup.Classes[i].Sections[j].period
                 << "\t"
                 << minGroup.Classes[i].Sections[j].Roster.size()
                 << endl;
        }
    }

    getchar();

    return 0;
}
