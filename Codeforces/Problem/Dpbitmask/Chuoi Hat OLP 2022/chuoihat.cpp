#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=1e5+1;

short currenttest=1;
short dp[10001][1<<13];
short visited[10001][1<<13];
bool sol(vector<vector<short>>& dxbatdautaiicosizejketthuctai,vector<short>& len,short mask,short startindex)
{
    short n=len.size();

    if(mask==(1<<n)-1) return true;

    if(startindex>=dxbatdautaiicosizejketthuctai.size()) return false;

    if(dp[startindex][mask]!=-1 && visited[startindex][mask]==currenttest) return dp[startindex][mask];
    bool ans=false;
    for(short i=0; i< n; i++)
    {
        if((mask>>i)&1 || dxbatdautaiicosizejketthuctai[startindex][len[i]]==-1) continue;
        ans|=sol(dxbatdautaiicosizejketthuctai,len,mask|(1<<i),dxbatdautaiicosizejketthuctai[startindex][len[i]]+1);
    }
    visited[startindex][mask]=currenttest;
    return dp[startindex][mask]= ans;
}
void reset()
{
    for(short i=0; i< 10001; i++)
    {
        for(short j=0; j< (1<<13) ;j++)
        {
            dp[i][j]=-1;
            visited[i][j]=0;
        }
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    reset();

    string s; cin>>s;
    short n=s.size();


    vector<vector<short>> dxbatdautaiicosizejketthuctai(n+1,vector<short>(n+1,-1));
    for(short i=0; i<n; i++)
    {
        dxbatdautaiicosizejketthuctai[i][1]=i;
        if(i+1<n && s[i]==s[i+1])
        {
            short l=i,r=i+1;
            short f=2;
            while(l>=0 && r<n && s[l]==s[r])
            {
                dxbatdautaiicosizejketthuctai[l][f]=r;
                l--;
                r++;
                f+=2;
            }
        }
        if(i+2<n && s[i]==s[i+2])
        {
            short l=i,r=i+2;
            short f=3;
            while(l>=0 && r<n && s[l]==s[r])
            {
                dxbatdautaiicosizejketthuctai[l][f]=r;
                l--;
                r++;
                f+=2;
            }
        }
    }


    for(short i=n-2;i>=0;i--)
    {
        for(short j=n;j>=1;j--)
        {
            if(dxbatdautaiicosizejketthuctai[i][j]==-1)
            {
                dxbatdautaiicosizejketthuctai[i][j]=dxbatdautaiicosizejketthuctai[i+1][j];
            }
        }
    }
//        for(short i=0; i< n; i++)
//    {
//        for(short j=0; j< n; j++)
//        {
//            cout<<dxbatdautaiicosizejketthuctai[i][j]<<' ';
//        }
//        cout<<'\n';
//    }
     //vector<vector<short>> dp(n+1,vector<short>(1<<17,-1));
    short t; cin>>t;
    while(t--)
    {
        //reset();
        short k; cin>>k;
        vector<short> len(k);
        bool haveans=true;
        for(short i=0; i< k ;i++)
        {
            cin>>len[i];
            if(len[i]>n) haveans=false;
        }
        if(!haveans)
        {
            cout<<"NO"<<'\n';
            continue;
        }
        bool ans=false;
//        if(k==1)
//        {
//            cout<<((dxbatdautaiicosizejketthuctai[0][len[0]]!=-1)?"YES":"NO")<<'\n';
//            continue;
//        }
        for(short i=0; i< k ;i++)
        {
            if(dxbatdautaiicosizejketthuctai[0][len[i]]!=-1)
                ans|=sol(dxbatdautaiicosizejketthuctai,len,1<<i,dxbatdautaiicosizejketthuctai[0][len[i]]+1);
        }
        currenttest++;
        cout<<(ans?"YES":"NO")<<'\n';
    }
}



