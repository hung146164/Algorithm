class Solution {
public:
    int numRabbits(vector<int>& a) {
        unordered_map<int,int> dp;
        int ans=0;
        for(int i=0; i< a.size(); i++)
        {
            dp[a[i]]++;
        }
        for(auto i: dp)
        {
            ans+=i.second/(i.first+1)*(i.first+1);
            if(i.second%(i.first+1)!=0)
            {
                ans+=i.first+1;
            }
        }

        return ans;
    }
};
