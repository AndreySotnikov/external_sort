#include "myfile.h"

MyFile::MyFile()
{
}

MyFile::MyFile(string _s) {
    this->flast = 0;
    fname = _s;
    eof = true;
    feosec = true;
}

void MyFile::closeFile() {
    fclose(f);
}

void MyFile::copy(MyFile& f2) {
    //if (!f2.isEmpty())
    fprintf(f2.getFile(), "%c", ' ');
    fprintf(f2.getFile(),"%d",this->flast);
    f2.setFlast(this->flast);
    this->eof = feof(f);

    if (!eof) {

        fscanf(f,"%d",&flast);
    }
    feosec = (bool)(this->eof || (f2.getLast() > flast));
    //feosec = (bool)(feof(f) || (f2.getLast() > flast));
}

void MyFile::copySec(MyFile& f2) {
    while (!feosec) {
        copy(f2);
        // !feosec)
            //fprintf(f2.getFile(), "%c", ' ');
    }
}

void MyFile::deleteFile() {
    remove(this->fname.c_str());
}

bool MyFile::isEmpty() {
    //f = fopen(fname.c_str(),"r");

    long sz;

    sz = ftell(f);
    return (sz == 0 && feof(f));


    fseek(f, 0, SEEK_END);
    sz = ftell(f);
    fseek(f, 0, SEEK_SET);
    bool result = sz == 0;
    //fclose(f);
    return result;
}

void MyFile::nextSec() {
    this->feosec = eof;
}

void MyFile::openRead() {
    f = fopen(fname.c_str(),"r");
    fscanf(f,"%d",&flast);
    feosec = feof(f);
    eof = feof(f);
    //fseek(f, 0, SEEK_SET);
    //if (!eof)
        //fscanf(f,"%d",&flast);
}

void MyFile::openWrite() {
    f = fopen(fname.c_str(),"w");
}

bool MyFile::isEosec() {
    return this->feosec;
}

bool MyFile::isEof() {
    return this->eof;
}

FILE* MyFile::getFile() {
    return f;
}

string MyFile::getName() {
    return fname;
}

int MyFile::getLast() {
    return this->flast;
}

void MyFile::setFlast(int _i) {
    flast = _i;
}
