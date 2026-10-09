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

void insert_at_tail(Node*&head,Node*&tail,int val)
{
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

void print_forward(Node*head)
{
    Node*temp = head;
    while(temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << endl;
}


int main()
{
    Node*head = NULL;
    Node*tail = NULL;

    int val;
    while(cin >> val && val != -1)
    {
        insert_at_tail(head,tail,val);
    }

    if (head == NULL || head == tail)
    {
        cout << "YES" << endl;
        return 0;
    }


    int flag = 0;
    for(Node *i=head,*j=tail; i!=j && i->prev !=j ; i=i->next, j=j->prev)
    {
        if(i->val != j->val)
        {
            flag = 1;
            break;
        }
    }

    if(flag == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

}
