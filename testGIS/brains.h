#ifndef BRAINS_H
#define BRAINS_H

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <cstring>
#include <vector>

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
    const char *formatError = "Format error, see help (-h)";
    const char *fError = "File not exist\n";
    const char *mError = "Incorrect value of -m key\n";
    const char *help = "Keys: -f, -m, -v, -h\n"
                       "Key -f getting the file\n"
                       "Key -m getting one of two modifiers: checksum, words\n"
                       "Key -v getting the word that find\n"
                       "Key -h getting help\n"
                       "You can use one of three formats:\n"
                       "1.Getting help\n"
                       "testGis -h\n"
                       "2.Printing the words number in file into display\n"
                       "There key -f is file Test.tst, key -m is words and key -v is word mother\n"
                       "testGIS.exe -f Test.tst -m words -v mother\n"
                       "3.Printing the checksum into display\n"
                       "Checksum calculated as word1+word2+...+wordN(wordN - 32-bit words of file)\n"
                       "testGIS.exe -f Test.tst -m checksum"
                       ;
};

#endif // BRAINS_H
