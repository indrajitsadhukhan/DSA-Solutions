#include<bits/stdc++.h>
using namespace std;
vector<int> z_function(string s)
{
    int n=s.size();
    vector<int> z(n,0);
    for(int i=1,l=0,r=0;i<n;i++)
    {
        if(i<=r)
        z[i]=min(r-i+1,z[i-l]);
        while(z[i]+i<n && s[z[i]+i]==s[z[i]])
            ++z[i];
        if(z[i]+i-1>r)
        l=i,r=z[i]+i-1;
    }
    return z;
}
int main()
{
    string s="abx$aifneabxajof";
    string p="abx";
    vector<int> res=z_function(s);
    for(int i=0;i<res.size();i++)
    {
       cout<<res[i]<<' ';
    }
}
