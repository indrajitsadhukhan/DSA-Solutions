#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v={9,0,1,2,5,0,-20,19,-30};

    for(int i=1;i<v.size();i++)
    {
        int key=v[i];
        int j=i-1;
        while(j>=0 && v[j]>key)
        {  
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=key;        
    }

    for(int i: v)
        cout<<i<<" ";
}
