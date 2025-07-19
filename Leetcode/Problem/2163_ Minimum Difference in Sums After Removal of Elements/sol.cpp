class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
       priority_queue<long long> mi;
       priority_queue<long long, vector<long long>, greater<long long>> ma;

        //mi
       long long sum=0;
       for(int i=0; i< nums.size()/3; i++)
       {
            sum+=nums[i];
            mi.push(nums[i]);
       } 
       vector<long long> a1,a2;
       a1.push_back(sum);
       for(int i=nums.size()/3;i<nums.size()/3*2 ;i++)
       {
        if(mi.top()>nums[i])
        {
            sum-=mi.top();
            sum+=nums[i];
            mi.pop();
            mi.push(nums[i]);
        }
        a1.push_back(sum);
       }
       //ma
       sum=0;
       for(int i=nums.size()-1;i>=nums.size()/3*2; i--)
       {
        sum+=nums[i];
        ma.push(nums[i]);
       }
       a2.push_back(sum);
       for(int i=nums.size()/3*2-1;i>=nums.size()/3; i--)
       {
            if(ma.top()<nums[i])
            {
                sum-=ma.top();
                sum+=nums[i];
                ma.pop();
                ma.push(nums[i]);
            }
            a2.push_back(sum);
       }
       reverse(a2.begin(),a2.end());
        // for(int i=0; i< a1.size(); i++)
        // {
        //     cout<<a1[i]<<' ';
        // }
        // cout<<endl;
        // for(int i=0; i<a2.size(); i++)
        // {
        //     cout<<a2[i]<<' ';
        // }
        long long ans=LLONG_MAX;
        for(int i=0; i<a1.size(); i++)
        {
            ans=min(ans,a1[i]-a2[i]);
        }
        return ans;
        
    }
};