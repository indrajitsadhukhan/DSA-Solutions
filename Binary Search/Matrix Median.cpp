int countSmallerthanMid(vector<int> &A,int x)
{
    int low=0,high=A.size()-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(A[mid]<=x)
            low=mid+1;
        else
            high=mid-1;
    }
    return low;
}
int Solution::findMedian(vector<vector<int> > &A) {
    int low=1,high=1e9,n=A.size(),m=A[0].size();
    while(low<=high)
    {
        int mid=(low+high)/2;
        int cnt=0;
        for(int i=0;i<n;i++)
            cnt+=countSmallerthanMid(A[i],mid);
        if(cnt<=n*m/2)
            low=mid+1;
        else
            high=mid-1;
    }
    return low;
}

