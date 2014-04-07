#include "file.h"

File::File() {
    time = 0;
    compCount = 0;
    readCount = 0;
}

void File::generateRandom(int maxSize) {
    remove(name.c_str());
    string fname = "tmp";
    ofstream fout (fname.c_str());
    int sz = maxSize;// rand() % maxSize + 15;
    for (int i = 0; i < sz; i++)
        fout << rand() % 3333 << " ";
    fout.close();
    this->name = fname;
}

void File::generateReverse(int maxSize) {
    remove(name.c_str());
    string fname = "tmp";
    ofstream fout (fname.c_str());
    int sz = maxSize;// rand() % maxSize;
    for (int i = sz; i >= 0; i--)
        fout << i << " ";
    fout.close();
    this->name = fname;
}

int File::getCompares() {
    return this->compCount;
}

int File::getReads() {
    return this->readCount;
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


int File::Print_File(const char* name, int j) {
    ifstream fin(name);
    string lg = "log";
    lg.push_back(j);
    ofstream fout(lg.c_str());
    string s;
    while (getline(fin, s))
        fout << s << "\n";

    int s1 = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '\'')
            s1++;
    }
    fout << s1;
    //fout << s << "\t\t\t\n" << s1 << endl;
    //fout << endl;
    fin.close();
    fout.close();
    return s1;
}


void File::distribute(int& s1, int& s2) {
    f = fopen(this->name.c_str(),"r");
    f1 = fopen("nmsort_1","w");
    f2 = fopen("nmsort_2","w");

    int mark = 1;
    s1 = 0;
    s2 = 0;
    int a1, a2;

    //распределение
    if (!feof(f))
        fscanf(f,"%d",&a1);
    fprintf(f1,"%d ",a1);
    if (!feof(f))
        fscanf(f,"%d",&a2);


    this->readCount++;  //проход по файлу f
    while (!feof(f)) {
        this->compCount++; // compare a1 a2
        if (a2 < a1) {
            switch (mark) {
            case 1:
                fprintf(f1,"' ");
                mark = 2;
                s1++;
                break;
            case 2:
                fprintf(f2,"' ");
                mark = 1;
                s2++;
                break;
            }
        }
        if (mark == 1) {
            fprintf(f1,"%d ",a2);
            s1++;
        } else {
            fprintf(f2,"%d ",a2);
            s2++;
        }
        a1 = a2;
        fscanf(f,"%d",&a2);
    }

    if (s2 > 0 && mark == 2)
        fprintf(f2,"'");
    if ( s1 > 0 && mark == 1)
        fprintf(f1,"'");

    fclose(f2);
    fclose(f1);
    fclose(f);
}

void File::merge() {
    //слияние
    f = fopen(name.c_str(),"w");
    f1 = fopen("nmsort_1","r");
    f2 = fopen("nmsort_2","r");

    int a1, a2;

    if (!feof(f1))
        fscanf(f1,"%d",&a1);
    if (!feof(f2))
        fscanf(f2,"%d",&a2);

    bool file1, file2;

    this->readCount += 2; //read f1 f2
    while (!feof(f1) && !feof(f2)) {
        file1 = false;
        file2 = false;
        //выбираем пока не кончится один
        while (!file1 && !file2) {
            this->compCount++; //compare a1 a2
            if (a1 <= a2) {
                fprintf(f,"%d ",a1);
                file1 = End_Range(f1);
                fscanf(f1,"%d",&a1);
            } else {
                fprintf(f,"%d ",a2);
                file2 = End_Range(f2);
                fscanf(f2,"%d",&a2);
            }
        }

        //запись серий в исходный
        while (!file1) {
            fprintf(f,"%d ",a1);
            file1 = End_Range(f1);
            if (!feof(f1))
                fscanf(f1,"%d",&a1);
        }
        while (!file2) {
            fprintf(f,"%d ",a2);
            file2 = End_Range(f2);
            if (!feof(f2))
                fscanf(f2,"%d",&a2);
        }
    }

    file1 = false;
    file2 = false;
    //переписываем остатки если какой то из файлов кончился
    while (!file1 && !feof(f1)) {
        fprintf(f,"%d ",a1);
        file1 = End_Range(f1);
        if (!file1)
            fscanf(f1,"%d",&a1);
    }
    while (!file2 && !feof(f2)) {
        fprintf(f,"%d ",a2);
        file2 = End_Range(f2);
        if (!file2)
            fscanf(f2,"%d",&a2);
    }
    fclose(f2);
    fclose(f1);
    fclose(f);
}

void File::sort() {
    time = 0;
    compCount = 0;
    readCount = 0;

    int s1 = 1;
    int s2 = 1;

    //int currTime = clock();
    int t1 = clock();
    int j = (int)'0';
    while ( s1 > 0 && s2 > 0 ) {
        distribute(s1, s2);

//        Print_File(name.c_str(), 33);
//        int s1 = Print_File("nmsort_1", j++);
//        int s2 = Print_File("nmsort_2", j++);
//        if (abs(s1 - s2) > 1) {
//            return;
//        }

        merge();
    }
    int t2 = clock();
    //this->time = (t2 - t1)*1.0 / 1000.0;
    this->time = 1.0*(t2 - t1) / CLOCKS_PER_SEC;

    remove("nmsort_1");
    remove("nmsort_2");



}

void File::setName(string &_name) {
    name = _name;
}
