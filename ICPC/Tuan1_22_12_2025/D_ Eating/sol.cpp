#include<bits/stdc++.h>
using namespace std;

#define el '\n'
typedef long long ll;
const int N = 2e5 + 5;

int ar[N];
int near_pos[30][N];
int prefixXor[N];

// Hàm lấy bit cao nhất
int get_mb(int x) {
    if (x == 0) return -1;
    return 31 - __builtin_clz(x);
}

void solve() {
    int n,q; cin>>n>>q;
    for(int i=0; i< n; i++)
    {
        cin>>ar[i];
    }
    vector<int> prefix_xor(1,0);
    for(int i=0;i<n; i++)
    {
        prefix_xor.push_back(prefix_xor[i]^ ar[i]);
    }

    for(int i=1; i<= n; i++)
    {
        for(int b=0; b<30;b++)
        {
            int mb_preval=get_mb(ar[i-1]);
            if(mb_preval>=b)
            {
                near_pos[b][i]=i-1;
            }
            else near_pos[b][i]=near_pos[b][i-1];
        }
    }
//    for(int j=0; j< 30; j++)
//    {
//        for(int i=0; i<6; i++)
//        {
//            cout<<near_pos[j][i]<<' ';
//
//        }
//        cout<<el;
//    }
    while(q--)
    {
        int curr_val;cin>>curr_val;
        int start_pos=n;

        bool def=true;
        while(def)
        {
            if(curr_val==0) break;
//            cout<<"curr "<<curr_val<<el;
            int mb=get_mb(curr_val);
            int boss_pos= near_pos[mb][start_pos];
            if(boss_pos==-1)
            {
                start_pos=0;
                break;
            }
            def=false;
            int mini=prefix_xor[start_pos]^prefix_xor[boss_pos+1];
            curr_val^=mini;
            start_pos=boss_pos+1;
//            cout<<start_pos<<' '<<boss_pos<<el;
//            cout<<curr_val<<' '<<ar[boss_pos]<<el;
            if(curr_val>=ar[boss_pos])
            {
                curr_val^=ar[boss_pos];
                start_pos=boss_pos;
                def=true;
            }
            else break;
        }
        cout<<n-start_pos<<' ';
    }
    cout<<el;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(near_pos,-1,sizeof(near_pos));
//       freopen("input.txt","r",stdin);
//
//    freopen("output.txt","w",stdout);
    int t;
    if(cin >> t) {
        while(t--) solve();
    }
    return 0;
}
