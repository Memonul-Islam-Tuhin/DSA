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

void find_duplicate_link_list(Node*head)
{
    Node*currentNode = head;
    while(currentNode != NULL)
    {
        Node*temp = currentNode->next;
        while(temp != NULL)
        {
            if(currentNode->val == temp->val)
            {
                cout << "YES" << endl;
                return;
            }

            temp = temp->next;
        }

        currentNode = currentNode->next;
    }

    cout << "NO" << endl;
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

    find_duplicate_link_list(head);
    return 0;
}
