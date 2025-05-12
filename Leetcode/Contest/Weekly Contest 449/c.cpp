class Solution {
public:
    int dfs(int& start,int curr,bool& iscycle, vector<vector<int>>& dp,vector<bool>& check,int pre=-1)
    {
        int ans=0;
        for(int i=0; i< dp[curr].size(); i++)
        {
            if(!check[dp[curr][i]])
            {
                check[dp[curr][i]]=true;
                ans+=dfs(start,dp[curr][i],iscycle,dp,check,curr);
            }
            else if(dp[curr][i]==start && pre!=start)
            {
                iscycle=true;
                return 0;
            }
        }
        return ans+1;
    }
    long long maxScore(int n, vector<vector<int>>& edges) {
        vector<int> cycle,line;
        vector<vector<int>> dp(n);
        for(int i=0; i< edges.size(); i++)
        {
            dp[edges[i][0]].push_back(edges[i][1]);
            dp[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> check(n);
        for(int i=0; i< n; i++)
        {
            if(!check[i])
            {
                check[i]=true;
                bool iscycle=false;
                int val= dfs(i,i,iscycle,dp,check);
                if(iscycle)
                {
                    cycle.push_back(val+1);
                }
                else
                {
                    line.push_back(val);
                }
              //  cout<<val<<endl;
            }
        }
        sort(cycle.begin(),cycle.end());
        sort(line.begin(), line.end(),greater<int>());
        // cout<<"Cy"<<endl;
        // for(auto i : cycle) cout<<i <<" ";
        // cout<<endl;
        // cout<<"line"<<endl;
        // for(auto i: line) cout<<i<<" ";
        // cout<<endl;
        long long ans=0;
        int v=n;
        for(int i=0; i< cycle.size(); i++)
        {
            ans+=imcycle(v,cycle[i]);
            v-=cycle[i];
        }
        // cout<<"imcycle "<<ans<<endl;
        for(int i=0; i< line.size(); i++)
        {
           // cout<<line[i]<<endl;
            ans+=imline(v,line[i]);
            v-=line[i];
        }
        return ans;
    }
    long long imcycle(int val,int countnode)
    {
        long long ans=0;
        long long pre=val;
        if(countnode%2==0)
        {
            for(int i=0; i< countnode/2; i++)
            {
                int curr=pre-(i==0?1:2);
                ans+=curr*pre;
                pre=curr;
            }
            for(int i=0; i< countnode/2; i++)
            {
                int curr=pre+(i==0?1:2);
                ans+=curr*pre;
                pre=curr;
            }
        }
        else
        {
            for(int i=0; i< countnode/2; i++)
            {
                int curr=pre-(i==0?1:2);
                ans+=curr*pre;
                pre=curr;
            }
            int ccur=pre-1;
            ans+=ccur*pre;
            pre=ccur;
            for(int i=0; i< countnode/2; i++)
            {
                int curr=pre+2;
                ans+=curr*pre;
                pre=curr;
            }
        }
        return ans;
    }
    long long imline(int val,int countnode)
    {
        long long ans=0;
        if(countnode%2==1)
        {
            long long pre=val;
            for(int i=0; i<countnode/2; i++)
            {
                int curr=pre-(i==0?1:2);
                ans+=curr*pre;
                pre=curr;
            }
            pre=val;
            for(int i=0; i<countnode/2; i++)
            {
                int curr=pre-2;
                ans+=curr*pre;
                pre=curr;
            }
        }
        else
        {
            long long pre=val;
            for(int i=0; i<countnode/2-1; i++)
            {
                int curr=pre-2;
                ans+=curr*pre;
                pre=curr;
            }
            pre=val;
            for(int i=0; i< countnode/2; i++)
            {
                int curr=pre-(i==0?1:2);
                ans+=curr*pre;
                pre=curr;
            }
        }
        return ans;
    }

};
