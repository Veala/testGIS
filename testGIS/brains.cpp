#include "brains.h"
#include <iostream>
#include <cstring>

using namespace std;

Brains::Brains(int n)
{
    argc = n;
    argv = new char*[n];
}

void Brains::init()
{
    if (argc == 1) {
        cout << err1_a;
        return;
    } //else if (n!=)
    checkArgument(argv[1]);
}

void Brains::checkArgument(const char* arg)
{
    if (!strcmp(arg,"-h")) {
        cout << help;
    } else if (!strcmp(arg,"-f")) {

    } else if (!strcmp(arg,"-m")) {

    } else if (!strcmp(arg,"-v")) {

    } else {

    }

}

void Brains::checkValue(const char* val)
{

}

Brains::~Brains()
{
    delete[] argv;
}

