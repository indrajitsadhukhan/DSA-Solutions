#include<bits/stdc++.h>
using namespace std;
bool ok(vector<int> &locs,int mid,int c)
{
    int i=locs[0],k=0;
    c--;
    while(k<locs.size())
    {
        while(k<locs.size() && locs[k]<i+mid)
        {
            k++;
        }
        
        if(k<locs.size() && locs[k]>=i+mid)
           { 
               c--;
               i=locs[k];
            }
        if(c==0)
        return true;
    }
    return false;
}
int main()
{
    int t; cin>>t;
    while(t--)
    {
        vector<int> locs;
        int n,c;
        cin>>n>>c;
        for(int i=0;i<n;i++)
        {
            int x;cin>>x;
            locs.push_back(x);
        }
        sort(locs.begin(),locs.end());
        int low=1,high=INT_MAX,res=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(ok(locs,mid,c))
               {
                   res=mid;
                    low=mid+1;
                    // cout<<"M"<<mid<<endl;
                }
            else
                high=mid-1;
        }
        cout<<res<<endl;
    }
 
    return 0;
}
 
