#include<bits/stdc++.h>
#define ll long long
#define en "\n"
//cout << setprecision(7) << fixed
#define MOD 1000000007
using namespace std;
#define BIT(x, i) (((i) >> (x))&1)
#define find(s,a) s.find(a)!=s.end()
const ll N=1e5+5;
const ll inf=LLONG_MAX/4;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ll t;
    cin>>t;
    for(ll itest=0; itest<t; itest++)
    {


        ll n,m,k;
        cin>>n>>m>>k;
        vector<vector<tuple<ll,ll,ll,ll>>> g(n+1);
        for(ll i=0; i< m ; i++)
        {
            ll u,v,x1,x2,p;
            cin>>u>>v>>x1>>x2>>p;
            g[u].emplace_back(v,x1,x2,p);
        }
        priority_queue<vector<ll>,vector<vector<ll>>, greater<vector<ll>>> pq;
        pq.push({0,1,k});
        vector<ll> dist(n+1,0);
        dist[1]=0;
        while(!pq.empty())
        {
            vector<ll> clone=pq.top();
            pq.pop();

            ll c_time=clone[0];
            ll c_node=clone[1];
            ll c_k=clone[2];
            if(c_time>dist[c_node])
                dist[c_node]=c_time;
            for(auto& [v,x1,x2,p] : g[c_node] )
            {
//                if(itest==1)
//                {
//                    cout<<'\n';
//                    cout<<v<<' '<<x1<<' '<<x2<<' '<<ctime<<'\n';
//                    cout<<'\n';
//                }
                if(x1<c_time) continue;
                if(p==1)
                {
                    pq.push({x2,v,k});
                }
                else{
                    pq.push({x2,v,k-1});
                    pq.push({x2,v,k});
                }

            }
        }
//        for(ll i=0;i<dist.size(); i++)
//        {
//            cout<<dist[i]<<' ';
//        }
//        cout<<'\n';
            cout<<(dist[n]==inf?-1:dist[n])<<'\n';
    }


}

