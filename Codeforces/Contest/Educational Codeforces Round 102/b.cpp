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
bool check(string clone, string v)
{
    for(int i=0; i<v.size(); i+=clone.size())
    {
        if(v.substr(i,clone.size())!=clone) return false;
    }
    return true;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--)
    {
        string s,v; cin>>s>>v;
        int m=v.size();
        vector<string> can;
        for(int i=0; i< m; i++)
        {
            if(m%(i+1)==0 && check(v.substr(0,i+1),v))
            {

                can.push_back(v.substr(0,i+1));
            }
        }
        bool haveans=false;
        for(int i=0; i< can.size(); i++)
        {
            if(check(can[i],s))
            {
                int time=(s.size()* v.size() /gdc(s.size(),v.size()))/can[i].size();
                //cout<<"hh "<<time<<endl;
//                cout<<can[i].size()<<' '<<s.size()<<endl;
//                cout<<time<<endl;
                for(int j=0; j< time;j++)
                {
                    cout<<can[i];
                }
                haveans=true;
                break;
            }
        }
        if(!haveans) cout<<-1;
        cout<<'\n';
    }
}


