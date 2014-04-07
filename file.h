#ifndef FILE_H
#define FILE_H

#include <cstdio>
#include <stdio.h>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <time.h>

using namespace std;

class File {
private:
    FILE* f;
    FILE* f1, *f2;
    string name;
    int compCount;
    double time;
    int readCount;

    bool End_Range(FILE* ftmp);
    void distribute(int& s1, int& s2);
    void merge();

    int Print_File(const char *name, int j);
public:
    File();
    void sort();
    void setName(string& _name);
    void generateRandom(int maxSize);
    void generateReverse(int maxSize);

    int getCompares();
    double getTime();
    int getReads();
};

#endif // FILE_H
