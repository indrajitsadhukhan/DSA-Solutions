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
//Find kth smallest element
int findkthsmallest(int arr[],int n,int k)
{
	
	priority_queue<int> pq;
	for(int i=0;i<n;i++)
	{
		pq.push(arr[i]);
		if(pq.size()>k)
		{
			pq.pop();
		}
	}
	return pq.top();
}

//Find kth largest element
int findkthlargest(int arr[],int n,int k)
{
	
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i=0;i<n;i++)
	{
		pq.push(arr[i]);
		if(pq.size()>k)
		{
			pq.pop();
		}
	}
	return pq.top();
}
//Sort a k-sorted array
void sortksorted(int arr[],int n,int k)
{
	int j=0;	
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i=0;i<n;i++)
	{
		pq.push(arr[i]);
		if(pq.size()>k)
		{
			arr[j++]=pq.top();
			pq.pop();
		}
	}
	while(!pq.empty())
	{
		arr[j++]=pq.top();
		pq.pop();
	}
}

void solve()
{
	int n;
	cin>>n;
	int arr[n];
	for(int &i:arr) cin>>i;
	int k;
	cin>>k;
	cout<<findkthlargest(arr,n,k)<<endl;	
	cout<<findkthsmallest(arr,n,k)<<endl;
	int a[]={6,5,3,2,8,10,9};
	n=7;
	k=3;
	sortksorted(a,n,k);
	for(int i: a) 
	cout<<i<<' ';
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