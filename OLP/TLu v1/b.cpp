#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n;
    int a, b, c; cin>>a>>b>>c;
    vector<int> ans;
    while(a)
    {
        ans.push_back(a%b);
        a/=b;
    }
    for(int i=ans.size()-1;i>=0; i--)
    {
        cout<<ans[i];
    }

    return 0;
}
