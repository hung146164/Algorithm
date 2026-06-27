/*
    Author: HungForree
    Link: https://codeforces.com/contest/2045/problem/A
*/

#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=5e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using i128 = __int128;
constexpr i64 inf = 1E18;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
int sol(int p,int a,int y)
{
    int ans=0;
    while(true)
    {
        int need_p=max(0,2-p);
        int need_a=max(0,1-a);
        if(need_p+need_a>y)
        {
           // cout<<ans<<el;
            return ans;
        }
        y-=need_p+need_a;
        //cout<<need_p<<' '<<need_a<<el;
        ans+=3;
        if(need_p==0)
        {
            p-=2;
        }
        else
        {
            p=0;
        }
        if(need_a==0)
        {
            a--;
        }
        else
        {
            a=0;
        }
    }
    return ans;
}
void solve()
{
    string s; cin>>s;
    int p=0,a=0,n=0,g=0,y=0;
    for(int i=0; i< s.size(); i++)
    {
        if(string("AEIOU").find(s[i])!=string::npos)
        {
            a++;
        }
        else if(s[i]=='N')
        {
            p++;
            n++;
        }
        else if(s[i]=='G')
        {
            g++;
            p++;
        }
        else if(s[i]=='Y')
        {
            y++;
        }
        else
        {
            p++;
        }
    }
    int ng=min(g,n);
    int ans=0;
    for(int i=1;i<=s.size()/3 ; i++)
    {
        int need_a=min(a,i);
        int need_y_for_a=i-need_a;

        if(need_y_for_a>y) continue;

        int y_con_lai=y-need_y_for_a;

        int so_block_cho_nguyen_am=2*i;

        int nguyen_am_hien_tai=p+y_con_lai;
        if(nguyen_am_hien_tai<so_block_cho_nguyen_am) continue;
        int p_dung= so_block_cho_nguyen_am+ min({so_block_cho_nguyen_am,ng,nguyen_am_hien_tai-so_block_cho_nguyen_am});
        ans=max(ans,i+p_dung);
    }
    cout<<ans<<el;

}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int t; t=1;
    while(t--)
    {
        solve();
    }
}









