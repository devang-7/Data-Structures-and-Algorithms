// Chaining is a hashing technique where a linked list is created to resolve collision

// Loading factor(lambda) = (no of keys)/(size of the table)

// Analysis is always based on the loading factor.

// Explaining the case of collision:
// If two values are pointing to the same index, the linked list is used to link the elements at the same index.

//Ques: How to tackle the case of all the elements pointing to the same index?
//Ans: Programmer has to select a proper hash function so that all the elements are distributed equally.

// C++ code to demonstrate hashing using chaining

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public: 
    int data;
    Node *next;
};

void SortedInsert(Node **X, int x)
{
    Node *t, *q = NULL, *p = *X;
    t = new Node;
    t->data = x;
    t->next = NULL;
    if (p== NULL)
        *X = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }

        if (p == *X)
        {
            t->next = p;
            *X = t;
        }

        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}
int Search(Node *p, int key)
{
    int count = -1;
    while (p != NULL)
    {
        if (key == p->data)
        {
            return count;
        }
        p = p->next;
        count++;
    }
    return count;
}

int hashing(int key)
{
    return key % 10;
}
void Insert(Node *H[], int key)
{
    int index = hashing(key);
    SortedInsert(&H[index], key);
}
int main()
{
    Node *HT[10];
   int temp;
    int i;
    for (i = 0; i < 10; i++)
        HT[i] = NULL;

    Insert(HT, 12);
    Insert(HT, 12);
    Insert(HT, 42);

    temp = Search(HT[hashing(42)], 42);
    printf("%d ", temp);
    return 0;
}

