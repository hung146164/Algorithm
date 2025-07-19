#include<bits/stdc++.h>
using namespace std;

int pow2[12];
void process()
{
    pow2[0]=1;
    for(int i=1; i<12; i++)
    {
        pow2[i]=pow2[i-1]*2;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("lostcow.in","r",stdin);
    freopen("lostcow.out","w",stdout);

    process();
    int x, y;cin>>x>>y;
    int ans=0;
    if(x<y)
    {

        int hehe=x;
        int c=0;
        bool e=true;
        while(x<y)
        {
            ans+=pow2[c];
            if(e)
            {
                x+=pow2[c];
                if(x>=y)
                {
                    ans-=(x-y);
                    break;
                }
            }
            else{
                x-=pow2[c];
            }
            ans+=pow2[c];
            x=hehe;
            e=!e;
            c++;

        }
    }
    else{
        int hehe=x;
        int c=0;
        bool e=true;
        while(x>y)
        {
            ans+=pow2[c];
            if(e)
            {
                x+=pow2[c];

            }
            else{
                x-=pow2[c];
                if(x<=y)
                {
                    ans-=(y-x);
                    break;
                }
            }
            ans+=pow2[c];
            x=hehe;
            e=!e;
            c++;

        }
    }
    cout<<ans<<'\n';

}
