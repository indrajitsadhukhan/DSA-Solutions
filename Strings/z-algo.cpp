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

        while(z[i]+i<n && s[z[i]]==s[z[i]+i])
            ++z[i];

        if(z[i]+i-1>r)
            l=i,r=z[i]+i-1;
    }
    
    return z;
}

int main()
{
    string s="abcabdabe";
    vector<int> zf=z_function(s);
    for(int i=0;i<zf.size();i++)
        cout<<zf[i]<<' ';
    cout<<endl;
}
