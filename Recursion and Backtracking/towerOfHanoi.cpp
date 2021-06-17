#include <bits/stdc++.h>

using namespace std;

void TOH(int n, char from, char to, char aux)
{
    if(n==1)
    {
        cout<<"Move the disk 1 from "<<from<<" to "<<to<<endl;
        return ;
    }

    TOH(n-1, from, aux, to);
    cout<<"Move the disk "<<n<<" from "<<from<<" to "<<to<<endl;

    TOH(n-1, aux,to,from); 

}

int main()
{
    TOH(3,'A', 'C', 'B');
}