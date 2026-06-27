#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll N=1e5+1;

bool check[N];

vector<ll> sang()
{
    vector<ll> sont;
    for(ll i=2; i<N; i++)
    {
        if(!check[i])
        {
            sont.push_back(i);
            for(ll j=i*i;j<N ;j+=i)
            {
                check[j]=true;
            }
        }
    }
    return sont;
}
ll powll(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a;
        }
        b/=2;
        a=a*a;
    }
    return ans;
}
vector<pair<ll,ll>> get(ll n,vector<ll>& snt)
{
    vector<pair<ll,ll>> ans;
    for(ll i=0; i<snt.size() && snt[i]<=n; i++)
    {
        ll cnt=0;
        while(n%snt[i]==0)
        {
            n/=snt[i];
            cnt++;
        }
        if(cnt!=0)
        {
            ans.push_back({snt[i],cnt});
        }
    }
    if(n!=1) ans.push_back({n,1});
    return ans;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ll> snt = sang();
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        if(n>m)
        {
            cout<<-1<<'\n';
            continue;
        }
        else if(n==m)
        {
            cout<<0<<'\n';
            continue;
        }
        vector<pair<ll,ll>> uoca=get(n,snt),uocb=get(m,snt);

        if(uoca.size()!=uocb.size())
        {
            cout<<-1<<'\n';
            continue;
        }
        else{
            bool isequal=true;
            for(ll i=0; i< uoca.size(); i++)
            {
                if(uoca[i].first!=uocb[i].first || uoca[i].second> uocb[i].second)
                {
                    isequal=false;
                    break;
                }
            }
            if(!isequal)
            {
                cout<<-1<<'\n';
                continue;
            }
            ll ans=0;
            vector<ll> h(201,1);
            for(ll i=0; i< uoca.size(); i++)
            {
                ll val=uoca[i].second;
                ll cnt=0;
                while(val!=uocb[i].second)
                {
                    ll time=min(uocb[i].second-val,val);
                    val+=time;
                    h[cnt]*=powll(uoca[i].first,time);
                    cnt++;
                }
                ans=max(ans,cnt);
            }
            cout<<ans<<' ';
            ll i=0;
            while(i<201 && h[i]!=1)
            {
                cout<<h[i]<<' ';
                i++;
            }
            cout<<'\n';
        }
    }


}


