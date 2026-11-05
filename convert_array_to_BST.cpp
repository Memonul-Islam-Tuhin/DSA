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

        if(f->left) que.push(f->left);
        if(f->right) que.push(f->right);
    }
}

Node* convert(int arr[],int n, int l, int r)
{
    if(l > r) return NULL;
    int mid = (l + r) / 2;
    Node* root = new Node(arr[mid]);

    Node* leftroot = convert(arr,n,l,mid - 1);
    Node* rightroot = convert(arr,n,mid + 1,r);

    root->left = leftroot;
    root->right = rightroot;

    return root;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Node* root = convert(arr,n,0,n-1);
    level_order(root);
    return 0;
}
