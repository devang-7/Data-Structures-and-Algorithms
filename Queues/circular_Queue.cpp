#include <iostream>

using namespace std;

class Queue
{

    int *arr;
    int size;
    int rear, front;
public:
    Queue(int capacity)
    {
        front = rear = -1;
        size = capacity;
        arr = new int[capacity];
    }

    void enqueue(int element);
    int dequeue();
    bool isEmpty();
    bool isFull();
    void displayQueue();
};

void Queue::enqueue(int value)
{
    if ((front == 0 && rear == size-1) ||
            (rear == (front-1)%(size-1)))
    {
        printf("\nQueue is Full");
        return;
    }
  
    else if (front == -1) /* Insert First Element */
    {
        front = rear = 0;
        arr[rear] = value;
    }
  
    else
    {
        rear= (rear+1)%(size);
        arr[rear] = value;
    }
}
 

int Queue::dequeue()
{
    int data = arr[front];
    if (isEmpty())
        cout << "Kya re bhadwe? Abhi toh smjhaya";
    else
    {
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
            front = 0;
        else
            front = front + 1;
    }
    return data;
}

bool Queue::isEmpty()
{
    if (front == -1 && rear == -1)
        return true;
    return false;
}

bool Queue::isFull()
{
    if ((front == 0 && rear == size - 1) || (rear == front - 1))
        return true;
    return false;
}

void Queue::displayQueue()
{
    int temp_front = front;
    if (isEmpty())
        cout << "Sorry";

    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
    }
    else if(rear<front)
    {
        int temp_front = front;
        while (temp_front < size)
        {
            cout << arr[temp_front] << " ";
            temp_front++;
        }

        temp_front = 0;
        while (temp_front <= rear)
        {
            cout << arr[temp_front] << " ";
            temp_front++;
        }
    }
}

int main()
{

    Queue q(5);
    /* pass*/
}