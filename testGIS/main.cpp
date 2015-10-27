#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 1) {
        std::cout << argv[1];
        //std::getline()
        if (argv[1] == "-f") {
            std::cout << "-f\n";
        }

    } else {
        std::cout << "No parameters\n";
    }
    //std::cout << "Arguments incorrect\n";
    //std::cout << argc;

    return 1;
}
