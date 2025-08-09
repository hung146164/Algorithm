#include<bits/stdc++.h>
using namespace std;

bool isdx(string& s)
{
    for(int i=0; i< s.size()/ 2; i++)
    {
        if(s[i]!=s[s.size()-1-i]) return false;
    }
    return true;
}
pair<int,int> sol(string& s)
{
    int f=s.size()%2==0?s.size():s.size()-1;

    while(f>0)
    {
        int count=0;
        for(int i=0; i<=s.size()-f; i++)
        {
            string a=s.substr(i,f/2);
            string b=s.substr(i+f/2,f/2);
            if(isdx(a) && isdx(b) )
            {
                int diff=0;
                for(int j=0; j<a.size(); j++)
                {
                    if(a[j]!=b[j]) diff++;
                }
                if(diff>1)
                    count++;
            }

        }
        if(count!=0) return {f,count};
        f-=2;
    }
    return {-1,-1};
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

//    freopen("PADBLE.INP","r",stdin);
//    freopen("PADBLE.OUT","w",stdout);

    string s;cin>>s;

    pair<int,int> ans=sol(s);
    if(ans.first==-1 && ans.second==-1) cout<<"-1"<<'\n';
    else cout<<ans.first<<' '<<ans.second<<'\n';

}
