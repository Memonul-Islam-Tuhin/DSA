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

        if(p->left) que.push(p->left);
        if(p->right) que.push(p->right);
    }

    return root;
}

int max_height(Node*root)
{
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 0;
    int l = max_height(root->left);
    int r = max_height(root->right);

    return max(l,r) + 1;
}

int count_nodes(Node* root)
{
    if(root == NULL)
        return 0;
    int l = count_nodes(root->left);
    int r = count_nodes(root->right);
    return l+r+1;
}

int main()
{
    Node*root = input_tree();
    int mx_dep = max_height(root);
    int total_Nodes = count_nodes(root);
    int cal = pow(2, mx_dep + 1) - 1;

    cout << "Total nodes : " << total_Nodes << endl;
    cout << "Perfect binary nodes : " << cal << endl;
    return 0;
}
