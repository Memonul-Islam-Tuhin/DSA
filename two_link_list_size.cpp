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


int count_link_list(Node*head)
{
    int count = 0;
    Node*temp = head;
    while(temp != NULL)
    {
//        cout << temp->val << " ";
        count++;
        temp = temp->next;

    }

    return count;
}

int main()
{

    Node*head1 = NULL;
    Node*tail1 = NULL;

    int val;
    while(cin >> val && val != -1)
    {
        insert_at_tail(head1,tail1,val);
    }

    Node*head2 = NULL;
    Node*tail2 = NULL;

    while(cin >> val && val != -1)
    {
        insert_at_tail(head2,tail2, val);
    }

//    print_link_list(head);

    if(count_link_list(head1) == count_link_list(head2))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
