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

void permutations(string s,int i,int n)
{
	if(i==n-1)
	{
		cout<<s<<endl;
		return;
	}
for(int j=i;j<n;j++)
{
	swap(s[i],s[j]);
	permutations(s,i+1,n);
	swap(s[i],s[j]);
}
}
void solve()
{
	string s;
	s="369";
	permutations(s,0,s.size());
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