/* Time complexity:

    Average successful search = 1/lambda * ln(1/1-lambda)
    Average unsuccessful search = 1/1-lambda

    where, lambda is the loading factor(no of elements / size of the hash table)

    Ques: What if I want to delete an element
    Ans: Deletion is not simple in linear probing, the only solution to deletion is rehashing of all the keys.
    
*/

/* Assuming all the keys are positive and greater than 0 */

/*This code can be used as a template for quadratic probing.*/

#include<bits/stdc++.h>

#define SIZE 10

using namespace std;

int hashing(int key)
{
    return key%SIZE;
}

int probe(int H[], int key)
{
    int index=  hashing(key);

    int i = 0;

    while(H[(index+ i*i)%SIZE] != -1)
        i++;

    return (index + i)%SIZE;
}

void insert(int H[],int key)
{
    int index = hashing(key);

    if(H[index]!= -1)
        index = probe(H,key);

    H[index] = key;        
}

// int search(int H[], int key)
// {
//     int index = hashing(key);

//     while(H[index % SIZE]!=key && H[index % SIZE]!=-1 )
//         index++;

//     return index %SIZE;    
// }

int main()
{
    int answer[SIZE] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    
    insert(answer,12);
    insert(answer,35);
    insert(answer,45);
    insert(answer,26);
    insert(answer,16);
    insert(answer,6);
    insert(answer,56);
    insert(answer,76);

    // int temp = search(answer,76);
    // cout<<temp;
    return 0;

}