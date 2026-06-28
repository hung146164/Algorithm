#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N=1e5+5;
const ll mod=1e9+7;
ll dx[]{0,0,-1,1};
ll dy[]{-1,1,0,0};
char a[1000][1000];
bool check[1000][1000];
ll n,m,k;
bool ok(string& s, ll x,ll y, ll curr,bool& ans)
{
    if(curr==s.size()) return true;
    if(x<0 || y<0 || x>=n || y>=m || check[x][y]) return false;
    if(a[x][y]!=s[curr]) return false;
    check[x][y]=true;
    bool re=false;
    for(ll i=0; i< 4; i++)
    {
        re|=ok(s,x+dx[i],y+dy[i],curr+1,ans);
    }
    check[x][y]=false;
    return re;
}
bool can(string& s)
{
    bool ans=false;
    for(ll i=0; i< n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            if(a[i][j]==s[0])
            {
                if(ok(s,i,j,0,ans))
                {
                    return true;
                }
            }
        }
    }
    return false;
}
void solve()
{
     cin>>n>>m>>k;
    for(ll i=0; i< n; i++)
    {
        for(ll j=0; j<m ; j++)
        {
            cin>>a[i][j];
//            if(!(a[i][j]-'A'>=0 && a[i][j]-'A'<26))
//            {
//                a[i][j]=a[i][j]-'a'+'A';
//            }
        }
    }
    for(ll i=1;i<=k; i++)
    {

        ll sz;cin>>sz;
        string s; cin>>s;



        bool ans=can(s);
        cout<<"#"<<i<<": "<<(ans?"YES":"NO")<<(i==k?"":"\n");
    }
}

signed main()
{
    solve();
}









