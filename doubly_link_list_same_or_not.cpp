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

int count_link_list(Node*head)
{
    int count = 0;
    Node*temp = head;
    while(temp != NULL)
    {
//      cout << temp->val << " ";
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

    int size1 = count_link_list(head1);
    int size2 = count_link_list(head2);

    if(size1 != size2)
    {
        cout << "NO" << endl;
    }
    else
    {
        Node*temp1 = head1;
        Node*temp2 = head2;
        int flag = 0;
        while(temp1 != NULL && temp2 != NULL)
        {
            if(temp1->val != temp2->val)
            {
                flag = 1;
                break;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
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
    return 0;
}
