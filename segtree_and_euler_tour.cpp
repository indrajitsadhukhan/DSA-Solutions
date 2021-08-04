#include <bits/stdc++.h>
#define int long long
#define dg(x) cout << #x << "=" << x << endl;
using namespace std;
const int M = 501;
const int N = 1e7 + 10;
const int mod = 1e9 + 7;
int INF = (int)1e10;
int dp[N];
const float eps = 1e-7;
vector<int> G[N];
int val[N], arr[2 * N], start[N],ens[N];
int tree[8 * N];
int cnt = 0;
void dfs(int root,int par=-1)
{
	start[root]=cnt;
	arr[cnt++] = root;
	for (auto x : G[root])
	{
		if (x != par)
			dfs(x,root);
	}
	ens[root]=cnt;
	arr[cnt++] = root;
}
void build(int node, int start, int end)
{
	if (start == end)
	{	
		tree[node] = val[arr[start]-1];
		return;
	}
	int mid = (start + end) / 2;
	build(2 * node, start, mid);
	build(2 * node + 1, mid + 1, end);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}
int query(int node, int start, int end, int l, int r)
{	
	if (l > end || start > r)
	{
		return 0;
	}
	if (l <= start and end<= r)
	{
		return tree[node];
	}
	int mid = (start + end) / 2;
	return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
}
void update(int node,int  start,int end,int idx,int value)
{
	// cout<<idx<<' ';
	if(start == end)
	{
		val[idx]=value;
		tree[node]=value;
		return;
	}
	int mid = (start+end)/2;
	if(idx<=mid)
	update(2*node,start,mid,idx,value);
	else
	update(2*node+1,mid+1,end,idx,value);
	tree[node] = tree[2*node]+ tree[2*node+1];
}
void solve()
{
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> val[i];
	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1);
	build(1,0,2*n);
	
	while(q--)
	{
		int type; 
		cin>>type;
		if(type==2)
		{
			int x; cin>>x;
			cout<<query(1,0,2*n,start[x],ens[x])/2<<endl;
		}
		else
		{
			int x,v;
			cin>>x>>v;
			update(1,0,2*n,start[x],v);
			update(1,0,2*n,ens[x],v);
		}
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
