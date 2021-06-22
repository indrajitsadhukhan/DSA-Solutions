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

int binsearch(int arr[],int l,int r,int x)
{
	if(l>r)
	{
		return -1;
	}
	int mid = (l+r)/2;
	if(arr[mid]==x)
	{
		return mid;
	}
	if(arr[mid]>x)
	{
		return binsearch(arr,l,mid-1,x);
	}
	else{
		return binsearch(arr,mid+1,r,x);
	}
}

void solve()
{
	int n;
	cin>>n;
	int arr[n];
	for(int &i: arr)
	{
		cin>>i;
	}
	int l=0,r=n-1;
	int x;
	cin>>x;
	while(l<r)
	{
		int mid = (l+r)/2;
		if(arr[mid]>=x)
		{
			r=mid;	
		}
		else{
			l=mid+1;
		}
	}
	if(arr[l]==x)
	{
		cout<<"Found at index: "<<l<<endl;
	}
	else{
		cout<<"Not found"<<endl;
	}
	int z = binsearch(arr,0,n-1,x);
	if(z==-1)
	{
		cout<<"Not found"<<endl;
	}
	else{
		cout<<"Found at index "<<z<<endl;
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