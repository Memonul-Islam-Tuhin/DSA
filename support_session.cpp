#include <bits/stdc++.h>
using namespace std;

int main()
{
    int query;
    cin >> query;
    queue<string>que;
    while(query--)
    {
        string cmd;
        cin >> cmd;
        if(cmd == 'JOIN')
        {
            string name;
            cin >> name;
            que.push(name);
        }
        else if(cmd == 'DONE')
        {
            if(que.empty())
            {
                cout<< "No Student" << endl;
            }
            else
            {
                cout << que.front() << endl;
                que.pop();
            }
        }
    }
    return 0;
}
