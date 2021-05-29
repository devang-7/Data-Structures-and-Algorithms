#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    void insert(int data);                       /*Insertion in a binary search tree */
    Node* insertBinarySearchTree(Node *root, int data); /* Insertion in a binary tree */
    void insertBinaryTree(int val);

    /*For finding the size*/
    int sized(Node *root);
    int modifiedSize(Node* root);

    /*Traversals*/
    void inorderTraversal(Node *root);
    void preorderTraversal(Node *root);
    void postOrderTraversal(Node *root);
    void levelOrderTraversal(Node *root);

    /*Searching for the maximum value */
    int maximumValueR(Node *root); //Using recursion
    int maximumValue(Node *root);  //Without recursion

    /* For deleting the entire binary tree*/
    void deleteBinaryTree(Node *root);

    /*To find the height of the tree*/
    int heightBinaryTree(Node *root); //finds height of the binary tree
    int heightEdge(Node *root);       //to find height in terms of edges

    /*Miscellaneous functions*/
    void reverseLevelOrder(Node *root); //To print the elements of the tree in reverse with level order traversal
    Node *deepestNode(Node *root);      //finds deepest node in the tree

} *root = NULL, *current = NULL;

///////////////////////*Functions*//////////////////////

void Node::insert(int val) //for BST  - - -Brute force
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    Node *current = root;
    Node *prev = root;
    if (root == NULL)
    {
        root = temp;
        current = temp;
    }

    else
    {
        while (current)
        {
            if (val < current->data)
            {
                prev = current;
                current = current->left;
            }
            else
            {
                prev = current;
                current = current->right;
            }
        }

        if (val > prev->data)
            prev->right = temp;
        else
            prev->left = temp;
    }
}

void Node::insertBinaryTree(int val)
{
    Node *temp;
    Node *newNode = new Node;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = val;
    if (!root)
    {
        root = newNode;
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->left)
            q.push(temp->left);
        else
        {
            temp->left = newNode;
            return;
        }

        if (temp->right)
            q.push(temp->right);

        else
        {
            temp->right = newNode;
            return;
        }
    }
}

Node* Node::insertBinarySearchTree(Node *root, int val)
{

    if (root == NULL)
    {
        root= new Node;
        root->left=NULL ;
        root->right=NULL;
        root->data = val;
    }

    else
    {
        if (root->data > val)
            root->left= insertBinarySearchTree(root->left, val);
        
        else if(root->data < val)
            root->right = insertBinarySearchTree(root->right,val);
    }

    return root;
}

void Node::inorderTraversal(Node *root)
{
    Node *p = root;
    if (p)
    {

        inorderTraversal(p->left);
        cout << p->data << " ";
        inorderTraversal(p->right);
    }
}

void Node::preorderTraversal(Node *root)
{
    Node *p = root;
    if (p)
    {
        cout << p->data << " ";
        preorderTraversal(p->left);
        preorderTraversal(p->right);
    }
}

void Node::postOrderTraversal(Node *root)
{
    Node *p = root;
    if (p)
    {

        postOrderTraversal(p->left);
        postOrderTraversal(p->right);
        cout << p->data << " ";
    }
}

void Node::levelOrderTraversal(Node *root)
{
    Node *p = root;
    queue<Node *> Q;
    Q.push(p);

    while (!Q.empty())
    {
        Node *temp;
        temp = Q.front();
        cout << temp->data << " ";
        Q.pop();

        if (temp->left)
            Q.push(temp->left);

        if (temp->right)
            Q.push(temp->right);
    }
}

int Node::maximumValueR(Node *root)
{
    int root_val, left, right;
    int maxElement = INT_MIN;
    if (root)
    {
        root_val = root->data;
        left = maximumValueR(root->left);
        right = maximumValueR(root->right);
        maxElement = max(root_val, max(left, right));
    }
    return maxElement;
}

int Node::maximumValue(Node *root)
{
    queue<Node *> q;
    q.push(root);
    Node *temp;
    int maxE = INT_MIN;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (maxE < temp->data)
            maxE = temp->data;

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }
    return maxE;
}

void Node::deleteBinaryTree(Node *root)
{
    if (root == NULL)
        return;

    deleteBinaryTree(root->left);
    deleteBinaryTree(root->right);
    free(root);
}

int Node::heightBinaryTree(Node *root)
{
    int x = 0, y = 0;
    if (root == 0)
        return 0;
    x = heightBinaryTree(root->left);
    y = heightBinaryTree(root->right);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}

int Node::heightEdge(Node *root)
{
    if (root == NULL)
        return -1;

    int left = heightEdge(root->left);
    int right = heightEdge(root->right);

    if (left > right)
        return left + 1;
    else
        return right + 1;
}

int Node::sized(Node *root)
{

    queue<Node *> s;
    s.push(root);
    Node *temp;
    int count = 0;
    while (!s.empty())
    {
        temp = s.front();
        s.pop();
        count++;
        if (temp->left)
            s.push(temp->left);

        if (temp->right)
            s.push(temp->right);
    }
    return count;
}

int Node:: modifiedSize(Node* root)
{
    if(root==NULL)
        return 0;
    else return(modifiedSize(root->left)+1+modifiedSize(root->right));    
}


int main()
{
    Node temp;
    int ocunt;
    
    root = temp.insertBinarySearchTree(root,3);
    root= temp.insertBinarySearchTree(root,2);
    root= temp.insertBinarySearchTree(root,4);
    root= temp.insertBinarySearchTree(root,1);
    root= temp.insertBinarySearchTree(root,7);
    root= temp.insertBinarySearchTree(root,8);
    root= temp.insertBinarySearchTree(root,9);
    root= temp.insertBinarySearchTree(root,10);
    ocunt = temp.modifiedSize(root);  
    cout<<ocunt;
}