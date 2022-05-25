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
#define MAX 1000
//Stack using Queue
template<typename T>
class Stack {
	queue<T> q1;
	queue<T> q2;
	int csize;
	public:
	Stack()
	{
		csize=0;
	}
	void push(T x)
	{
		csize++;
		q2.push(x);
		while(!q1.empty())
		{
			q2.push(q1.front());
			q1.pop();
		}
		queue<T> q = q1;
		q1=q2;
		q2=q;
	}
	void pop()
	{
		if(q1.empty())
		return;
		csize--;
		q1.pop();
	}
	T peek()
	{
		if(q1.size()>0)
		return q1.front();
		else
		return -1;
	}
	T size()
	{
		return csize;
	}
};

//Queue using stack
template<typename T>
class Queue{
	int csize;
	stack<T> s1,s2;
	public:
	Queue()
	{
		csize=0;
	}
	void enqueue(T x)
	{
		csize++;
		while(!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
		s1.push(x);
		while(!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
	}
	int dequeue()
	{
		if(csize<=0)
		{
			cout<<"Queue is empty"<<endl;
			return -1;
		}
		csize--;
		int temp= s1.top();
		s1.pop();
		return temp;
	}

};


void solve()
{
	Stack<int> s;
	s.push(1);
	s.push(2);
	s.pop();
	cout<<s.peek();
	s.pop();
	s.pop();
	cout<<s.peek();

	Queue<int> q;
	q.enqueue(1);
	q.enqueue(3);
	q.enqueue(10);
	cout<<q.dequeue();
	cout<<q.dequeue();
	cout<<q.dequeue();
	cout<<q.dequeue();
	cout<<q.dequeue();
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