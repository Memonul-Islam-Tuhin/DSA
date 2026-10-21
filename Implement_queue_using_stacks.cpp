#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
public:
    stack<int> st;
    MyQueue()
    {

    }

    void push(int val)
    {
        st.push(val);
    }

    int pop()
    {
        stack<int> st2;
        int val;
        while(!st.empty())
        {
            val = st.top();
            st.pop();
            if(st.empty() == true)
                break;
            st2.push(val);
        }
        while(!st2.empty())
        {
            st.push(st2.top());
            st2.pop();
        }
        return val;
    }

    int peek()
    {
        stack<int> st2;
        int val;
        while(!st.empty())
        {
            val = st.top();
            st.pop();
            st2.push(val);
        }
        while(!st2.empty())
        {
            st.push(st2.top());
            st2.pop();
        }
        return val;
    }

    bool empty()
    {
        return st.empty();
    }
};

int main()
{
    MyQueue que;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        que.push(val);
    }

    while(!que.empty())
    {
        cout << que.pop() << endl;
    }
    return 0;
}
