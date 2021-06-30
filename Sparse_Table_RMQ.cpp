#include <bits/stdc++.h>
// #include<iostream>
#define int long long
#define dg(x) cout << #x << "=" << x << endl;
using namespace std;
const int M = 501;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
int INF = (int)1e10;
int dp[N][2];
const float eps = 1e-7;
int lookup[N][50];

void pre(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		lookup[i][0]=i;
	}
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;(i+(1<<j)-1)<n;i++)
		{
			if(arr[lookup[i][j-1]]<=arr[lookup[i+(1<<(j-1))][j-1]])
			{
				lookup[i][j]=lookup[i][j-1];
			}
			else{
				lookup[i][j]=lookup[i+(1<<(j-1))][j-1];
			}
		}
	}
}
int rmq(int arr[],int l,int r)
{
	int x = (int)log2(r-l+1);
	if(arr[lookup[l][x]]<=arr[lookup[r-(1<<x)+1][x]])
	{
		return arr[lookup[l][x]];
	}
	else{
		return arr[lookup[r-(1<<x)+1][x]];
	}
}
void solve()
{
	int n;
	cin>>n;
	int a[n];
	for(int &i : a)
	{
		cin>>i;
	}
	pre(a,n);
	cout<<rmq(a,1,3)<<endl;
	cout<<rmq(a,2,4)<<endl;
	cout<<rmq(a,3,5)<<endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tt = 1;
	cin >> tt;
	for (int i = 1; i <= tt; i++)
	{
		// cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}