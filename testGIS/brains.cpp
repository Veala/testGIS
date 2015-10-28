#include "brains.h"

Brains::Brains(int n)
{
    argc = n;
    argv = new char*[n];
}

void Brains::init()
{
    if (!(((argc==2) && (!strcmp(argv[1],"-h"))) |
            ((argc==5) && (!strcmp(argv[1],"-f")) & (!strcmp(argv[3],"-m"))) |
            ((argc==7) && (!strcmp(argv[1],"-f")) & (!strcmp(argv[3],"-m")) & (!strcmp(argv[5],"-v"))))) {
        cout << formatError;
        return;
    }

    if ((argc==2) & (!strcmp(argv[1],"-h"))) {
        cout << help;
        return;
    }

    if (!checkF()) {
        cout << fError;
        return;
    }

    if (checkM() == 0) {
        cout << mError;
        return;
    }

    if (checkM()==1) {
        printSum();
        return;
    }

    if (checkM()==2) {
        printWords();
        return;
    }
}

bool Brains::checkF()
{
    fstream file;
    file.open(argv[2], ios_base::in);
    if (file == NULL) {
        file.close();
        return 0;
    } else {
        file.close();
        return 1;
    }
}

int Brains::checkM()
{
    if ((argc==5) && (!strcmp(argv[4],"checksum"))) {
        return 1;
    } else if ((argc==7) && (!strcmp(argv[4],"words"))) {
        return 2;
    } else {
        return 0;
    }
}

void Brains::printWords()
{
    ifstream file;
    file.open(argv[2], ios_base::in);
    //file.EOF()
    //EOF

    file.close();
}

void Brains::printSum()
{
    fstream file;
    file.open(argv[2], ios_base::in);


    file.close();
}

Brains::~Brains()
{
    delete[] argv;
}

