#include<bits/stdc++.h>
using namespace std;
void rotate(int arr[],int n)
{
    int i=0,j=n-1;
    while(i!=j)
    {
        swap(arr[i],arr[j]);
        i++;
    }
}
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

void leftRotate(int arr[],int n,int d)
{
    d=d%n;
    // Handle If d>n 
    int gcd1=gcd(n,d);
    for(int i=0;i<gcd1;i++)
    {
        int temp=arr[i],j=i;
        while(1)
        {
            int k=j+d;
            if(k>=n) k-=n;
            if(k==i)
                break;
            arr[j]=arr[k];
            j=k;   
        }
        arr[j]=temp;
    }
}
void rightRotate(int arr[],int n,int d)
{
    leftRotate(arr,n,n-d);
}
int main(){
    int arr[]={1,2,3,4},n=4,k=3;
    leftRotate(arr,n,k);
    for(int i: arr) 
        cout<<i<<' ';
}
