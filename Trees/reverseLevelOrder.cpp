#include "linkedlistTree.cpp"
#include <stack>

void Node::reverseLevelOrder(Node *root)
{
    queue<Node *> q;
    stack<int> s;
    Node *temp;

    q.push(root);

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->right)
            q.push(temp->right);

        if (temp->left)
            q.push(temp->left);

        s.push(temp->data);
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

Node *Node::deepestNode(Node *root)
{
    queue<Node *> q;
    int level = 0;
    q.push(root);
    Node *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    return temp;
}

// int main()
// {
//     Node temp;
//     Node *newNode;
//     temp.insertBinaryTree(3);
//     temp.insertBinaryTree(2);
//     temp.insertBinaryTree(1);

//     int tempa;
//     tempa = temp.heightBinaryTree(root);
//     cout<<tempa;
// }