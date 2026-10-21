#include <bits/stdc++.h>
using namespace std;

class MyStack
{
public:
    queue<int> que;
    MyStack()
    {

    }

    void push(int x)
    {
        que.push(x);
    }

    int pop()
    {
        queue<int> que2;
        int val;
        while(!que.empty())
        {
            val = que.front();
            que.pop();
            if(que.empty() == true)
                break;
            que2.push(val);
        }
        que = que2;
        return val;
    }

    int top()
    {
        return que.back();
    }

    bool empty()
    {
        return que.empty();
    }
};

int main()
{
    MyStack st;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        st.push(val);
    }

    while(!st.empty())
    {
        cout << st.pop() << endl;
    }

    return 0;
}
