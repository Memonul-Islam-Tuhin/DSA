#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int val;
    Node*next;
    Node*prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class MyStack
{
public :
    Node*head = NULL;
    Node*tail = NULL;
    int count = 0;

    void push(int val)
    {
        count++;
        Node*newNode = new Node(val);
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void pop()
    {
        count--;
        Node*deleteNode = tail;
        tail = tail->prev;
        delete deleteNode;
        if(tail == NULL)
        {
            head = NULL;
            return;
        }

        tail->next = NULL;
    }

    int top()
    {
        return tail->val;
    }

    int size()
    {
        return count;
    }

    bool empty()
    {
        return head == NULL;
    }

    void clear()
    {
        while(!empty())
        {
            pop();
        }
    }
};

int main()
{
    MyStack st1,st2;

    int n,m;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        st1.push(val);
    }

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int val;
        cin >> val;
        st2.push(val);
    }

    if(st1.size() != st2.size())
    {
        cout << "NO" << endl;
        return 0;
    }

    bool flag = true;
    while(!st1.empty() && !st2.empty())
    {
        if(st1.top() != st2.top())
        {
            flag = false;
            break;
        }
        st1.pop();
        st2.pop();
    }

    if(flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    st1.clear();
    st2.clear();
    return 0;
}
