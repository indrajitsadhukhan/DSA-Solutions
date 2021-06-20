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
void solve()
{
	int n;
	cin>>n;
	int mat[n][n];   
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>mat[i][j];
		}
	}
	int dir=0,top=0,down=n-1,left=0,right=n-1;
	while(top<=down && left<=right)
	{
		
		if(dir==0)
		{
			for(int i=left;i<=right;i++)
			{
				cout<<mat[top][i]<<' ';
			}
			top++;
		}
		else if(dir==1)
		{
			for(int i=top;i<=down;i++)
			{
				cout<<mat[i][right]<<' ';
				
			}
			right--;
		}
		else if(dir==2)
		{
			for(int i=right;i>=left;i--)
			{
				cout<<mat[down][i]<<' ';
			}
			down--;
		}
		else if(dir==3)
		{
		for(int i=down;i>=top;i--)
		{
			cout<<mat[i][left]<<' ';
		}
		left++;
		}
		dir=(dir+1)%4;
	}
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