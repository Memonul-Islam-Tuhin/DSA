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
        Node*p = que.front();
        que.pop();

        int l,r;
        cin >> l >> r;
        Node* myLeft,*myRight;
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

bool search(Node* root, int val)
{
    if(root == NULL) return false;
    if(root->val == val) return true;

    if(root->val > val) return search(root->left,val);
    else return search(root->right,val);
}

int main()
{
    Node* root = input_tree();
    int val;
    cin >> val;
    if(search(root,val)) cout << "Found" << endl;
    else cout << "Not Found" << endl;
    return 0;
}


