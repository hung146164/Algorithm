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

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    if(n==1)
    {
        cout<<"Uphold integrity and ethics throughout the contest."<<'\n';
    }
    else if(n==2)
    {
        cout<<"Do not seek or receive external help from people, platforms, tools or AI."<<'\n';
    }
    else if(n==3)
    {
        cout<<"Follow all ICPC rules and guidelines, accept decisions made by organizers and judges as final."<<'\n';
    }
    else if(n==4)
    {
        cout<<"Show good sportmanship and treat competitors, volunteers, staff and judges with respect."<<'\n';
    }
    else
    {
        cout<<"Compete with creativity and teamwork, honor the contest spirit and pursue excellence."<<'\n';
    }
}


