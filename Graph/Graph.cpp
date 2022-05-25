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
vector<int> G[100];
vector<pair<int,int>> Gw[100];
int visited[100];
int dis[100];
bool dfs(int x)
{
	visited[x]=1;
	// cout<<x<<' ';
	for(int i: G[x])
	{
		if(i!=x && visited[i]==1)
		{
			return true;
		}
		if(!visited[i])
		{
			if(dfs(i))
			return true;
		}
	}
	return false;
}
void bfs(int x)
{
	queue<int> q;
	q.push(x);
	while(!q.empty())
	{
		int x = q.front();
		cout<<x<<' ';
		q.pop();
		
		for(int i: G[x])
		{
			if(!visited[i])
			{
				visited[i]=1;
				q.push(i);
			}
		}
	}
}
void dijkstra(int x)
{
	memset(dis,INF,sizeof(dis));
	set<pair<int,int>> s;
	s.insert({0,x});
	while(!s.empty())
	{
		int curr = s.begin()->second;
		int d = s.begin()->first;
		s.erase(*(s.begin()));
		if(visited[curr])
		continue;
		dis[curr]=d;
		visited[curr]=1;
		for(auto i: Gw[curr])
		{
			if(visited[i.first])
			continue;
			s.insert({d+i.second,i.first});
		}
	}
}

bool bipartite(int x)
{
	int n = 5;
	int color[n];
	memset(color,-1,sizeof(color));
	queue<pair<int,int>> q;
	//{vertex,color}
	q.push({x,0});
	color[x]=0;
	while(!q.empty())
	{
		auto x = q.front();
		q.pop();
		for(int i: G[x.first])
		{
		if(color[i]==color[x.first])
		{
					return false;
		}
			if(!visited[i])
			{
					visited[i]=1;
				q.push({i,(1-color[x.first])});
			}
		}
	}
	return true;
}
void solve()
{ 
	memset(visited,0,sizeof(visited));
	G[1].push_back(2);
	G[1].push_back(3);
	G[2].push_back(3);
	G[2].push_back(4);
	G[3].push_back(5);
	G[5].push_back(4);

//{vertices,weight}

	Gw[1].push_back({2,4});
	Gw[1].push_back({3,1});
	Gw[2].push_back({3,3});
	Gw[2].push_back({4,1});
	Gw[3].push_back({5,2});
	Gw[5].push_back({4,1});
	// for(int i=1;i<=5;i++)
	// {
	// 	if(!visited[i] && dfs(i))
	// 	{
	// 		cout<<"Graph has a cycle"<<endl;
	// 	}
	// }
	// for(int i=1;i<=5;i++)
	// {
	// 	if(!visited[i])
	// 	bfs(i);
	// }
	// for(int i=1;i<=5;i++)
	// {
	// 	if(!visited[i])
	// 	dijkstra(i);
	// }
	// for(int i=1;i<=5;i++)
	// {
	// 	cout<<dis[i]<<endl;
	// }
	for(int i=1;i<=3;i++)
	{
		if(!visited[i])
		{
			if(bipartite(i))
			{
				cout<<"GRAPH IS BIPARTITE"<<endl;
				break;
			}
			else{
				cout<<"GRAPH IS NOT BIPARTITE"<<endl;
				break;
			}
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