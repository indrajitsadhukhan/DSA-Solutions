#include<bits/stdc++.h>
using namespace std;
long long int p_pow[(int)1e5];
long long int pre_hash[(int)1e5];
long long int inv_ppow[(int)1e5];
long long int M=1e9+9;
void hash_function(string s)
{
    long long int hash=0;
    pre_hash[0]=0;
    for(int i=0;i<s.size();i++)
    {
        hash+=((s[i]-'a'+1)*p_pow[i])%M;
        pre_hash[i+1]=hash;
    }
}
long long int bin_exp(long long int a,long long int b)
{
    if(b==0)
    return 1;
    if(b&1)
    return (a*bin_exp(a,b-1))%M;
    long long int x=bin_exp(a,b/2);
    return (x*x)%M;
}
long long int sub_hash(string s,int i,int j)
{
    return ((pre_hash[j+1]-pre_hash[i])*inv_ppow[i])%M;
}
int main()
{
    string s="aniwffnabcdanwinf";
    string ss="abcd";
    long long int p=31;
    p_pow[0]=1;
    inv_ppow[0]=1;
    for(int i=1;i<1e5;i++)
    {
        p_pow[i]=(p_pow[i-1]*p)%M;
    }
    long long int invp=bin_exp(p,M-2)%M;
    inv_ppow[1]=invp;
    for(int i=2;i<1e5;i++)
    {
        inv_ppow[i]=(inv_ppow[i-1]*invp)%M;
    }
    
    hash_function(s);
    cout<<sub_hash(s,7,10)<<endl;

    hash_function(ss);
    cout<<sub_hash(ss,0,3)<<endl;
}
