#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int val;
    Node*next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class MyQueue
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
        tail = newNode;
    }

    void pop()
    {
        count--;
        Node*deleteNode = head;
        head = head->next;
        delete deleteNode;
        if(head == NULL)
        {
            tail = NULL;
        }
    }

    int front()
    {
        return head->val;
    }

    int back()
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
