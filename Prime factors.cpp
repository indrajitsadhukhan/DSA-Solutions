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
map<int,int> primefactors(int n)
{
	map<int,int> mp;
	if(n==1)
	{
		mp[1]=1;
		return mp;
	}
	for(int i=2;i*i<=n;i++)
	{
		while(n%i==0)
		{
			mp[i]++;
			n/=i;
		}
	}
	if(n>2)
	mp[n]++;
	return mp;
}
void solve()
{
	map<int,int> mp;
mp = primefactors(729);
for(auto i: mp)
{
	cout<<i.first<<' '<<i.second<<endl;
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