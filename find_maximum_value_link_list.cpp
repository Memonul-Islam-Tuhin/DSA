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


int find_maximum(Node*head)
{
    int mx = INT_MIN;
    Node*temp = head;
    while(temp != NULL)
    {
        mx = max(mx,temp->val);
        temp = temp->next;

    }

    return mx;
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

//    print_link_list(head);
    cout << find_maximum(head) << endl;

    return 0;
}
