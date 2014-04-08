#include "file.h"

File::File() {
    time = 0;
    compCount = 0;
    readCount = 0;

    cycleCount = 0;


}

void File::generateRandom(int maxSize) {
    remove(name.c_str());
    string fname = "tmp";
    ofstream fout (fname.c_str());
    int sz = maxSize;// rand() % maxSize + 15;
    fout << " " << rand() % 3333;
    for (int i = 1; i < sz; i++)
        fout << " " << rand() % 3333;
    fout.close();
    this->name = fname;
}

void File::generateReverse(int maxSize) {
    remove(name.c_str());
    string fname = "tmp";
    ofstream fout (fname.c_str());
    int sz = maxSize;// rand() % maxSize;
    fout << " " << sz;
    for (int i = sz-1; i > 0; i--)
        fout << " " << i;
    fout.close();
    this->name = fname;
}

string File::getFilename() {
    return this->name;
}

int File::getCompares() {
    return this->compCount;
}

int File::getReads() {
    return this->readCount;
}

int File::getCycleCount() {
    return this->cycleCount;
}

double File::getTime() {
    return this->time;
}

//определение конца блока
bool File::End_Range (FILE* ftmp){
    int tmp;
    if (!feof(ftmp))
        tmp = fgetc(ftmp);
    if (!feof(ftmp))
        tmp = fgetc(ftmp);

    if (tmp != '\'')
        fseek(ftmp, -2, 1);
    else
        fseek(ftmp,1,1);
    return tmp == '\'' ? true : false;
}


//int File::Print_File(const char* name, int j) {
//    ifstream fin(name);
//    string lg = "log";
//    lg.push_back(j);
//    ofstream fout(lg.c_str());
//    string s;
//    while (getline(fin, s))
//        fout << s << "\n";

//    int s1 = 0;
//    for (int i = 0; i < s.length(); i++) {
//        if (s[i] == '\'')
//            s1++;
//    }
//    fout << s1;
//    fin.close();
//    fout.close();
//    return s1;
//}


//void File::distribute(int& s1, int& s2) {
//    f = fopen(this->name.c_str(),"r");
//    f1 = fopen("nmsort_1","w");
//    f2 = fopen("nmsort_2","w");

//    int mark = 1;
//    s1 = 0;
//    s2 = 0;
//    int a1, a2;

//    //распределение
//    if (!feof(f))
//        fscanf(f,"%d",&a1);
//    fprintf(f1,"%d ",a1);
//    if (!feof(f))
//        fscanf(f,"%d",&a2);


//    this->readCount++;  //проход по файлу f
//    while (!feof(f)) {
//        this->compCount++; // compare a1 a2
//        if (a2 < a1) {
//            switch (mark) {
//            case 1:
//                fprintf(f1,"' ");
//                mark = 2;
//                s1++;
//                break;
//            case 2:
//                fprintf(f2,"' ");
//                mark = 1;
//                s2++;
//                break;
//            }
//        }
//        if (mark == 1) {
//            fprintf(f1,"%d ",a2);
//            s1++;
//        } else {
//            fprintf(f2,"%d ",a2);
//            s2++;
//        }
//        a1 = a2;
//        fscanf(f,"%d",&a2);
//    }

//    if (s2 > 0 && mark == 2)
//        fprintf(f2,"'");
//    if ( s1 > 0 && mark == 1)
//        fprintf(f1,"'");

//    fclose(f2);
//    fclose(f1);
//    fclose(f);
//}

//void File::merge() {
//    //слияние
//    f = fopen(name.c_str(),"w");
//    f1 = fopen("nmsort_1","r");
//    f2 = fopen("nmsort_2","r");

//    int a1, a2;

//    if (!feof(f1))
//        fscanf(f1,"%d",&a1);
//    if (!feof(f2))
//        fscanf(f2,"%d",&a2);

//    bool file1, file2;

//    this->readCount += 2; //read f1 f2
//    while (!feof(f1) && !feof(f2)) {
//        file1 = false;
//        file2 = false;
//        //выбираем пока не кончится один
//        while (!file1 && !file2) {
//            this->compCount++; //compare a1 a2
//            if (a1 <= a2) {
//                fprintf(f,"%d ",a1);
//                file1 = End_Range(f1);
//                fscanf(f1,"%d",&a1);
//            } else {
//                fprintf(f,"%d ",a2);
//                file2 = End_Range(f2);
//                fscanf(f2,"%d",&a2);
//            }
//        }

