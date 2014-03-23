#include "includes.h"
#define LIMIT 2
#include <thread>

// Should I move this?
mt19937 gen; // Don't you think this would be better with salt?

int main() {

    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    gen.seed(t1.time_since_epoch().count());

    Group Academy = readGroupFromFile("simple.txt");

    for(int i = 1; i <= 20; i++) {
        Academy.Classes.push_back(i);
    }

    Academy = assignClasses(Academy);

    unsigned int minConflicts = INF;
    //ofstream w("dump.txt",ios_base::out);
    unsigned int temp;
    Group tempGroup,minGroup;
    for(int i = 0; i < 100; i++) {
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
        cout << minGroup.Classes[i].period << "\t";
    }
    */

    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();

    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

    cout << "Compute Time :: " << time_span.count() << endl;

    getchar();

    return 0;
}
