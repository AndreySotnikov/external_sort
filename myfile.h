#ifndef MYFILE_H
#define MYFILE_H

#include <cstdio>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <time.h>

using namespace std;

class MyFile {
private:
    //FILE* f;
    fstream f;
    string fname;
    int flast;
    bool feosec;
    bool eof;
public:
    MyFile();
    MyFile(string _s);
    void openRead();
    void openWrite();
    bool isEmpty();
    void nextSec();
    //void rename(string _s);
    void deleteFile();
    void copy(MyFile &f2);
    void copySec(MyFile &f2);
    void closeFile();

    //void setElem()

    bool isEosec();
    bool isEof();
    int getLast();
    void setFlast(int _i);
    string getName();

    FILE* getFile();

};

#endif // MYFILE_H
