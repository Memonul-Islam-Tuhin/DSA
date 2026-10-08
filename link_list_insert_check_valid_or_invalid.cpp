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

void insert_at_head(Node *&head, int val)
{

    Node *newNode = new Node(val);
    newNode->next = head;
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
    temp->next = newNode;
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

//int main()
//{
//
//    Node*head = NULL;
//    Node*tail = NULL;
//
//    int val;
//
//    while(cin >> val && val != -1)
//    {
//        insert_at_tail(head,tail,val);
//    }
//
//    int q;
//    cin >> q;
//
//    while(q--)
//    {
//        int idx,val;
//        cin >> idx >> val;
//        if(idx < 0)
//        {
//            cout << "Invalid" << endl;
//            continue;
//        }
//
//        if(idx == 0)
//        {
//            Node*newNode = new Node(val);
//            newNode->next = head;
//            head = newNode;
//
//            if(tail == NULL)
//            {
//                tail = newNode;
//            }
//
//            print_link_list(head);
//            continue;
//        }
//
//        Node*temp = head;
//        for(int i = 1; i < idx; i++)
//        {
//            if(temp == NULL)
//            {
//                break;
//            }
//            temp = temp->next;
//        }
//
//        if(temp == NULL)
//        {
//            cout << "Invalid" << endl;
//            continue;
//        }
//
//        Node*newNode = new Node(val);
//        newNode->next = temp->next;
//        temp->next = newNode;
//
//        if(newNode->next == NULL)
//        {
//            tail = newNode;
//        }
//
//        print_link_list(head);
//    }
//
//    return 0;
//}


int main()
{

    Node*head = NULL;
    Node*tail = NULL;

    int val;
    while(true)
    {
        cin >> val;
        if(val == -1)
        {
            break;
        }

        insert_at_tail(head,tail,val);
    }

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
            insert_at_head(head,val);
        }
        else
        {
            insert_at_any_position(head,idx,val);
        }

        print_link_list(head);
    }

    return 0;
}

