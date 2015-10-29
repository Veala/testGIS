#include "brains.h"

Brains::Brains(int n)
{
    argc = n;
    argv = new char*[n];

    formatError = "Format error, see help (-h)";
    fError      = "File not exist\n";
    mError      = "Incorrect value of -m key\n";
    intError    = "Type int is not 32-bit\n";
    words       = "Word: ";
    checksum    = "Checksum: ";
    help        = "Keys: -f, -m, -v, -h\n"
                       "Key -f getting the file\n"
                       "Key -m getting one of two modifiers: checksum, words\n"
                       "Key -v getting the word that find\n"
                       "Key -h getting help\n"
                       "You can use one of three formats:\n"
                       "1.Getting help\n"
                       "testGis -h\n"
                       "2.Printing the words number in file into display\n"
                       "Bottom key -f is file Test.tst, key -m is words and key -v is word mother\n"
                       "testGIS.exe -f Test.tst -m words -v mother\n"
                       "3.Printing the checksum into display\n"
                       "Checksum calculated as word1+word2+...+wordN(wordN - 32-bit words of file)\n"
                       "If the last word less then four characters than characters of previous word is added to it\n"
                       "Bottom key -f is file Test.tst, key -m is checksum\n"
                       "testGIS.exe -f Test.tst -m checksum\n"
                       ;
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
    fstream file;
    file.open(argv[2], ios_base::in);
    int len = strlen(argv[6]);
    int n = 0;
    char *c;
    int pos = 0;   file.seekg(pos);
    while (1) {
        file.read(c,len);
        //cout << c << '\n';
        if (!strcmp(argv[6], c)) n++;
        if (file.peek() == EOF) break;
        pos++;  file.seekg(pos);

    }
    cout << words << argv[6] << ": " << n << '\n';
    file.close();
}

void Brains::printSum()
{
    if (sizeof(int) != 4) {
        cout << intError;
        return;
    }
    fstream file;
    file.open(argv[2], ios_base::in);
    unsigned int sum=0;
    unsigned int buf=0;
    while (1) {
        if (file.peek() == EOF) break;
        file.read((char*)&buf,4);
        sum=sum+buf;
        //cout << (char*)&buf << '\n';
        //cout << buf << '\n';
        if (file.eof()) break;
    }
    cout << checksum << sum << '\n';
    file.close();
}

Brains::~Brains()
{
    delete[] argv;
}