//        //запись серий в исходный
//        while (!file1) {
//            fprintf(f,"%d ",a1);
//            file1 = End_Range(f1);
//            if (!feof(f1))
//                fscanf(f1,"%d",&a1);
//        }
//        while (!file2) {
//            fprintf(f,"%d ",a2);
//            file2 = End_Range(f2);
//            if (!feof(f2))
//                fscanf(f2,"%d",&a2);
//        }
//    }

//    file1 = false;
//    file2 = false;
//    //переписываем остатки если какой то из файлов кончился
//    while (!file1 && !feof(f1)) {
//        fprintf(f,"%d ",a1);
//        file1 = End_Range(f1);
//        if (!file1)
//            fscanf(f1,"%d",&a1);
//    }
//    while (!file2 && !feof(f2)) {
//        fprintf(f,"%d ",a2);
//        file2 = End_Range(f2);
//        if (!file2)
//            fscanf(f2,"%d",&a2);
//    }
//    fclose(f2);
//    fclose(f1);
//    fclose(f);
//}



//void File::sort() {
//    time = 0;
//    compCount = 0;
//    readCount = 0;

//    cycleCount++;

//    int s1 = 1;
//    int s2 = 1;

//    //int currTime = clock();
//    int t1 = clock();
//    int j = (int)'0';
//    while ( s1 > 0 && s2 > 0 ) {
//        distribute(s1, s2);

////        Print_File(name.c_str(), 33);
////        int s1 = Print_File("nmsort_1", j++);
////        int s2 = Print_File("nmsort_2", j++);
////        if (abs(s1 - s2) > 1) {
////            return;
////        }

//        merge();

//        cycleCount++;

//    }
//    int t2 = clock();
//    //this->time = (t2 - t1)*1.0 / 1000.0;
//    this->time = 1.0*(t2 - t1) / CLOCKS_PER_SEC;

//    remove("nmsort_1");
//    remove("nmsort_2");



//}

void File::setName(string &_name) {
    name = _name;
}


void File::newSort() {
    f = MyFile(name);
    string name1 = "nmsort_1";
    string name2 = "nmsort_2";
    f1 = MyFile(name1);
    f2 = MyFile(name2);

    do {
        newDistribute();
        newMerge();
    } while (count > 1);

    f1.deleteFile();
    f2.deleteFile();
}

int File::getLast() {
    int result = INT_MAX;
    if (f.getLast() < result && !f.isEosec())
        result = f.getLast();
}

void File::newDistribute() {
    f.openRead();
    f1.openWrite();
    f2.openWrite();
    //f.nextSec();

    if (!f.isEof()) {
        f.copySec(f1);
        count++;
        f.nextSec();
    }
    if (!f.isEof()){
        f.copySec(f2);
        count++;
        f.nextSec();
    }
    int dest = 1;
    while (!f.isEof()) {
        //f.nextSec();
        if (dest == 1) {
            if (f.getLast() >= f1.getLast()) {
                f.copySec(f1);
                f.nextSec();
            }
            f.copySec(f1);
            f.nextSec();
            dest = 2;
        } else {
            if (f.getLast() >= f2.getLast()) {
                f.copySec(f2);
                f.nextSec();
            }
            f.copySec(f2);
            f.nextSec();
            dest = 1;
        }

    }
    f.closeFile();
    f1.closeFile();
    f2.closeFile();
}

void File::newMerge() {



    f.openWrite();
    f1.openRead();
    f2.openRead();



    count = 0;

    while (!f1.isEof() && !f2.isEof()) {
        while (!f1.isEosec() && !f2.isEosec()) {
            if (f1.getLast() <= f2.getLast()) {
                f1.copy(f);
                //f1.nextSec();
            } else {
                f2.copy(f);
                //f2.nextSec();
            }
        }

        if (!f1.isEosec()) {
            f1.copySec(f);
            //f1.nextSec();
        }
        if (!f2.isEosec()) {
            f2.copySec(f);
            //f2.nextSec();
        }
        f1.nextSec();
        f2.nextSec();


        count++;
    }
    //f1.nextSec();
    //f2.nextSec();

    //add if exists in 1 and 2
    while (!f1.isEof()) {
        f1.copySec(f);
       // f1.nextSec();
        count++;
    }
    while (!f2.isEof()) {
        f2.copySec(f);
        //f2.nextSec();
        count++;
    }

    f.closeFile();
    f1.closeFile();
    f2.closeFile();
}
