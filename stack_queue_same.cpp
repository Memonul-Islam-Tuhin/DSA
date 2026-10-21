#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int>st;
    queue<int>que;

    int n,m;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        st.push(val);
    }

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int val;
        cin >> val;
        que.push(val);
    }

    if(n != m)
    {
        cout << "NO" << endl;
        return 0;
    }

    bool flag = true;
    while(!st.empty() && !que.empty())
    {
        if(st.top() != que.front())
        {
            flag = false;
            break;
        }

        st.pop();
        que.pop();
    }

    if(flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
