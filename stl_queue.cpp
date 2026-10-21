#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> que;
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



