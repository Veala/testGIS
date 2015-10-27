#include <iostream>
#include <cstring>
#include "brains.h"

using namespace std;

int main(int argc, char *argv[])
{
    Brains brains(argc);
    for (int i=0; i<argc; i++)  brains.argv[i] = argv[i];
    brains.init();


//    if (argc == 1) {
//        std::cout << "No parameters\n";
//        return 1;
//    }
//    if (argc == 1) {

//    }
//    if (argc != 1) {
//        //if (string(argv[1]) == "-f") {
//        if (!strcmp(argv[1], "-f")) {

//        } else if (!strcmp(argv[1], "-h")) {

//        } else {
//            std::cout << "Argument incorrect\n The first argument must be -f or -h\n";
//        }

//    } else {
//        std::cout << "No parameters\n";
//    }
//    //std::cout << "Arguments incorrect\n";
//    //std::cout << argc;

    return 1;
}
