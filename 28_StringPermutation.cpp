#include <iostream>
#include <string>
#include <cstring>


using namespace std;


void Permutation(char *str, char *begin)
{
    if (*begin == '\0') {
        cout << str << endl;
    }
    else
    {
        for(char *pCh = begin; *pCh != '\0'; ++pCh)
        {
            char temp = *pCh;
            *pCh = *begin;
            *begin = temp;

            Permutation(str, begin+1);

            temp = *pCh;
            *pCh = *begin;
            *begin = temp;
        }
    }
}

void Permutation(char *str)
{
    if (str == NULL) {
        return;
    }

    Permutation(str, str);
}

int main()
{
    string tmp;
    cin >> tmp;
    char str[11];
    strncpy(str, tmp.c_str(), 10);
    Permutation(str);

    return 0;
}
