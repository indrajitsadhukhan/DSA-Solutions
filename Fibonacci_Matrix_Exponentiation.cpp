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
void mul(int a[][2],int b[][2])
{
	int c[2][2];
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			c[i][j]=0;	
			for(int k=0;k<2;k++)
			{
				c[i][j] +=(a[i][k]*b[k][j]);  
			}
		}
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			a[i][j] = c[i][j];
		}
	}
}

void mex(int mat[][2],int n)
{
	int M[2][2] = {{1,1},{1,0}};
	if(n==1)
	{
		return;
	}
	mex(mat,n/2);
	mul(mat,mat);
	if(n&1)
	{
		mul(mat,M);
	}
}

void solve()
{
	int n;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	int mat[2][2] = {{1,1},{1,0}};
	mex(mat,n-1);
	cout<<mat[0][0];
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