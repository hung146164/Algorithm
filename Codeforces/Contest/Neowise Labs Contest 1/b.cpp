#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--)
    {
        int n, k; cin>>n>>k;
        vector<int> a1,a2;
        for(int i=0; i< n; i++)
        {
            int x; cin>>x;
            a1.push_back(x);
        }
        for(int i=0; i< n; i++)
        {
            int x; cin>>x;
            a2.push_back(x);
        }
        ll ans=0;
        vector<int> huhu;
        for(int i=0; i< n; i++)
        {
            ans+=max(a1[i],a2[i]);
            huhu.push_back(min(a1[i],a2[i]));
        }
        sort(huhu.begin(),huhu.end(),greater<int>());
        for(int i=0; i< k-1; i++)
        {
            ans+=huhu[i];
        }
        cout<<ans+1<<endl;
    }
    return 0;
}
