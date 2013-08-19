#include <iostream>

using namespace std;

bool VerifySequenceOfBST(int *seq, int length)
{
    if(seq == NULL || length <= 0)
    {
        return false;
    }

    int i = 0;
    int leftLen = 0;
    while(seq[i] < seq[length-1])
        ++i;
    leftLen = i;
    for(int j = leftLen; j < length-1; ++j)
    {
        if(seq[j] < seq[length-1])
            return false;
    }

    bool left = true;
    if (leftLen > 1) {
        left = VerifySequenceOfBST(seq, leftLen);
    }
    
    bool right = true;
    if(length - length - 1 > 1)
    {
        right = VerifySequenceOfBST(seq+leftLen, length - leftLen - 1);
    }
    return left&&right;
}
int main()
{
    int sequence[] = {5, 7, 6, 9, 11, 10, 8};
    int sequence2[] = {7, 4, 6, 5};

    cout << VerifySequenceOfBST(sequence, sizeof(sequence)/sizeof(int)) << endl;
    cout << VerifySequenceOfBST(sequence2, sizeof(sequence2)/sizeof(int)) << endl;
}
