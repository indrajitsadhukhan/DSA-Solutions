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
class Tree{
	public:
	int data;
	Tree *left,*right;
	Tree(int x)
	{
		data=x;
		left=NULL;
		right=NULL;
	}
};

bool hasPath(Tree *root, vector<int> &arr,int x)
{
	if(root==NULL)
	return false;
	arr.push_back(root->data);
	if(root->data == x)
	return true;
	
	if(hasPath(root->left,arr,x)|| hasPath(root->right,arr,x))
	{
		return true;
	}
	arr.pop_back();
	return false;
}
Tree* LCA(Tree *root,int p,int q)
{
	if(root==NULL)
	return NULL;
	if(root->data == p || root->data== q)
	return root;
	Tree* left = LCA(root->left,p,q);
	Tree* right = LCA(root->right,p,q);
	if(left && right)
	{
		return root;
	}
	else if(left)
	{
		return left;
	}
	return right;
}
int height(Tree *node)
{
	if(node == NULL)
	return 0;
	int left = height(node->left);
	int right = height(node->right);
	return max(left,right)+1;
}
//Time complexity = N2
int diameter(Tree *root)
{
	if(root==NULL)
	return 0;
	int left = diameter(root->left);
	int right = diameter(root->right);
	int temp = height(root->left)+height(root->right);
	return max({left,right,temp});
}
//Time complexity = N
pair<int,int> diameter_optimized(Tree *root)
{
	pair<int,int> ans;
	if(root==NULL)
	{ 
		ans = {-1,0};
		return ans;
	}
	pair<int,int> left = diameter_optimized(root->left);
	pair<int,int> right = diameter_optimized(root->right);
	ans.first = max(left.first,right.first)+1;
	ans.second = max({left.second,right.second,left.first+right.first+2});
		return ans;
}
bool isBalanced(Tree *root)
{
	if(root==NULL)
	return true;
	int left = isBalanced(root->left);
	int right = isBalanced(root->right);
	int lh = height(root->left);
	int rh = height(root->right);
	if(left && right && abs(lh-rh)<=1)
	{
		return true;

	}
	return false;
}
void printCurrentLevel(Tree *root,int level)
{
	if(root==NULL)
	return;
	if(level==1)
	{
		cout<<root->data<<' ';
	}
	else if(level>1)
	{
		printCurrentLevel(root->left,level-1);
		printCurrentLevel(root->right,level-1);
	}
}
void printLevelOrder(Tree *root)
{
	int h=height(root);
	for(int i=1;i<=h;i++)
	{
		printCurrentLevel(root,i);
	}
}
void solve()
{
	Tree *tree = new Tree(3);
	tree->left=new Tree(5);
	tree->right=new Tree(1);
	tree->left->left=new Tree(6);
	tree->left->right=new Tree(2);
	tree->right->left=new Tree(0);
	tree->right->right=new Tree(8);
	// vector<int> arr;
	// cout<<hasPath(tree->left,arr,2)<<endl;
	// for(int i: arr)
	// {
	// 	cout<<i<<' ';
	// }
	// Tree* ans=LCA(tree,2,6);
	// if(ans==NULL)
	// {
	// 	cout<<"NO LCA EXISTS"<<endl;
	// }
	// else
	// cout<<ans->data;
	// cout<<diameter_optimized(tree).second<<endl;
	// cout<<isBalanced(tree)<<endl;
	printLevelOrder(tree);
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