class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int ans=nums.size();
        int n=nums.size();
        for(int l=0,r=1; r<n; r++)
        {
            if(nums[l]<=nums[r])
            {
                ans-=r-l-1;
                l=r;
            }
            else if(r==n-1)
            {
               ans-=r-l;
            }
        }
       // 4 2 3 5 3 4 5 2 1 3 5
         return ans;
    }
};
