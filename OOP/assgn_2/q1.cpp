#include <iostream>
#include <string.h>
#include "q1.h"
using namespace std;


char symbol[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int value[7] = { 1, 5, 10, 50, 100, 500, 1000 };


RomanNum :: RomanNum(int s, char romanNum[])
{
    size = s;

    for (int i = 0; i < size; i++)
        num[i] = romanNum[i];

    result = 0;
}


int RomanNum :: findIndex(char ch)
{
    for (int count = 0; count < 7; count++)
        if (ch == symbol[count])
            return count;
    return -1;
}


int RomanNum :: convertToInt()
{
    int index = size - 1, firstIndex = 0, scndIndex = 0, thirdIndex = 0;

    if (size == 1)
    {
        if (findIndex(num[index] != -1))
        {
            firstIndex = findIndex(num[index]);
            result += value[firstIndex];
        }
    }

    else
    {
        for (; index > -1; index--)
        {
            if (index == size - 1)
            {
                if (findIndex(num[index]) != -1)
                {
                    firstIndex = findIndex(num[index]);
                    result += value[firstIndex];
                }
            }

            else
            {
                scndIndex = findIndex(num[index]);
                thirdIndex = findIndex(num[index + 1]);

                if (value[scndIndex] >= value[thirdIndex])
                    result += value[scndIndex];

                else if (value[scndIndex] < value[thirdIndex])
                    result -= value[scndIndex];
            }
        }
    }

    return result;
}


string convertToRoman(int val)
{
    string symbolExt[13] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
    int valueExt[13] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
    string answer = "";

    for (int i = 12; i > -1;)
    {
        if (val >= valueExt[i] && val != 0)
        {
            val -= valueExt[i];
            answer += symbolExt[i];
        }

        else
            i--;
    }

    return answer;
}


int RomanNum :: operator + (RomanNum& r2)
{
    int temp = this->result + r2.result;
    return temp;
}


int RomanNum :: operator - (RomanNum& r2)
{
    int temp = this->result - r2.result;
    return temp;
}


int RomanNum :: operator * (RomanNum& r2)
{
    int temp = this->result * r2.result;
    return temp;
}


int RomanNum :: operator / (RomanNum& r2)
{
    int temp = this->result / r2.result;
    return temp;
}


bool RomanNum :: operator == (RomanNum& r2)
{
    if (this->result == r2.result)
        return 1;

    else
        return 0;
}


bool RomanNum :: operator != (RomanNum& r2)
{
    if (this->result != r2.result)
        return 1;

    else
        return 0;
}


bool RomanNum :: operator < (RomanNum& r2)
{
    if (this->result < r2.result)
        return 1;

    else
        return 0;
}


bool RomanNum :: operator > (RomanNum& r2)
{
    if (this->result > r2.result)
        return 1;

    else
        return 0;
}


int RomanNum :: operator++ ()
{
    int temp = this->result++;
    return temp;
}


int RomanNum :: operator-- ()
{
    int temp = this->result--;
    return temp;
}


int RomanNum :: operator++ (int dummy)
{
    int temp = this->result++;
    return temp;
}


int RomanNum :: operator-- (int dummy)
{
    int temp = this->result--;
    return temp;
}


int main()
{
    char romanNum1[100];
    cout << "Roman Numeral 1: ";
    cin >> romanNum1;

    int size1 = strlen(romanNum1);
    int count = 1;
    for (int i = 0; i < size1 - 1; i++)
    {
        if (romanNum1[i] == romanNum1[i + 1])
            count++;

        else
            count = 0;
    }

    while (count >= 4)
    {
        cout << "Enter the number again: ";
        cin >> romanNum1;

        count = 1;
        for (int i = 0; i < size1 - 1; i++)
        {
            if (romanNum1[i] == romanNum1[i + 1])
                count++;

            else
                count = 0;
        }
    }

    size1 = strlen(romanNum1);
    RomanNum r1(size1, romanNum1);
    int intR1 = r1.convertToInt();
    cout << "Roman Numeral 1: " << intR1 << endl << endl;


    char romanNum2[100];
    cout << "Roman Numeral 2: ";
    cin >> romanNum2;

    int size2 = strlen(romanNum2);
    count = 1;
    for (int i = 0; i < size2 - 1; i++)
    {
        if (romanNum2[i] == romanNum2[i + 1])
            count++;

        else
            count = 0;
    }

    while (count >= 4)
    {
        cout << "Enter the number again: ";
        cin >> romanNum2;

        count = 1;
        for (int i = 0; i < size2 - 1; i++)
        {
            if (romanNum2[i] == romanNum2[i + 1])
                count++;

            else
                count = 0;
        }
    }

    size2 = strlen(romanNum2);
    RomanNum r2(size2, romanNum2);
    int intR2 = r2.convertToInt();
    cout << "Roman Numeral 2: " << intR2 << endl << endl;


    int sum = r1 + r2;
    string sumAns = convertToRoman(sum);
    cout << "Addition: " << sumAns << endl;


    int subt = 0;
    if (r1 > r2)
        subt = r1 - r2;

    else if (r2 > r1)
        subt = r2 - r1;

    else if (r1 == r2)
        subt = r1 - r2;

    string subAns = convertToRoman(subt);
    cout << "Subtraction: " << subAns << endl;


    int mul = r1 * r2;
    string mulAns = convertToRoman(mul);
    cout << "Multiplication: " << mulAns << endl;


    int div = 0;
    if (r1 > r2)
        div = r1 / r2;

    else if (r2 > r1)
        div = r2 / r1;

    else if (r1 == r2)
        div = r1 / r2;

    string divAns = convertToRoman(div);
    cout << "Division: " << divAns << endl;


    if (r1 == r2)
        cout << "\nThe Roman Numerals are equal\n";

    else if (r1 != r2)
    {
        cout << "\nThe Roman Numerals are NOT equal";

        if (r1 < r2)
            cout << "\nRoman Numeral 1 is less than Roman Numeral 2\n";

        else if (r1 > r2)
            cout << "\nRoman Numeral 1 is greater than Roman Numeral 2\n";
    }


    int postR1 = r1++, postR2 = r2++, preR1 = ++r1, preR2 = ++r2;
    string postR1Ans = convertToRoman(postR1), postR2Ans = convertToRoman(postR2), preR1Ans = convertToRoman(preR1), preR2Ans = convertToRoman(preR2);
    cout << "\nPost Increment of Roman Number 1: " << postR1Ans << "\nPost Increment of Roman Number 2: " << postR2Ans;
    cout << "\n\nPre Increment of Roman Number 1: " << preR1Ans << "\nPre Increment of Roman Number 2: " << preR2Ans << endl;

    return 0;
}
