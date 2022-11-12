#include<bits/stdc++.h>
using namespace std;
// Using Z-algorithm
vector<int> z_function(string s)
{
    int n=s.size();
    vector<int> z(n,0);
    for(int i=1,l=0,r=0;i<n;i++)
    {
        if(i<=r)
            z[i]=min(r-i+1,z[i-l]);
        while(z[i]+i<n && s[z[i]]==s[z[i]+i])
            ++z[i];
        if(z[i]+i-1>r)
            l=i,r=z[i]+i-1;
    }
    return z;
}

int main()
{
    string s;
    cin>>s;
    vector<int> z=z_function(s);
    int max1=0,max2=0;
    vector<int> pre(z.size()+1,0);
    for(int i=0;i<z.size();i++)
    {
        pre[i+1]=max(pre[i],z[i]);
    }
    int res=0;
    for(int i=z.size()-1;i>=0;i--)
    {
        if(i+z[i]==s.size() && pre[i]>=z[i])
            res=max(res,z[i]);
    }
    if(res)
    cout<< s.substr(0,res);
    else
    cout<<"Just a legend"<<endl;
}
