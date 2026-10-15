#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_tail(Node*& head, Node*& tail, int val)
{
    Node* newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void sort_list(Node* head)
{
    for (Node* i = head; i != NULL; i = i->next)
    {
        for (Node* j = i->next; j != NULL; j = j->next)
        {
            if (i->val > j->val)
            {
                swap(i->val, j->val);
            }
        }
    }
}

void remove_duplicate(Node*& head, Node*& tail)
{
    Node* current = head;

    while (current != NULL)
    {
        Node* temp = current;

        while (temp->next != NULL)
        {
            if (temp->next->val == current->val)
            {
                Node* duplicate = temp->next;

                temp->next = duplicate->next;

                if (duplicate->next != NULL)
                {
                    duplicate->next->prev = temp;
                }
                else
                {
                    tail = temp;
                }

                delete duplicate;
            }
            else
            {
                temp = temp->next;
            }
        }

        current = current->next;
    }
}

void print_list(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }
}


int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    int val;

    while (cin >> val && val != -1)
    {
        insert_at_tail(head, tail, val);
    }

    sort_list(head);
    remove_duplicate(head, tail);
    print_list(head);

    while (head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
