/*
    Author: HungForree
    Link:
*/

#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=5e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using i128 = __int128;
constexpr i64 inf = 1E18;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve()
{
    int n, k; cin >> n >> k;

    vi a(k, 0);
    vector<bool> tight(k, true);

    for(int b = 29; b >= 0; b--)
    {
        int bit_n = (n >> b) & 1;

        if(bit_n == 1)
        {
            if(k % 2 != 0)
            {
                for(int i = 0; i < k; i++) a[i] |= (1 << b);
            }
            else
            {
                int idx = -1;
                for(int i = 0; i < k; i++) {
                    if(tight[i]) {
                        idx = i;
                        break;
                    }
                }
                if(idx == -1) idx = 0;

                tight[idx] = false;
                for(int i = 0; i < k; i++) {
                    if(i != idx) a[i] |= (1 << b);
                }
            }
        }
        else
        {
            vi loose_indices;
            for(int i = 0; i < k; i++) {
                if(!tight[i]) loose_indices.push_back(i);
            }

            int cnt = loose_indices.size();
            int take = (cnt % 2 == 0) ? cnt : cnt - 1;

            for(int i = 0; i < take; i++) {
                a[loose_indices[i]] |= (1 << b);
            }
        }
    }

    for(int i = 0; i < k; i++) cout << a[i] << " ";
    cout << el;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--)
    {
        solve();
    }
}
