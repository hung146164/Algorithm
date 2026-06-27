#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 500000 + 5;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("snake_scales_chapter_2_input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t; cin>>t;

    for(ll k=1; k<=t; k++){
        ll n; cin>>n;
        vector<ll> nums(n);
        vector<ll> minreach(n);
        for(ll i=0;i<n;i++) {
            ll x; cin>>x;
            nums[i]=x;
            minreach[i]=x;
        }
        ll ans=0;
        for(int i=0; i< n; i++)
        {
            ll ma=minreach[i];
            for(int j=i-1; j>=0; j--)
            {
                ma=max(ma,abs(nums[j]-nums[j+1]));
                minreach[j]=min(minreach[j],ma);
            }
            ma=minreach[i];
            for(int j=i+1; j<n; j++)
            {
                ma=max(ma,abs(nums[j]-nums[j-1]));
                minreach[j]=min(minreach[j],ma);
            }
        }
        for(int i=0; i< n; i++) ans=max(minreach[i],ans);

        cout << "Case #" << k << ": " << ans << "\n";
    }
    return 0;
}

