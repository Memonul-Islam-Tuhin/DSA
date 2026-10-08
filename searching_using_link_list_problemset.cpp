// https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/B
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

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        insert_at_tail(head,tail,val);
    }


    int target_val;
    cin >> target_val;

    int idx = 0;
    bool flag = false;

    Node*temp = head;
    while(temp != NULL)
    {
        if(temp->val == target_val)
        {
            cout << idx << endl;
            flag = true;
            break;
        }
        temp = temp->next;
        idx++;
    }

    if(flag == false)
    {
        cout << -1 << endl;
    }
//    print_link_list(head);

    return 0;
}
