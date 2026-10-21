#include <bits/stdc++.h>
using namespace std;

int main()
{

    queue<int>que1,que2;
    stack<int>st;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        que1.push(val);
    }

    while(!que1.empty())
    {
        st.push(que1.front());
        que1.pop();
    }

    while(!st.empty())
    {
        que2.push(st.top());
        st.pop();
    }

    while(!que2.empty())
    {
        cout << que2.front() << " ";
        que2.pop();
    }
    return 0;
}
