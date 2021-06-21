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
class Node{
		public:
	int data;
	Node *next,*prev;

	Node(int x)
	{
		data = x;
		next = prev = NULL;
	}
	void printList(Node *head)
	{
		while(head->next)
		{
			cout<<head->data;
			head=head->next;
		}
		cout<<head->data;
		cout<<endl;

		while(head!=NULL)
		{
			cout<<head->data<<' ';
			head = head->prev;
		}

	}
	void addNode(Node **head,int data)
	{
		Node *curr = *head;
		while(curr->next!=NULL)
		{
			curr=curr->next;
		}
		Node *temp = new Node(data);
		curr->next = temp;
		curr->next->prev = curr;
	}
	Node* findMiddle(Node **head)
	{
		Node *slow,*fast;
		slow=fast=*head;
		Node *temp=*head;
		while(fast && fast->next)
		{
			fast = fast->next->next;
			temp=slow;
			slow = slow->next;
		}
		temp->next = NULL;
		return slow;

	}
	Node* merge(Node *first,Node *second)
	{
		Node *ans=NULL;
		Node *curr = ans;
		while(first && second)
		{
			if(first->data<second->data)
			{
				if(!ans)
				{
					ans = first;
					curr=ans;
				}
				else
				{
					curr->next = first;
					first->prev = curr;
					curr=curr->next;
				}
				first = first->next;
			}
			else
			{
				if(!ans)
				{
					ans = second;
					curr = ans;
				}
				else
				{
					curr->next = second;
					second->prev = curr;
					curr= curr->next;
				}
				second = second->next;
			}
		}
		while(first)
		{
			curr->next = first;
			first->prev = curr;
			curr = curr->next;
			first=first->next;
		}
		while(second)
		{
			curr->next= second;
			second->prev = curr;
			curr = curr->next;
			second=second->next;
		}
		return ans;
	}
	void mergesort(Node **head)
	{
		Node *curr=*head;
		if(!curr || !curr->next)
		{
			return;
		}
		Node *mid= findMiddle(head);
		mergesort(head);
		mergesort(&mid);
		Node *ans = merge(*head,mid);
		*head = ans;
	}

};

void solve()
{
	// Node *head = new Node(1);
	// head->addNode(&head,2);
	// head->addNode(&head,4);
	// head->addNode(&head,3);
	// cout<<head->findMiddle(head)->data;
	// head->mergesort(&head);
	// head->printList(head);

	Node *first = new Node(1);
	first->addNode(&first,3);
	first->addNode(&first,7);
		Node *second = new Node(2);
	second->addNode(&second,2);
second->addNode(&second,8);
first->printList(first->merge(first,second));
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