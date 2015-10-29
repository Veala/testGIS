#ifndef BRAINS_H
#define BRAINS_H

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Brains
{
public:
    Brains(int);
    int argc;
    char **argv;
    void init();
    bool checkF();
    int checkM();
    void printWords();
    void printSum();
    ~Brains();

private:
    string  formatError,
            fError,
            mError,
            intError,
            words,
            checksum,
            help;
};

#endif // BRAINS_H
