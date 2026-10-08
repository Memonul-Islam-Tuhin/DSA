#include<bits/stdc++.h>
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
    tail = newNode;
}

void print_link_list(Node*head)
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

    for(Node * i = head; i->next != NULL; i = i->next)
    {
        for(Node * j = i->next; j != NULL; j = j->next)
        {
            if(i->val > j->val)
            {
                swap(i->val,j->val);
            }
        }
    }

//    print_link_list(head);
//
//    Node*temp = head;
//    int idx = 0;
//    while(temp->next != NULL)
//    {
//        if(temp->val == temp->next->val)
//        {
//            cout << "Duplicate found" << endl;
//            print_link_list(head);
//        }
//
//        temp = temp->next;
//        idx++;
//    }
//
//    cout << "No duplicate found" << endl;

    Node *i = head;
    while(i != NULL)
    {
        Node*j = i;
        while(j->next != NULL)
        {
            if(i->val == j->next->val)
            {
                Node*deleteNode = i->next;
                i->next = i->next->next;
                delete deleteNode;
            }
            else
            {
                j = j->next;
            }
        }
        i = i->next;
    }

    print_link_list(head);

    return 0;
}
