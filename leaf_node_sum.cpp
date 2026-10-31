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

int leaf_nodes_sum(Node*root)
{
    if(root == NULL)
    {
        return 0;
    }

    if(root->left == NULL && root->right == NULL)
    {
        return root->val;
    }

    int l = leaf_nodes_sum(root->left);
    int r = leaf_nodes_sum(root->right);

    return l + r;
}

int main()
{
    Node*root = input_tree();
    cout << leaf_nodes_sum(root);

    return 0;
}
