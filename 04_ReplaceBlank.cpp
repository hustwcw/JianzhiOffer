#include <iostream>
#include <cstring>

using namespace std;

void ReplaceBlank(char *str, int len)
{
    if (str == NULL || len == 0)
    {
        return;
    }
    
    int blankCnt = 0;
    for (int i = 0; i < len; ++i)
    {
        if (str[i] == ' ')
        {
            ++blankCnt;
        }
    }
    
    char *pi = str+len-1;
    char *pj = str+len+blankCnt*2-1;
    int cur = len-1;
    str[len+blankCnt*2] = '\0';
    while (blankCnt > 0)
    {
        while (str[cur] != ' ')
        {
            str[cur + blankCnt*2] = str[cur];
            --cur;
        }
        str[cur+blankCnt*2] = '0';
        str[cur+blankCnt*2-1] = '2';
        str[cur+blankCnt*2-2] = '%';
        --blankCnt;
        --cur;
    }
}

int main()
{
    char string[20] = "we are happy";
    ReplaceBlank(string, strlen(string));
    cout << string << endl;
    return 0;
}