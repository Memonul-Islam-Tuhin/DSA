//https://docs.google.com/document/d/1MioUnRGIA_F5-X7--OJAZ7aAd9pM1V156OMhxto7FHY/edit?tab=t.0
#include <bits/stdc++.h>
using namespace std;

class Node
{

public:

    int val;
    Node*left;
    Node*right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void preorder(Node*root)
{
    if(root == NULL)
    {
        return;
    }

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node*root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void postorder(Node*root)
{
    if(root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

int main()
{
    Node*root = new Node(10);

    root->left = new Node(20);
    root->right = new Node(30);

    root->left->left = new Node(40);
    root->left->right = new Node(50);

    root->left->right->left = new Node(60);
    root->left->right->right = new Node(70);


    root->right->right = new Node(80);
    root->right->right->left = new Node(90);

    cout << "Preorder = ";
    preorder(root);
    cout << endl;

    cout << "Inorder = ";
    inorder(root);
    cout << endl;

    cout << "Postorder = ";
    postorder(root);
    cout << endl;

    return 0;
}
