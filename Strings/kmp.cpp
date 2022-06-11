#include<bits/stdc++.h>
using namespace std;
vector<int> prefix_function(string s)
{
    int n=s.size();
    vector<int> pi(n,0);
    for(int i=1;i<n;i++)
    {
        int j=pi[i-1];
        if(i==5)
            cout<<"J1="<<j<<endl;
        while(j>0 && s[j]!=s[i])
            j=pi[j-1];
        if(i==5)
            cout<<"J2="<<j<<endl;
        if(s[i]==s[j])
            j++;
        if(i==5)
            cout<<"J3="<<j<<endl;
        pi[i]=j;
    }
    return pi;
}
int main()
{
    string text="ab$cabdba";
    string pattern="ab";
    // $ is a character out of domain. 
    vector<int> res=prefix_function(text);
    for(int i=0;i<res.size();i++)
    {
        if(res[i]==pattern.size())
            cout<<(i-2*pattern.size())<<endl;
    }
    return 0;
}
