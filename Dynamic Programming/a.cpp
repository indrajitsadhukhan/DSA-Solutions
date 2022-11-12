#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={1,1,2,3};
    int n=4,diff=1;
    int sum=0;
    for(int i: arr) 
    sum+=i; 

    cout<<sum<<endl;
    int dp[n+1][sum+1];
    for(int i=0;i<=sum;i++)
        dp[0][i]=0;
    for(int i=0;i<=n;i++)
        dp[i][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j>=arr[i-1])
                dp[i][j]=dp[i-1][j-arr[i-1]] + dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    int cnt=0;
    for(int i=0;i<=sum ;i++)
    {
        cout<<dp[n][i]<<" ";
        if(dp[n][i]>0 && 2*i-sum==diff)
            cnt+=dp[n][i];
    }
    cout<< cnt<<endl;;
}
