#include<bits/stdc++.h>
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

void insert_at_head(Node *&head,Node*&tail, int val)
{

    Node *newNode = new Node(val);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insert_at_any_position(Node *&head, int idx, int val)
{

    Node *newNode = new Node(val);

    Node *temp = head;

    for (int i = 1; i < idx; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            return;
        }
    }

    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

int size_link_list(Node*head)
{
    int count = 0;
    Node*temp = head;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
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


    int q;
    cin >> q;
    while(q--)
    {
        int idx,val;
        cin >> idx >> val;
        int sz = size_link_list(head);
        if(idx > sz || idx < 0)
        {
            cout << "Invalid" << endl;
            continue;
        }
        else if(idx == sz)
        {
            insert_at_tail(head,tail,val);
        }
        else if(idx == 0)
        {
            insert_at_head(head,tail,val);
        }
        else
        {
            insert_at_any_position(head,idx,val);
        }

        print_forward(head);
    }
    return 0;
}
