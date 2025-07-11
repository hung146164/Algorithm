#include<bits/stdc++.h>
using namespace std;
pair<vector<int>, vector<int>> shortest_odd_even_paths(const vector<vector<int>>& g) {
    int n = g.size();
    vector<vector<int>> dist(n, vector<int>(2, -1));
    queue<pair<int, int>> q;

    dist[0][0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        pair<int,int> curr=q.front(); int u=curr.first; int parity=curr.second;
        q.pop();
        for (int v : g[u]) {
            int next_parity = 1 - parity;
            if (dist[v][next_parity] == -1) {
                dist[v][next_parity] = dist[u][parity] + 1;
                q.push({v, next_parity});
            }
        }
    }

    vector<int> odd(n), even(n);
    for (int i = 0; i < n; ++i) {
        odd[i] = dist[i][1];
        even[i] = dist[i][0];
    }
    return {odd, even};
}
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n ;cin>>n;
        int m;cin>>m;
        int k; cin>>k;
        vector<int> mu;
        int sum=0;

        for(int i=0; i< k ;i++)
        {
            int x; cin>>x;
            mu.push_back(x);
            sum+=x;
        }
        int maxl=0;
        int maxc=0;
        if(sum%2==0)
        {
            maxc=sum;
        }
        else{
            maxl=sum;
        }
        sort(mu.begin(), mu.end());
        if(maxc==0)
        {
            int cc=0;
            for(int i=0; i< mu.size(); i++)
            {
                if(mu[i]%2==0)
                {
                    cc=max(cc,mu[i]);
                }
                else{
                    maxc=max(sum-mu[i],maxc);
                }
            }
             maxc=max(cc,maxc);
        }
        if(maxl==0)
        {
            int cc=0;
            for(int i=0; i< mu.size(); i++)
            {
                if(mu[i]%2==1)
                {
                    cc=max(cc,mu[i]);
                    maxl=max(sum-mu[i],maxl);
                }
            }
             maxl=max(maxl,cc);
        }
//        cout<<"maxc: "<<maxc<<" maxl: "<<maxl<<endl;
        vector<vector<int>> dp(n);
        for(int i=0; i< m ;i++)
        {
            int x,y; cin>>x>>y;
            x--;y--;
            dp[x].push_back(y);
            dp[y].push_back(x);
        }
        queue<int> q;
        pair<vector<int>,vector<int>> hihi=shortest_odd_even_paths(dp);

        vector<int> disle=hihi.first;
        vector<int> dischan=hihi.second;
//        cout<<"disle: ";
//        for(auto i: disle) cout<<i<<" ";
//        cout<<endl;
//        cout<<"dischan"<<endl;
//        for(auto i: dischan) cout<<i<<" ";
//        cout<<endl;

        vector<bool> check(n,false);
        q.push(0);
        check[0]=true;
        vector<int> ans;
//        cout<<"dis: ";
        for(int i=0; i< n; i++)
        {
            if((disle[i]!=-1 && maxl>=disle[i])||(dischan[i]!=-1 && maxc>= dischan[i]))
            {
                ans.push_back(1);
            }
            else ans.push_back(0);
        }
        for(int i=0; i< ans.size(); i++) cout<<ans[i];
        cout<<endl;
    }
}
