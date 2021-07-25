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
int solve()
{
	int n;
	cin >> n;
	int a[n];
	map<int, pair<int, int>> mp;
	for (int i = 0; i < 10; i++)
	{
		mp[i].second = -1;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		int x = mp[a[i]].second;
		if (x == -1)
			x = i;
		pair<int, int> pp = make_pair(mp[a[i]].first + 1, x);
		mp[a[i]] = pp;
	}

	int rep = -1, norep = -1;
	for (int i = 0; i < n; i++)
	{
		if (mp[a[i]].first >= 2)
		{
			rep = mp[a[i]].second;
		}
		if (mp[a[i]].first == 1 and norep == -1)
		{
			norep = mp[a[i]].second;
			dg(mp[a[i]].first);
		}
	}
	dg(rep);
	dg(norep);
	if (rep == -1 and is_sorted(a, a + n))
	{
		return a[0];
	}
	if (rep == -1)
	{
		return a[0] * 10 + 9;
	}
	if (rep == 0)
	{
		if (norep == -1)
		{
			cout<<"PP";
			return a[rep] * 10;
		}
		else
		{
			int z = abs(a[norep] - (norep - rep));
			if (norep > a[norep])
			{
				return a[rep] * 10 + (10 - z);
			}
			return a[rep] * 10 + z;
		}
	}
	if (a[rep] > a[norep])
	{
		return a[rep] * 10 + a[norep];
	}
	else
	{
		if (a[rep] >= 1)
			{
				if(norep==-1)
				{
					return a[rep-1]*10+(10-rep);
				}
				return (a[rep] - 1) * 10 + a[norep];
			}
		else
			return 90 + (10 - rep);
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
		cout << solve() << endl;
	}
	return 0;
}

/*
7
1 2 5 5 5 6 7
7 
9 1 1 1 1 1 1
5
9 9 9 0 0

5
8 8 8 9 9

5
5 2 5 4 5


*/
