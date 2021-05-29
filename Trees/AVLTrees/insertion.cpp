#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    int height;
};

int height(Node *root)
{
    if (!root)
        return -1;

    int lt = height(root->left);
    int rt = height(root->right);

    if (lt > rt)
        return lt + 1;
    else
        return rt + 1;
}

Node *leftLeftImbalance(Node *X) //SRL
{
    Node *W = X->left;
    X->left = W->right;
    W->right = X;
    X->height = height(X);
    W->height = height(W);
    return W;
}

Node *rightRightImbalance(Node *W) //SRR
{
    Node *X = W->right;
    W->right = X->left;
    X->left = W;
    W->height = height(W);
    X->height = height(X);
    return X;
}

Node *leftRightImbalance(Node *X)
{
    X->left = rightRightImbalance(X->left);
    return leftLeftImbalance(X);
}

Node *rightLeftImbalance(Node *X)
{
    X->right = leftLeftImbalance(X->right);
    return rightRightImbalance(X);
}

Node *insertion(Node *root, int data)
{
    Node *temp = new Node;
    if (root == NULL)
    {
        temp->val = data;
        temp->left = NULL;
        temp->right = NULL;
        temp->height = 0;
        root = temp;
    }
    else if (data < root->val)
    {
        root->left = insertion(root->left, data);
        if (height(root->left) - height(root->right) >= 2)
        {
            if (data < root->left->val)
                root = leftLeftImbalance(root);
            else
                root = leftRightImbalance(root);
        }
    }

    else if (data > root->val)
    {
        root->right = insertion(root->right, data);
        if ((height(root->right) - height(root->left)) >= 2)
        {
            if (data > root->right->val)
                root = rightRightImbalance(root);
            else
                root = rightLeftImbalance(root);
        }
    }

    root->height = height(root);
    return root;
}

void preorder(Node *root)
{
    if (root)
    {
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}


int main()
{
    Node *root = insertion(NULL, 50);
    root = insertion(root, 51);

    preorder(root);
    cout << endl;

    root = insertion(root, 56);

    preorder(root);
    cout << endl;

    root = insertion(root, 59);
    // root = insertion(root, 23);
    // root = insertion(root, 54);
    // root = insertion(root, 14);
    // root = insertion(root, 19);
    // root = insertion(root, 72);
    // root = insertion(root, 12);
    // root = insertion(root, 67);
    //root= insertion()
    cout<<"preorder = ";preorder(root);
    cout << endl;
    inorder(root);
    
    // cout<<root->left->val<<" "<<root->right->val;
    return 0;
}