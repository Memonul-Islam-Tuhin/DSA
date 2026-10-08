#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = next;
    }
};

void insert_at_tail_optimized(Node *&head, Node *&tail, int val)
{

    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;

        return;
    }

    tail->next = newNode;
    tail = newNode;
};

int print_link_list(Node *head)
{

    Node *temp = head;

    while (temp != NULL)
    {
        /* code */
        cout << temp->val << endl;
        temp = temp->next;
    }
};

int main()
{

    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *tail = new Node(30);

    head->next = a;
    a->next = tail;

    insert_at_tail_optimized(head, tail, 100);
    print_link_list(head);

    return 0;
}