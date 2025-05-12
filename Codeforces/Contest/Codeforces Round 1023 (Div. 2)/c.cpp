#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
    ll t;cin>>t;
    ll sieumin=-1e18;
    while(t--)
    {
        ll n,k;cin>>n>>k;
        string s;cin>>s;
        vector<ll> dp;
        ll sum=0;
        ll maxx=sieumin;
        for(int i=0; i< n; i++)
        {
            ll x; cin>>x;
            dp.push_back(x);
            if(s[i]=='0')
            {
                sum=0;
                continue;
            }
            sum=max(sum+x,x);
            maxx=max(maxx,sum);
            if(sum<0) sum=0;
        }
        if(maxx>k)
        {
            cout<<"No"<<endl;
            continue;
        }
        vector<ll> zeropos;
        for(int i=0; i< s.size(); i++)
        {
            if(s[i]=='1') continue;
            zeropos.push_back(i);
        }

        if(zeropos.size()==0)
        {
            if(maxx==k)
            {
                cout<<"Yes"<<endl;
                for(int i=0; i< dp.size(); i++) cout<<dp[i]<<" ";
                cout<<endl;
            }
            else cout<<"No"<<endl;
            continue;
        }

        ll first=zeropos[0];

        ll ssum=0;
        ll lmax=sieumin;
        bool fl=0;
        for(int i=first-1;i>=0 && s[i]=='1' ; i--)
        {
            fl=true;
            ssum+=dp[i];
            lmax=max(lmax,ssum);

        }
        ll left= fl==true?lmax:0;

        ll psum=0;
        ll rmax=sieumin;
        bool fr=0;
        for(int i=first+1;i<n && s[i]=='1';i++)
        {
            fr=true;
            psum+=dp[i];
            rmax=max(rmax,psum);

        }
        ll right=fr==true?rmax:0;
        ll x=0;

        //chỉ update một phần 0 duy nhất
        if(left>=0 && right>=0) x=k-left-right;
        else if(left<=0 && right>=0) x=k-right;
        else if(left>=0 &&right<=0) x=k-left;
        else x=k;

        cout<<"Yes"<<endl;

        for(int i=0; i< n; i++)
        {
            if(s[i]=='0')
            {
                if(i==first) cout<<x<<" ";
                else cout<< sieumin<<" ";
            }
            else cout<<dp[i]<<" ";
        }
        cout<<endl;
    }
}

