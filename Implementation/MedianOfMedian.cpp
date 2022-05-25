#include<bits/stdc++.h>
using namespace std;
int findMedian(int arr[],int n)
{
    sort(arr,arr+n);
    return arr[n/2];
}
int partition(int arr[],int l,int r,int x)
{
    for(int i=l;i<r;i++)
    {
        // Place x at the last of the array.
        if(arr[i]==x)
        {
            swap(arr[i],arr[r]);
            break;
        }
    }
    int i=l;
    for(int j=l;j<r;j++)
    {
        // 4 1 2 3
        if(arr[j]<=x)
        {
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[r]);
    return i;
}
int kthSmallest(int arr[],int l,int r,int k)
{
    int n = r-l+1;
    if(k>0 && k<=n)
    {
        int median[(n+4)/5];
        int i=0;
        for(i=0;i<n/5;i++)
            median[i]=findMedian(arr+l+i*5,5);
        if(i<n*5)
        {
            median[i]=findMedian(arr+l+i*5,n%5);
            i++;
        }
        int medofmed;
        if(i==1)
            medofmed=median[0];
        else
            medofmed=kthSmallest(median,0,i-1,i/2);
            // i/2 th smallest element is the median.
        int pos = partition(arr,l,r,medofmed);
        if(pos-l==k-1)
            return arr[pos];
        if(pos-l>k-1)
            return kthSmallest(arr,l,pos-1,k);
        return kthSmallest(arr,pos+1,r,k+l-pos-1);
    }
}
int main()
{
    // Find kth Smallest element in O(n) time.
    int arr[]= {1,4,0,-2,10};
    int k =4,n=5;
    cout<<kthSmallest(arr,0,n-1,k);
}
