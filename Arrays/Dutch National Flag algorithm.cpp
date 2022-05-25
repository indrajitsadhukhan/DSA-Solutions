// Sort an array containing 0 1 and 2
#include "bits/stdc++.h"
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
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
void solve()
{
	int n;cin>>n;
	int arr[n];
	for(int &i: arr)
		cin>>i;
	int low=0,mid=0,high=n-1;
	for(int i=0;i<n,mid<=high;i++)
	{
		if(arr[i]==0)
		{
			swap(&arr[low],&arr[i]);
			low++;
			mid++;
		}
		if(arr[i]==1)
		{
			mid++;
		}
		if(arr[i]==2)
		{
			swap(&arr[i],&arr[high]);
			high--;
			i--;
		}
	}
	for(int i: arr) cout<<i<<' ';
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