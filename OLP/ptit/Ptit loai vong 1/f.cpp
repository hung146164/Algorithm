#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int N=1e6+1;
ll ans[N];

bool ok(string& s)
{
    int n=s.size();
    int c=0;
    for(int i=0; i< n/2; i++)
    {
        if(s[i]!=s[n-i-1])
        {
            c++;
        }
        if(c>1) return false;
    }
    return true;
}
void process()
{
    for(int i=1; i<N; i++)
    {
        string s=to_string(i);
        ans[i]=ans[i-1];
        if(ok(s))
        {
            ans[i]++;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    process();
    int q;cin>>q;
    while(q--)
    {
        int a,b; cin>>a>>b;

        cout<<ans[b]-ans[a-1]<<'\n';
    }


}
