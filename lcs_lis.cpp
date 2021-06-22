#include <bits/stdc++.h>
// #include<iostream>
#define int long long
#define dg(x) cout << #x << "=" << x << endl;
using namespace std;
const int M = 501;
const int N = 1e7 + 10;
const int mod = 1e9 + 7;
int INF = (int)1e10;
int dp[N];
const float eps = 1e-7;
int A[1000000];
int B[1000000];
int lis(int arr[],int n){
	int lis[n];
	lis[0]=1;
	for(int i=1;i<n;i++)
	{
		lis[i]=1;
		for(int j=0;j<i;j++)
		{
			if(arr[i]>arr[j] && lis[i]<lis[j]+1)
			{
				lis[i] = lis[j]+1;
			}
		}
	}
	int mx = 0;
	for(int i=0;i<n;i++)
	{
		mx = max(mx,lis[i]);
	}
	return mx;
}
int lcs(string a,string b,int m,int n)
{
	if(m==0 || n==0)
	{
		return 0;
	}
	if(a[m-1]==b[n-1])
	{
		return 1+lcs(a,b,m-1,n-1);
	}
	return max(lcs(a,b,m-1,n),lcs(a,b,m,n-1));
}
void solve()
{
	int n;
	cin>>n;
	int a[n];
	for(int &i : a) cin>>i;
	cout<<lis(a,n)<<endl;

	string sa="Hello";
	string sb = "jHkeremefklwmo";
	cout<<lcs(sa,sb,sa.size(),sb.size())<<endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tt = 1;
	// cin >> tt;
	for (int i = 1; i <= tt; i++)
	{
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}