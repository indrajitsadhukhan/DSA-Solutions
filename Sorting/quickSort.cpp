#include<bits/stdc++.h>
using namespace std;
int partition(int arr[],int l,int r)
{
    int x = arr[r];
    int i=l;
    for(int j=l;j<r;j++)
    {
        if(arr[j]<=x)
        {
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[r]);
    return i;
}
void quickSort(int arr[],int l,int r)
{
    if(l>r)
    return;
    int pivot = partition(arr,l,r);
    quickSort(arr,l,pivot-1);
    quickSort(arr,pivot+1,r);
}
int main()
{
    int arr[]={1,1,0,-3,5},n=5;
    quickSort(arr,0,n-1);
    for(int i: arr) 
        cout<<i<<' ';
}
