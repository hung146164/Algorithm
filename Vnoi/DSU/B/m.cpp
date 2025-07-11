#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class DSU
{

public:
    vector<ll> parent,LEN;
    DSU(ll n)
    {
        parent.resize(n);
        LEN.resize(n);
        process(n);

    }
    void process(ll n)
    {
        for(int i=0; i<n; i++)
        {
            parent[i]=i;
            LEN[i]=1;
        }
    }
    void stl(ll a,ll b)
    {
        LEN[a]+=LEN[b];
        parent[b]=a;
    }
    bool join(ll a, ll b)
    {
        ll pa=find(a);
        ll pb=find(b);
        if(pa==pb) return false;
        if(LEN[pa]>LEN[pb])
        {
            stl(pa,pb);
        }
        else stl(pb,pa);
        return true;
    }
    ll find(ll u)
    {
        if(u==parent[u]) return u;
        return parent[u]=find(parent[u]);
    }

};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m,s;
    cin>>n>>m>>s;
    vector<vector<ll>> e;
    for(int i=0; i< m; i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        e.push_back({c,a,b,i});
    }
    sort(e.begin(),e.end());
    DSU dsu(n+1);
    vector<pair<ll,ll>> ans;
    ll sum=0;
    for (int i = e.size()-1; i >=0 ; i--) {
    if (!dsu.join(e[i][1], e[i][2])) {
        ans.push_back({e[i][3],e[i][0]});
    }
}
    sort(ans.begin(),ans.end());
    if(ans.size()!=0)
    {
        cout<<ans.size()<<'\n';
        for(int i=0; i< ans.size(); i++)
        {
            if(sum+ans[i].second>s) break;
            cout<<ans[i].second<<' ';
        }
    }


}
