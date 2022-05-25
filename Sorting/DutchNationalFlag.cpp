#include<bits/stdc++.h>
using namespace std;
/*
To Sort an array which have 0 1 and 2
*/
void mySort(int arr[],int n)
{
    int low=0,mid=0,high=n-1;
    while(mid<high)
    {
        if(arr[mid]==0)
        {
            swap(arr[low],arr[mid]);
            low++,mid++;
        }
        else if(arr[mid]==1)
        mid++;
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }    
}
int main()
{
    int arr[]={2,0,1,1,0,2},n=6;
    mySort(arr,n);
    for(int i: arr) 
        cout<<i<<' ';
}
