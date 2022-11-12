#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v={9,0,1,2,5,0,-20,19,-30};
    int k=0,n=v.size();
    for(int i=0;i<n-1;i++)
    {
        int max_num=INT_MIN,max_idx=0,swap_idx=0;
        for(int j=0;j<n-k;j++)
        {
            if(v[j]>max_num)
            {
                max_num=v[j];
                max_idx=j;
            }
        }
        swap(v[max_idx],v[n-k-1]);
        k++;
    }
    for(int i: v)
        cout<<i<<" ";
}
