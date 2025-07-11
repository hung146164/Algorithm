// Use two unordered_map
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        unordered_map<int,int> d1,d2;
        int ans=0;
        int close=INT_MAX;
        for(int i=0; i< nums.size(); i++)
        {
            for(auto j: d1)
            {
                int diff=abs(nums[i]+j.first-target);
                if(diff<close)
                {
                    close=diff;
                    ans=nums[i]+j.first;
                }
            }
            for(int j=i-1;j>=0; j--)
            {
                d1[nums[i]+nums[j]]++;
            }
            
        }
        return ans;

    }
};