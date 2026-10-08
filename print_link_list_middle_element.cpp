
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

void  print_link_list_middle_element(Node*head)
{
    Node*slow = head;
    Node*fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        if(fast->next->next == NULL)
        {
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    if(fast == NULL)
    {
        cout << slow->val << endl;
    }

    else
    {
        cout << slow->val << " " << slow->next->val << endl;
    }
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

    print_link_list_middle_element(head);
    return 0;
}
