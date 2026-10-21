#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
public :
    vector<int>v;

    void push(int val)
    {
        v.push_back(val);
    }

    void pop()
    {
        if(!v.empty())
        {
            v.erase(v.begin());
        }
    }

    int front()
    {
        return v.front();
    }

    int back()
    {
        return v.back();
    }

    int size()
    {
        return v.size();
    }

    bool empty()
    {
        return v.empty();
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
        cout << que.front() << endl;
        que.pop();
    }
    return 0;
}
