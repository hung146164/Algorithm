#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=1e5+1;

ll maxll(ll a,ll b)
{
    if(a>b) return a;
    return b;
}
ll minll(ll a,ll b)
{
    if(a>b) return b;
    return a;
}
ll gdc(ll a, ll b)
{
    if(b==0) return a;
    return gdc(b,a%b);
}

namespace sub1
{
    bool CheckSub1()
    {
        return true;
    }
    void sol()
    {

    }
}
namespace sub2
{
    bool CheckSub2()
    {
        return true;
    }
    void sol()
    {

    }
}
namespace sub3
{
    bool CheckSub3()
    {
        return true;
    }
    void sol()
    {

    }
}
struct edge
{
public:
    int to,tstart,tend,type;
    edge(int a, int b, int c,int d)
    {
        this.to=a;
        this.tstart=b;
        this.tend=c;
        this.type=d;
    }
};
bool cmp(edge& a, edge& b)
{
    return a.tstart<b.tstart;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--)
    {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<edge>> g(n);
        for(int i=0; i< m ;i++)
        {
            int a,b,c,d,e;
            cin>>a>>b>>c>>d>>e;
            a--;
            b--;
            g[a].push_back(edge(b,c,d,e));
        }
        sort(g.begin(),g.end(),cmp);
        queue<vector<int>> q;
        //city, time,k
        q.push({0,0,k});
        int ans=0;
        vector<vector<int>> dist(n,vector<int>(k+1));
        while(!q.empty())
        {
            vector<int> curr=q.front();
            q.pop();
            int city=curr[0];
            int time=curr[1];
            int huy=curr[2];
            if(dist[city][huy]>=time) continue;
            dist[city][huy]=time;

            for(int i=0; i<g[city].size(); i++)
            {
                int to=g[city][i].to;
                int tstart=g[city][i].tstart;
                int tend=g[city][i].tend;
                int type=g[city][i].type;

                if(type==0)
                {

                }
                else{

                }


            }
        }
    }
}


