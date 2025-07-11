class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=0; int r= nums.size()-1;vector<int> k=nums;
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int a,b;
        
        while(l<r)
        {
            int s=nums[l]+nums[r];
            if(s<target)
            {
                l++;
            }
            else if(s==target)
            {
                a=nums[l];
                b=nums[r];
                break;
            }
            else
            {
                r--;
            }
        }
        for(int i=0; i< nums.size();i++)
        {
            if(k[i]==a)
            {
                ans.push_back(i);
                a=1e9+1;
            }
            else if(k[i]==b)
            {
                ans.push_back(i);
                b=1e9+1;
            }
        }
        return ans;
    }
};