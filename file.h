#ifndef FILE_H
#define FILE_H

#include <cstdio>
#include <string>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include "myfile.h"
#include <climits>

using namespace std;

class File {
private:
    MyFile f;
    MyFile f1, f2;
    string name;
    int count;
    int compCount;
    double time;
    int readCount;

    int cycleCount;

    bool End_Range(FILE* ftmp);
    void distribute(int& s1, int& s2);
    void merge();

    void newDistribute();
    void newMerge();


    int getLast();

    //int Print_File(const char *name, int j);
public:
    File();
    void sort();
    void setName(string& _name);
    void generateRandom(int maxSize);
    void generateReverse(int maxSize);

    string getFilename();

    int getCompares();
    double getTime();
    int getReads();
    int getCycleCount();
    void newSort();
};

#endif // FILE_H
