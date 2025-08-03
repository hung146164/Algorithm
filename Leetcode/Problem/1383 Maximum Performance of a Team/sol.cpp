class Solution {
public:
    const int mod=1e9+7;
    static bool cmp(pair<int,int>& a, pair<int,int>& b)
    {
        if(a.second==b.second)
        {
            return a.first>b.first;
        }
        return a.second>b.second;
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> nums;
        for(int i=0; i< speed.size(); i++)
        {
            nums.push_back({speed[i],efficiency[i]});
        }
        sort(nums.begin(),nums.end(),cmp);
        // for(int i=0; i< nums.size(); i++) cout<<nums[i].first<<' '<<nums[i].second<<'\n';
        // cout<<'\n';
        priority_queue<int,vector<int>,greater<int>> pq;
        long long sum=0;
        vector<long long> c;

        for(int i=0; i< k ;i++)
        {
            pq.push(nums[i].first);
            sum+=nums[i].first;
            c.push_back(sum);
        }
        
       
        for(int i=k; i<n; i++)
        {
            if(nums[i].first>pq.top())
            {
                sum-=pq.top();
                pq.pop();
                pq.push(nums[i].first);
                sum+=nums[i].first;
            }
            c.push_back(sum);
        }
        //  for(int i=0; i< c.size(); i++)
        // {
        //     cout<<c[i]<<' ';
        // }
        long long ans=0;
        for(int i=0; i<n; i++)
        {
            ans=max(ans,(1LL*nums[i].second*(c[i])));
        }
        return ans%mod;
    }
};