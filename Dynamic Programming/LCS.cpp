#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a="bcdeg";
    string b="kdep";
    int n=a.size(),m=b.size();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
        dp[i][0]=0;
    for(int i=0;i<=m;i++)
        dp[0][i]=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i-1]==b[j-1])
            { 
                dp[i][j]=dp[i-1][j-1]+1;
                ans=max(ans,dp[i][j]);
            }
            else
                dp[i][j]=0;
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        cout<<dp[i][j]<<' ';
        cout<<endl;
    }
    cout<<ans<<endl;
}
