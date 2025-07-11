#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;
ll minn(ll a,ll b)
{
    if(a<b) return a;
    return b;
}
ll maxx(ll a,ll b)
{
    if(a>b) return a;
    return b;
}
pair<vector<ll>,ll> handle(string s)
{
    vector<ll> in;
    ll i=0;
    while(s[i]!='>')
    {
        ll v=0;
        bool have=false;
        while(s[i]-'0'<10 && s[i]-'0'>=0)
        {
            have=true;
            v*=10;
            v+=s[i]-'0';
            i++;
        }
        if(have) in.push_back(v);
        i++;
    }
    ll b=0;
    i+=2;
    for(;i<s.size(); i++)
    {
        b*=10;
        b+=s[i]-'0';
    }

    return {in,b};
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,k; cin>>n>>k;

    vector<ll> nums;
    for(ll i=0; i< n; i++)
    {
        ll x; cin>>x;
        nums.push_back(x);
    }
    cin.ignore();
    vector<vector<ll>> g(n);
    for(ll i=0; i< n; i++)
    {
        string s;
        if(i==n-1) {cin>>s; continue;}
        getline(cin,s);
        cin.ignore();
        pair<vector<ll>,ll> in=handle(s);
        for(ll j=0; j<in.first.size(); j++)
        {
            g[in.second].push_back(in.first[j]);
        }
    }
//    for(ll i=0; i< g.size(); i++)
//    {
//        for(ll j=0; j< g[i].size(); j++)
//        {
//            cout<<g[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    vector<bool> danglam(n);

    for(ll i=0; i<g.size(); i++)
    {
        if(g[i].size()==0)
        {
            pq.push({nums[i],i});
            k--;
            danglam[i]=true;
        }
    }
    vector<ll> hh(n,INT_MAX);
    //tg ht task lam
    vector<bool> check(n);
    ll ans=0;

    while(!pq.empty())
    {
        pair<ll,ll> curr=pq.top();
        //cout<<curr.first<<" "<<curr.second<<endl;
        pq.pop();
        danglam[curr.second]=false;
        check[curr.second]=true;
        hh[curr.second]=minn(curr.first,hh[curr.second]);
        ans=max(ans,hh[curr.second]);

        k++;
        //tim xem co tag nao lam dc luon k
        for(ll i=0; i< n; i++)
        {
            if(k==0) break;
            if(check[i] || danglam[i]) continue;
            else{
                bool cothe=true;
                //kiem tra xem co the lam tag i duoc khong
                for(ll j=0; j<g[i].size(); j++)
                {
                    if(!check[g[i][j]])
                    {
                        cothe=false;
                        break;
                    }
                }
                if(cothe)
                {
                    pq.push({curr.first+nums[i],i});
                    danglam[i]=true;
                    k--;
                }
            }
        }

    }
    cout<<ans<<endl;
    return 0;
}

