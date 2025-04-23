#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;

using si = set<int>;
using sll = set<ll>;
using mii = map<int, int>;
using mll = map<ll, ll>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define f first
#define s second

int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        string s; cin>>s;

        bool check=false;int c=0;
        int ans;
        if(s[0]=='1') ans=2;
        else ans=1;
        for(int i=1; i< s.size(); i++)
        {
            if(s[i]!=s[i-1] )
            {
                c++;
                ans+=2;
            }
            else{
                ans++;
            }
        }
        if(c==0) cout<< ans <<'\n';
        else if(c==1)
        {
            if(s[0]=='1') cout<<ans-1<<endl;
            else if(s[0]=='0') cout<<ans<<endl;
        }
        else if(c==2)
        {
            if(s[0]=='1') cout<<ans-2<<endl;
            else cout<<ans-1<<endl;
        }
        else if(c>2) cout<<ans-2<<endl;
        else cout<< ans<<endl;
    }
}

