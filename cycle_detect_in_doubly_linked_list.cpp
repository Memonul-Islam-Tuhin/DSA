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

int main()
{

    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);

    // forward link
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = d;

    // backward link
    head->prev = NULL;
    a->prev = head;
    b->prev = a;
    c->prev = b;
    d->prev = c;

    Node*slow = head;
    Node*fast = head;
    bool flag = false;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            // detecting cycle
            flag = true;
            break;
        }
    }

    if(flag == true)
    {
        cout << "cycle detected" << endl;
    }
    else
    {
        cout << "No cycle detected" << endl;
    }
    return 0;
}
