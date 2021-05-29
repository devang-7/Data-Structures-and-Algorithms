#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *front = NULL, *rear = NULL;

bool isEmpty() //Function to check whether the queue is empty
{
    if (front == NULL)
        return true;
    return false;
}

void Enqueue(int val) //Function to add elements in the queue
{
    Node *tempNode = new Node;
    tempNode->next = NULL;
    tempNode->data = val;
    if (front == NULL)
    {
        front = tempNode;
        rear = tempNode;
    }
    else
    {
        rear->next = tempNode;
        rear = tempNode;
    }
}

void Dequeue() //Function to delete the elements in queue
{
    Node *tempNode = front;
    if (!isEmpty())
    {
        front = front->next;
        delete (tempNode);
    }
    else
    {
        cout << "Already empty!!";
    }
}

void Display() //Function to display the queue
{
    Node *temp = front;
    while (temp)
    {
        cout << temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
 printf("1/2 = %f",(float)(1/2));
}