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

class myStack
{
public :
    Node*head = NULL;
    Node*tail = NULL;
    int count = 0;

    void push(int val)
    {
        count++;
        Node*newNode = new Node(val);
        if(head==NULL)
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
        if (head == NULL)
        {
            return;
        }

        Node* deleteNode = tail;

        if (head == tail)
        {
            head = NULL;
            tail = NULL;
            return;
        }

        Node* temp = head;

        while (temp->next != tail)
        {
            temp = temp->next;
        }

        tail = temp;
        delete deleteNode;
        tail->next = NULL;
    }

    int top()
    {
        if (tail == NULL)
        {
            return -1;
        }

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
    myStack st;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        st.push(val);
    }

    while(!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}
