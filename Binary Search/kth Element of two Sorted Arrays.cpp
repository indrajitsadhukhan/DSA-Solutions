// https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n1,n2,k=1;
    cin>>n1>>n2;
    vector<int> nums1(n1,0),nums2(n2,0);
    for(int i=0;i<n1;i++)
        cin>>nums1[i];
    for(int i=0;i<n2;i++)
        cin>>nums2[i];
    int low=0,high=n1;
    while(low<=high)
    {
        int cut1=(low+high)>>1;
        int cut2=0;
        if(cut1<=k)
        {
            cut2=k-cut1;
            if(cut2>n2)
            {
                low=cut1+1;
                continue;
            }
        }
        else
        {
            high=cut1-1;
            continue;
        }
        int left1=(cut1==0)?INT_MIN:nums1[cut1-1];
        int right1=(cut1==n1)?INT_MAX:nums1[cut1];
        int left2=(cut2==0)?INT_MIN:nums2[cut2-1];
        int right2=(cut2==n2)?INT_MAX:nums2[cut2];

        if(left1<=right2 && left2<=right1)
        {
            cout<< max(left1,left2)<<endl;
            return 0;
        }
        else if(left1>right2)
            high=cut1-1;
        else
            low=cut1+1;
    }
    return 0;
}
