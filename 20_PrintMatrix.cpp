#include <iostream>


using namespace std;

void PrintMatrix(int *matrix, int rows, int colms)
{
    if(matrix == NULL || rows <= 0 || colms <= 0)
        return ;

    int start = 0;
    while(start*2 < rows && start*2 < colms)
    {
        int endX = colms - start - 1;
        int endY = rows- start - 1;
        for(int i = start; i < endX; ++i)
        {
            cout << matrix[start*colms + i] << "\t";
        }
        for(int i = start; i < endY; ++i)
        {
            cout << matrix[i*colms + endX] << "\t";
        }
        for(int i = endX; i > start; --i)
        {
            cout << matrix[endY*colms + i] << "\t";
        }
        for(int i = endY; i > start; --i)
        {
            cout << matrix[i*colms + start] << "\t";
        }
        ++start;
    }
    cout << endl;
}


int main()
{
    int matrix[] = {
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12,
        13, 14, 15, 16
    };

    PrintMatrix(matrix, 2, 8);

    return 0;
}
