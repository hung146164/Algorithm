#include<bits/stdc++.h>
using namespace std;

pair<int,int> tim(pair<int,int> rbs, int x, pair<int,int> rbt)
{
    if(x==0)
    {
        int newx=max(rbs.first,rbt.first);
        int newy=min(rbs.second,rbt.second);
        if(newx>newy) return {-1,-1};
        return {newx,newy};
    }
    if(x==1)
    {
        int newx=max(rbs.first-1,rbt.first);
        int newy= min(rbs.second-1,rbt.second);
        if(newx>newy) return {-1,-1};
        return {newx,newy};
    }
    else{
        int newx=max(rbs.first-1,rbt.first);
        int newy=min(rbs.second,rbt.second);
        if(newx>newy) return {-1,-1};
        return {newx,newy};
    }
}

vector<int> sol()
{
    int n; cin>>n;
    vector<int> nums(n);
    for(int i=0; i< n; i++)
    {
        cin>>nums[i];
    }
    vector<pair<int,int>>ob(n);
    for(int i=0; i< n; i++)
    {
        cin>>ob[i].first>>ob[i].second;
    }

    vector<pair<int,int>> cc(n);

    cc[n-1] = {ob[n-1].first, ob[n-1].second};
    if (cc[n-1].first > cc[n-1].second) return {};

    for(int i=n-2; i >=0; i--)
    {
        pair<int,int> change = tim(cc[i+1], nums[i+1], ob[i]);
        if(change.first == -1 && change.second == -1) return {};
        cc[i] = change;
    }

    vector<int> ans;
    int current_h = 0;

    for(int i=0; i<n; i++)
    {
        int d_i_val = nums[i];
        int min_h_target_at_i = cc[i].first;
        int max_h_target_at_i = cc[i].second;

        if(d_i_val != -1)
        {
            int next_h = current_h + d_i_val;
            if(next_h < min_h_target_at_i || next_h > max_h_target_at_i)
            {
                return {};
            }
            ans.push_back(d_i_val);
            current_h = next_h;
        }
        else
        {
            bool chosen_d_i = false;

            int h_if_d0 = current_h + 0;
            if(h_if_d0 >= min_h_target_at_i && h_if_d0 <= max_h_target_at_i)
            {
                ans.push_back(0);
                current_h = h_if_d0;
                chosen_d_i = true;
            }

            if(!chosen_d_i)
            {
                int h_if_d1 = current_h + 1;
                if(h_if_d1 >= min_h_target_at_i && h_if_d1 <= max_h_target_at_i)
                {
                    ans.push_back(1);
                    current_h = h_if_d1;
                    chosen_d_i = true;
                }
            }

            if(!chosen_d_i)
            {
                return {};
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
        vector<int> result = sol();
        if(result.empty())
        {
            cout << -1 << endl;
        }
        else
        {
            for(int i=0; i< result.size(); i++ )
            {
                cout << result[i] << (i == result.size() - 1 ? "" : " ");
            }
            cout << endl;
        }
    }
    return 0;
}
