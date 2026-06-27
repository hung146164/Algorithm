/*
    Author: HungForree
    Link:
*/

#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=1e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using i128 = __int128;
constexpr i64 inf = 1E18;

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
int min_snt[N];
unordered_map<string,int> dp;
void sang()
{
    min_snt[1]=1;
    for(int i=2; i<32; i++)
    {
        if(min_snt[i]==0)
        {
            for(int j=i; j<N; j+=i)
            {
                if(min_snt[j]==0) min_snt[j]=i;
            }
        }
    }
    dp.reserve(1000);
    int ans=0;
    string re;
    for(int i=2; i<6000; i++)
    {
        int clone=i;
        int val=0;
        int cnt=0;
        while(clone)
        {
            val+=clone%10;
            clone/=10;
            cnt++;
        }
        if(min_snt[val]==val && val!=1)
        {
            ans+=cnt;
            re+=to_string(i);
        }
    }
    //cout<<re<<el;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            for(int k=0; k<10; k++)
            {
                string candidate;
                candidate+=i+'0';
                candidate+=j+'0';
                candidate+=k+'0';
                for(int j=(int)candidate.size()-1; j<re.size(); j++)
                {
                    if(re.substr(j-(int)candidate.size()+1,candidate.size()) == candidate && dp.find(candidate)==dp.end())
                    {
                        dp[candidate]=(j-(int)candidate.size()+2);
                    }
                }
            }
        }
    }
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            string candidate;
            candidate+=i+'0';
            candidate+=j+'0';
            for(int j=(int)candidate.size()-1; j<re.size(); j++)
            {

                if(re.substr(j-(int)candidate.size()+1,candidate.size()) == candidate && dp.find(candidate)==dp.end())
                {
                    dp[candidate]=(j-(int)candidate.size()+2);
                }
            }
        }
    }
    for(int i=0; i<10; i++)
    {

        string candidate;
        candidate+=i+'0';
        for(int j=(int)candidate.size()-1; j<re.size(); j++)
        {

            if(re.substr(j-(int)candidate.size()+1,candidate.size()) == candidate && dp.find(candidate)==dp.end())
            {
                dp[candidate]=(j-(int)candidate.size()+2);
            }
        }


    }

    int maxx=0;
    for(auto& i: dp)
    {
        cout<<i.first<<' '<<i.second<<el;
        maxx=max(i.second,maxx);
    }
    cout<<dp.size()<<el;
    cout<<maxx<<endl;
}
void solve()
{
    string x; cin>>x;
    cout<<dp[x]<<el;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    sang();
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}









