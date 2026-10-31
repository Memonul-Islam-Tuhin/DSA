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

Node* input_tree()
{
    int val;
    cin >> val;
    Node*root;

    if(val == -1) root = NULL;
    else root = new Node(val);

    queue<Node*>que;
    if(root) que.push(root);


    while(!que.empty())
    {
        Node* p = que.front();
        que.pop();

        int l,r;
        cin >> l >> r;

        Node*myLeft,*myRight;
        if(l == -1) myLeft = NULL;
        else myLeft = new Node(l);

        if(r == -1) myRight = NULL;
        else myRight = new Node(r);

        p->left = myLeft;
        p->right = myRight;

        if(p->left)  que.push(p->left);
        if(p->right) que.push(p->right);
    }

    return root;
}

void level_order(Node*root)
{
    if(root == NULL)
    {
        cout << "No Tree";
        return;
    }
    queue<Node*>que;
    que.push(root);

    while(!que.empty())
    {
        Node* f = que.front();
        que.pop();
        cout << f->val << " ";
        if(f->left) que.push(f->left);
        if(f->right) que.push(f->right);
    }
}

int main()
{
    Node*root = input_tree();
    level_order(root);

    return 0;
}
