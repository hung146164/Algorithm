//Use Two pointer + binary search
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int kc=INT_MAX;
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0; i< nums.size()-2; i++)
        {
            for(int j=i+2;j<nums.size(); j++)
            {
                int s=nums[i]+nums[j];
                int fi=target-s;
                auto it=upper_bound(nums.begin()+i+1,nums.end()-(nums.size()-j+1),fi);
                int  have;
                if(abs(*it-fi)<=abs(*prev(it)-fi) || prev(it)==nums.begin()+i)
                {
                    have=*it;
                }
                else
                {
                    have=*prev(it);
                }
                
                // cout<<*it<<endl;
                // cout<<*prev(it)<<endl;
                if(kc>abs(have-fi))
                {
                    kc=abs(have-fi);
                    ans=s+have;
                }
            }
        }
        return ans;
    }
};