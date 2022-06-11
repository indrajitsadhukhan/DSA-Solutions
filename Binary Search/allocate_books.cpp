bool possible(vector<int> &A,int mid,int b)
{
    int curr_books=0,i=0;
    while(i<A.size())
    {
        while(i<A.size() && curr_books+A[i]<mid)
        {
            curr_books+=A[i];
            i++;
        }
        if(i<A.size() && curr_books+A[i]>=mid)
        {
            curr_books=0;
            b--;
            if(b==0)
                return true;
        }
    }
    return false;
}
int Solution::books(vector<int> &A, int B) {
    if(A.size()<B)
    return -1;
 int low=0,high=INT_MAX,res=-1;
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(possible(A,mid,B))
               {

                   res=mid;
                    low=mid+1;
            }
            else
                high=mid;
        }
        return res;
}
