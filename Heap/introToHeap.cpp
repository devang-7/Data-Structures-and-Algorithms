#include <bits/stdc++.h>

using namespace std;

class Heap
{
public:
    int *arr;
    int count;
    int capacity;
    int heap_type; // '1' denotes maxHeap and '0' denotes minHeap

    Heap() //constructor to initialise Heap class
    {

        this->heap_type = 1;
        this->capacity = 10;
        this->arr = new int[this->capacity];
    }
};

void resizeHeap(Heap *h)
{
    int *array_old = h->arr;
    h->arr = new int[h->capacity * 2];

    for (int i = 0; i < h->capacity; i++)
    {
        h->arr[i] = array_old[i];
    }
    h->capacity *= 2;
    delete (array_old);
}

int leftChild(Heap *x, int i)
{
    int left = 2 * i + 1;
    if (left >= x->count)
        return -1;
    return left;
}

int rightChild(Heap *x, int i)
{
    int right = 2 * i + 2;
    if (right >= x->count)
        return -1;
    return right;
}

Heap *createHeap(int cap, int h_type)
{
    Heap *h = new Heap();
    h->heap_type = h_type;
    h->capacity = cap;
    h->arr = new int[h->capacity];

    return h;
}

int parentPtr(Heap *h, int i) //returns the position of the parent
{
    if (i <= 0 || i >= h->count)
        return -1;
    return (i - 1) / 2;
}

int maxElement(Heap *h, int i) //For MaxHeap, similar in the case of MinHeap
{
    if (h->count == 0)
        return -1;
    return h->arr[0];
}

//Heapifying the element at location at i

void percolateDown(Heap *x, int i)
{
    int max, l, r, temp;

    l = leftChild(x, i);
    r = rightChild(x, i);

    if (l == -1 && r == -1)
        return;

    if (l != -1 && x->arr[i] < x->arr[l])
        max = l;
    else
        max = i;

    if (r != -1 && x->arr[max] < x->arr[r])
        max = r;

    if (max != i)
    {
        temp = x->arr[i];
        x->arr[i] = x->arr[max];
        x->arr[max] = temp;
    }
    if (max == i)
        return;
    percolateDown(x, max);
}

int deleteMax(Heap *h)
{
    int data;

    data = h->arr[0];

    h->arr[0] = h->arr[h->count - 1];
    h->count -= 1;

    percolateDown(h, 0);
    return data;
}

void buildHeap(Heap *h, int buildArr[], int n)
{
    if (h == NULL)
        return;

    while (n > h->capacity)
        resizeHeap(h);

    for (int i = 0; i < n; i++)
        h->arr[i] = buildArr[i];

    // for (int i = 0; i < n; i++)
    //     cout<< h->arr[i]<<" ";

    h->count = n;

    for (int i = (n - 1) / 2; i >= 0; i--)
        percolateDown(h, i);
}

void insertHeap(Heap *h, int data)
{
    if (h->count == h->capacity)
        resizeHeap(h);
    h->count += 1;

    int i;
    i = h->count-1;
    while (i >= 0 && data > h->arr[(i - 1) / 2])
    {
        h->arr[i] = h->arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    h->arr[i] = data;
}

void destroyHeap(Heap *h)
{
    if (h == NULL)
        return;

    delete (h->arr);
    delete (h);
    h = NULL;
}

void heapSort(int buildArr[], int n)
{
    Heap *h = createHeap(n, 1);
    buildHeap(h, buildArr, n);

    int old_size = h->count;
    int i;
    for (i = n - 1; i >= 0; i--)
    {
        int temp = h->arr[0];
        h->arr[0] = h->arr[h->count - 1];

        cout << temp << " ";
        percolateDown(h, 0);

        h->count--;
    }
    h->count = old_size;
}

// void percolateUp(Heap* h, int pos)
// {
//     int parentPos, max ;
//     parentPos = parentPtr(h,pos);

//     if(h->arr[pos] > h->arr[parentPos] )
//         max = pos;

//     if(max==pos)
//     {
//         int temp;
//         temp = h->arr[parentPos];
//         h->arr[parentPos] = h->arr[max];
//         h->arr[max] = temp;
//     }
//     percolateUp(h,max);
// }

int main()
{
    int arr[10] = {1, 5, 14, 2, 10, 7, 12, 3, 31, 16};
    // heapSort(arr, 10);
    Heap *h = createHeap(11,1);
    buildHeap(h, arr, 10);
    for (int i = 0; i < 10; i++)
        cout << h->arr[i] << " ";
}