class Solution {
public:
    typedef long long ll;

    long long calculateScore(vector<string>& ins, vector<int>& val) {
       long long ans=0;
        int n=ins.size();
        unordered_map<int,int> dp;
        int curr=0;
        for(int i=0; i< ins.size(); i++)
        {
            if(dp.find(curr)!=dp.end() || curr<0 || curr>=n )
            {
                break;
            }
            dp[curr]=1;
            if(ins[curr]=="jump")
            {
                curr+=val[curr];
            }
            else
            {
                ans+=val[curr];
                curr++;
            }
        }
        return ans;
    }
};
