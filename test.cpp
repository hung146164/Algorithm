class Solution {
public:
    unordered_map<string,unordered_map<string,int>> price;

    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {

        unordered_set<string> st;
        for(int i=0; i< original.size(); i++)
        {
            st.insert(original[i]);
            st.insert(changed[i]);
        }
        for(auto& i:st)
        {
            for(auto & j:st)
            {
                price[i][j]=(i==j?0:INT_MAX);
            }
        }
        for(int i=0; i< original.size(); i++)
        {
            price[original[i]][changed[i]]=cost[i];
        }
        for(auto &[k,_] :price)
        {
            for(auto&[i,_]: price)
            {
                for(auto&[j,_]:price)
                {
                    if(price[i][k]<INT_MAX && price[k][j]<INT_MAX)
                    {
                        price[i][j]=min(price[i][j],price[i][k]+price[k][j]);
                    }
                }
            }
        }
        // for(auto [a,l2] : price)
        // {
        //     for(auto [b,p]: l2)
        //     {
        //         cout<<a<<' '<<b<<' '<<p<<'\n';
        //     }
        // }
        vector<vector<int>> dp(source.size(), vector<int>(source.size(),INT_MAX));
        long long res = sol(dp, 0, 0, source, target);
        return (res == INT_MAX ? -1 : res);
    }
    long long sol(vector<vector<int>>& dp, int pre,int curr,string& source, string& target)
    {
        if(curr==source.size())
        {
            if(pre==curr) return 0;
            else return INT_MAX;
        }
        if(dp[curr][pre]!=INT_MAX) return dp[curr][pre];
        //lay
        long long ans=INT_MAX;
        long long gia= price[source.substr(pre,curr-pre+1)][target.substr(pre,curr-pre+1)];
        if(gia!=INT_MAX)
        {
            ans=min(ans,gia+sol(dp,curr+1,curr+1,source,target));
        }
        //boqua
        ans=min(ans,sol(dp,pre,curr+1,source,target));

        dp[curr][pre]=ans;
        return ans;
    }
};
