#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
public :
    int arr[100];
    int front_idx;
    int back_idx;
    int count;

    MyQueue()
    {
        front_idx = 0;
        back_idx = -1;
        count = 0;
    }

    void push(int val)
    {
        count++;
        if(count == 100)
        {
            return;
        }

        back_idx = (back_idx + 1) % 100;
        arr[back_idx] = val;
    }

    void pop()
    {
        count--;
        if(count == 0)
        {
            return;
        }

        front_idx = (front_idx + 1) % 100;
    }

    int front()
    {
        return arr[front_idx];
    }

    int back()
    {
        return arr[back_idx];
    }

    int size()
    {
        return count;
    }

    bool empty()
    {
        return (count == 0);
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

