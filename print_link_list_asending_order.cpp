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

void insert_at_tail(Node* &head, Node* &tail, int val)
{
    Node* newnode = new Node(val);
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }

    tail->next = newnode;
    tail = tail->next;
}

void print_link_list_asending_order_sort(Node*head)
{
    Node*temp = head;
    while(temp != NULL && temp->next != NULL)
    {
        if(temp-> val > temp->next->val)
        {
            cout << "NO" << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "YES" << endl;
}

int main()
{

    Node*head = NULL;
    Node*tail = NULL;

    int val;
    while(cin >> val)
    {
        if(val == -1)
        {
            break;
        }
        insert_at_tail(head,tail,val);
    }

    print_link_list_asending_order_sort(head);
    return 0;
}
