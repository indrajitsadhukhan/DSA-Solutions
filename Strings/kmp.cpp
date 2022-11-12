#include<bits/stdc++.h>
using namespace std;
vector<int> prefix_function(string s)
{
    int n=s.size();
    vector<int> pi(n,0);
    for(int i=1;i<n;i++)
    {
        int j=pi[i-1];
        while(j>0 && s[j]!=s[i])
            j=pi[j-1];
        if(s[i]==s[j])
            j++;
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
