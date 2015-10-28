#include "brains.h"

int main(int argc, char *argv[])
{
    Brains brains(argc);
    for (int i=0; i<argc; i++)  brains.argv[i] = argv[i];
    brains.init();
    cout << "bye";
    return 1;
}
