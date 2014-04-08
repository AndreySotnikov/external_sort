#ifndef MYFILE_H
#define MYFILE_H

#include <cstdio>
#include <string>
#include <cmath>
#include <cstdlib>
#include <time.h>

#include <fstream>

using namespace std;

class MyFile {
private:
    FILE* f;
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

    void writeData(int _d);
    int readData();

    FILE* getFile();


};

#endif // MYFILE_H
