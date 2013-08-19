#include <iostream>
#include <stack>


using namespace std;


bool IsPopOrder(int *pushOrder, int *popOrder, int length)
{
    stack<int> pushStack;
    int pos = 0;
    for(int i = 0; i < length; ++i)
    {
        if(pushStack.empty() || pushStack.top() != popOrder[i])
        {
            while(pos < length && pushOrder[pos] != popOrder[i])
            {
                pushStack.push(pushOrder[pos++]);
            }
            if (pos >= length)
            {
                return false;
            }
            else
            {
                ++pos;
            }
        }
        else
        {
            pushStack.pop();
        }
    }
    return true;
}


int main()
{
    int pushOrder[] = {1, 2, 3, 4, 5};
    int popOrder1[] = {4, 5, 3, 2, 6};
    int popOrder2[] = {4, 3, 5, 1, 2};
    int popOrder3[] = {5, 4, 3, 2, 1};

    cout << IsPopOrder(pushOrder, popOrder1, 5) << endl;
    cout << IsPopOrder(pushOrder, popOrder2, 5) << endl;
    cout << IsPopOrder(pushOrder, popOrder3, 5) << endl;

    return 0;
}

