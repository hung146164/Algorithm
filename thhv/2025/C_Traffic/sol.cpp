#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=1e5+1;

struct edge
{
    int to, val, coin, newval;
    edge(int a,int b,int c,int d)
    {
        to=a;
        val=b;
        coin=c;
        newval=d;
    }
};
struct node
{
    int minval,maxval;
    node(int a,int b)
    {
        minval=a;maxval=b;
    }
};
int tofake[N];
edge parent[N];
vector<edge> g[N];
vector<node> tree[N];
int index=1;
pair<int,int> euler(vector<vector<vector<int>>>& dske, int curr,int p=-1)
{
    tofake[curr]=index;
    index++;
    //set node
    node clone(curr,curr);

    for(int i=0; i< dske[curr].size(); i++)
    {
        vector<int> info=dske[curr][i];
        if(info[0]==p) continue;
        edge e(index+1,info[1],info[2],info[3]);
        g[tofake[curr]].push_back(e);
        parent[index+1]= edge(tofake[curr],info[1],info[2],info[3]);
        pair<int,int> p= euler(dske,info[0],tofake[curr]);
        clone.minval=min(p.first,clone.minval);
        clone.maxval=max(clone.maxval,p.second);
    }
    tree[tofake[curr]].push_back(clone);
    return {clone.minval,clone.maxval};
}
void get(vector<vector<int>>& duongdi, int start, int end)
{
    if(start==end)
    {
        return;
    }
    if(end<tree[start].minval || end>tree[start].maxval)
    {
        duongdi.push_back({parent[start].val,parent[start].coin,parent[start].newval});
        get(duongdi,parent[start].to,end);
    }
    else
    {
        for(int i=0; i<g[start].size(); i++)
        {
            int den=g[start][i].to;
            if(tree[den].minval<= start && tree[den].maxval>=start)
            {
                duongdi.push_back({g[start][i].val,g[start][i].coin,g[start][i].newval});
                get(duongdi,den,end);
            }
        }
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<vector<int>> input;
    vector<vector<vector<int>>> dske(n+1);
    for(int i=0; i< n-1; i++)
    {
        int x, y, v, c, s; cin>>x>>y>>v>>c>>s;
        dske[x].push_back({y,v,c,s});
    }

    euler(dske,1);

    int q;cin>>q;

    while(q--)
    {
        int a,b,c; cin>>a>>b>>c;
        int start=tofake[a];
        int end=tofake[b];
        vector<vector<int>> duongdi;
        get(duongdi,start,end);

        int sum=0;
        for(int i=0; i< duongdi.size(); i++)
        {
            sum+=duongdi[i][0];

        }

        int l=0, r=1e18;
        while(l<=r)
        {
            int incre=l+(r-l)/2;
            if(can(duongdi,incre,c))
            {
                r=incre-1;
            }
            else{
                l=incre+1;
            }
        }
        ans+=l;
        cout<<ans<<'\n';

    }


}


