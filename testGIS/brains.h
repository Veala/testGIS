#ifndef BRAINS_H
#define BRAINS_H


class Brains
{
public:
    Brains(int);
    int argc;
    char **argv;
    void init();
    void checkArgument(const char* );
    void checkValue(const char* );
    ~Brains();

private:
    const char *err1 = "Incorrect argument";
    const char *err1_a = "Not arguments";
    const char *err2 = "File not exsist";
    const char *err3 = "Less arguments";
    const char *help = "Help";
};

#endif // BRAINS_H
