#include "includes.h"

Group readGroupFromFile(const string & filename) {
    ifstream reader(filename,ios_base::in);
    assert(!reader.fail());
    Group Res;
    vector<unsigned int> buf;
    int i = -1;
    while(!reader.eof()) {
        buf = readLine(reader);
        if(reader.eof() || buf.size() == 0) break;
        Res.Students.push_back(buf[0]);
        i++;
        for(int j = 1; j < buf.size(); j++) {
            Res.Students[i].Courses.push_back(buf[j]);
        }
    }
    return Res;
}

vector<unsigned int> readLine(ifstream & reader) {
    vector<unsigned int> res;
    stringstream ss;
    char buf[0x100];
    reader.getline(buf,0x100);
    ss << buf;
    int n;
    while(!ss.eof()) {
        ss >> n;
        res.push_back(n);
    }
    return res;
}
