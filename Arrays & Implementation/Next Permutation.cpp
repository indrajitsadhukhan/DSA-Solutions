class Solution {
    
public:
    void nextPermutation(vector<int>& nums) {
       int pos1=-1,pos2=-1,n=nums.size();
        for(int i=n-1;i>0;i--)
        {
            if(nums[i-1]<nums[i])
                {
                pos1=i-1;
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(pos1>=0 && nums[i]>nums[pos1])
            {
                pos2=i;
                break;
            }
        }
        if(pos2==-1)
        {
            reverse(nums.begin(),nums.end());
        }
        else{
            swap(nums[pos1],nums[pos2]);
            reverse(nums.begin()+pos1+1,nums.end());
        }
    }
};
