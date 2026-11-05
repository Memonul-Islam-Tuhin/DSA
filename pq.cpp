#include <bits/stdc++.h>
using namespace std;

int main()
{

    priority_queue<string>,greater<string>>pq;

    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        pq.push(str);
    }


    while(!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
    return 0;
}
