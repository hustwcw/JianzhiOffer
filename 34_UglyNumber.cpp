#include <iostream>


using namespace std;



int Min(int number1, int number2, int number3)
{
    int min = (number1 < number2)? number1:number2;
    min = (min < number3)?min:number3;
    return min;
}

int GetUglyNumber(int index)
{
    if(index < 1)
    {
        return 0;
    }

    int *pUglyNumbers = new int[index];
    pUglyNumbers[0] = 1;
    int nextUglyIndex = 1;

    int *pMultiply2 = pUglyNumbers;
    int *pMultiply3 = pUglyNumbers;
    int *pMultiply5 = pUglyNumbers;

    while(nextUglyIndex < index)
    {
        int min = Min(*pMultiply2*2, *pMultiply3*3, *pMultiply5*5);
        pUglyNumbers[nextUglyIndex] = min;

        while(*pMultiply2*2 <= pUglyNumbers[nextUglyIndex])
        {
            ++pMultiply2;
        }
        
        while(*pMultiply3*3 <= pUglyNumbers[nextUglyIndex])
        {
            ++pMultiply3;
        }
        
        while(*pMultiply5*5 <= pUglyNumbers[nextUglyIndex])
        {
            ++pMultiply5;
        }
        
        ++nextUglyIndex;
    }
    for(int i = 0; i < index; ++i)
    {
        cout << pUglyNumbers[i] << "\t";
    }
    cout << endl;

    int ugly = pUglyNumbers[index-1];
    delete[] pUglyNumbers;
    return ugly;
}


int main()
{
    GetUglyNumber(15);
    
    return 0;
}
