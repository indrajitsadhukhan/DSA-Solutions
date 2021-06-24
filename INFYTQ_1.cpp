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
set<int> pre;
int ans[N];
void permutations(string s,int i,int n)
{
	if(i==n-1)
	{
		pre.insert(stoi(s));
		return;
	}
for(int j=i;j<n;j++)
{
	swap(s[i],s[j]);
	permutations(s,i+1,n);
	swap(s[i],s[j]);
}
}
void precompute()
{
		string s;
	s="369";
	permutations(s,0,s.size());
	vector<int> v;
	for(int i=0;i<=9;i++)
	{
		if(i!=3 && i!=6 && i!=9)
		v.push_back(i);
	}
	string temp=s;
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v.size();j++)
		{
			s+=to_string(v[i]);
			s+=to_string(v[j]);
			permutations(s,0,s.size());
			s=temp;
		}
	}
	memset(ans,0,sizeof(ans));
	for(int i: pre)
	{
		ans[i]++;
	}
	for(int i=1;i<N;i++)
	{
		ans[i]+=ans[i-1];
	}

}
void solve()
{
	precompute();
	int t; 
	cin>>t;
	while(t--)
	{
	int l,r;
	cin>>l>>r;
	cout<<ans[r]-ans[l-1]<<endl;
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