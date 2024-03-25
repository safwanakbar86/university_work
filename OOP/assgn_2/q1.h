#include <iostream>
using namespace std;

class RomanNum
{
    friend string convertToRoman(int);

private:
    char num[100];
    int size;
    int result;

public:
    RomanNum(int, char[]);
    int findIndex(char);
    int convertToInt();

    int operator + (RomanNum&);
    int operator - (RomanNum&);
    int operator * (RomanNum&);
    int operator / (RomanNum&);

    bool operator == (RomanNum&);
    bool operator != (RomanNum&);
    bool operator < (RomanNum&);
    bool operator > (RomanNum&);

    int operator ++ ();
    int operator -- ();
    int operator ++ (int);
    int operator -- (int);
};
