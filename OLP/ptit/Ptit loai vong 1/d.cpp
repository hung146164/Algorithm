#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    vector<int> c;
    for(int i=0; i< n; i++)
    {
        int x; cin>>x;
        c.push_back(x);
    }
    reverse(c.begin(),c.end());
    vector<int> h;
    for(int i=0; i< c.size(); i++)
    {
        if(h.size() == 0 || h.back()<= c[i])
        {
            h.push_back(c[i]);
        }
        else{
            auto it=lower_bound(h.begin(),h.end(),c[i]);
            h[it-h.begin()]=c[i];
        }
    }
    cout<<h.size()<<'\n';
}
