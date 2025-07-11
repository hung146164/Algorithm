#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,q; cin>>n>>q;
        vector<int> nums;
        for(int i=0; i<n; i++)
        {
            int x; cin>>x;
            x--;
            nums.push_back(x);
        }
//        for(int i=0; i< nums.size(); i++)
//            cout<<nums[i]<<" ";
//
//        cout<<endl;
        vector<int> real(n);
        vector<int> diff(n);
        for(int i=0; i< n; i++)
        {
            real[nums[i]]=i;
            int mi=min(nums[i],i);
            int ma=max(nums[i],i);
            diff[mi]++;
            diff[ma]--;
        }
//        for(int i=0; i< diff.size(); i++)
//        {
//            cout<<diff[i]<<" ";
//        }
//        cout<<endl;
        for(int i=1; i< diff.size();i++)
        {
            diff[i]+=diff[i-1];
        }
//        for(int i=0; i< diff.size(); i++)
//        {
//            cout<<diff[i]<<" ";
//        }

        string s;cin>>s;
        set<int> issue;
        for(int i=0; i< s.size()-1; i++)
        {
            if(s[i]=='L' && s[i+1]=='R' && diff[i]!=0)
            {
                issue.insert(i);
            }
        }
        for(int i=0;i < q; i++)
        {
            int x; cin>>x;
            x--;
            s[x]=s[x]=='L'?'R':'L';
            if(x<n-1 )
            {
                if(s[x]=='L' && s[x+1]=='R' && diff[x]!=0)
                {
                    issue.insert(x);
                }
                else issue.erase(x);
            }

            if(x>0)
            {
                if(s[x]=='R' && s[x-1]=='L' && diff[x-1]!=0)
                {
                    issue.insert(x-1);
                }
                else issue.erase(x-1);
            }
            cout<<(issue.size()==0?"YES":"NO")<<endl;
        }
    }
}
