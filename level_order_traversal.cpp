
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node* left;
    Node* right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void level_order(Node*root)
{
    if(root == NULL) return;
    queue<Node*>que;
    que.push(root);

    while(!que.empty())
    {
        Node* f = que.front();
        que.pop();
        cout << f->val << " ";
        if(f->left)
        {
            que.push(f->left);
        }
        if(f->right)
        {
            que.push(f->right);
        }
    }
}

int main()
{
    Node*root = new Node(10);
    Node*a = new Node(20);
    Node*b = new Node(30);
    Node*c = new Node(40);
    Node*d = new Node(50);
    Node*e = new Node(60);

    root->left = a;
    root->right = b;
    a->left = c;
    b->left = d;
    b->right = e;

    level_order(root);

    return 0;
}
