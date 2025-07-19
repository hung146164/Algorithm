#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> sangnt(int n)
{
    vector<pair<int,int>> ans;
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            int val=i;
            int c=0;
            while(n%i==0)
            {
                c++;
                n/=i;
            }
            ans.push_back({val,c});
        }
    }
    if(n!=1)
    {
        ans.push_back({n,1});
    }
    return ans;
}
vector<int> sol(int n,int m)
{
    if(n==1 && m!=1)
    {
        return {-1};
    }
    if(n>m) return {-1};
    if(n==m)
    {
        return {};
    }
    vector<pair<int,int>> nt1=sangnt(n),nt2=sangnt(m);
//    cout<<"NT1"<<endl;
//    for(int i=0;i<nt1.size(); i++){
//        cout<<nt1[i].first<<' '<<nt1[i].second<<endl;
//    }
//    cout<<"NT2"<<endl;
//    for(int i=0;i<nt2.size(); i++){
//        cout<<nt2[i].first<<' '<<nt2[i].second<<endl;
//    }
    if(nt1.size()!=nt2.size()) return {-1};
    for(int i=0; i< nt1.size(); i++)
    {
        if(nt1[i].first!=nt2[i].first) return {-1};
        if(nt1[i].second>nt2[i].second) return {-1};
    }
    vector<int> ans;

    while(true)
    {
        int have=false;
        int so=1;
        for(int i=0; i< nt1.size(); i++)
        {
              if(nt1[i].second==nt2[i].second) continue;
              have=true;
              if(nt1[i].second*2<=nt2[i].second)
              {
                  so*=pow(nt1[i].first,nt1[i].second);
                  nt1[i].second*=2;
              }
              else{
                so*=pow(nt1[i].first,nt2[i].second-nt1[i].second);
                nt1[i].second=nt2[i].second;
              }
        }

        if(!have) break;
        ans.push_back(so);
    }
    return ans;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
        int n,m; cin>>n>>m;
        vector<int> ans=sol(n,m);

        if(ans.size()==1 && ans[0]==-1) cout<<-1<<'\n';
        else{
                cout<<ans.size()<<' ';
            for(int i=0; i< ans.size(); i++)
            {
                cout<<ans[i]<<' ';
            }
            cout<<'\n';
        }
    }
}
