#include<bits/stdc++.h>

using namespace std;

void generatePermutations(int left, int right, string str)
{
    if(left>right)
        {
            cout<<str<<endl;
            return ;
        }
    for(int i = left; i<=right; i++)
    {
        swap(str[left], str[i]);
        generatePermutations(left+1, right, str);
        swap(str[left], str[i]);
    }

}

int main()
{
    string str = "abc";
    int left = 0, right = str.size()-1;
    generatePermutations(left, right, str);
}