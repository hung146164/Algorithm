    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;

    bool sol(int a)
    {
        ll A=a*a*2;
        for(ll i=1;i*i<=A/2 ; i++)
        {
            ll C=A-i*i;
            ll c = (ll)floor(sqrtl((long double)C) + 0.5L);
            if(c*c==C && c!=i && c!=a && i!=a) return true;
        }
        return false;
    }
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int a;cin>>a;

        cout<<(sol(a)?"YES":"NO")<<'\n';

    }
