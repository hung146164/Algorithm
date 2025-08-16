class Solution {
public:
    int longestAwesome(string s) {
        int mask=0;
        int n=s.size();
        vector<int> fi(1024,-2);
        vector<int> cmask(n);
        fi[0]=-1;
        for(int i=0; i< s.size(); i++)
        {
            int curr=s[i]-'0';
            mask^=(1<<curr);
            if(fi[mask]==-2) fi[mask]=i;
            else fi[mask]=min(fi[mask],i);
            cmask[i]=mask;
        }
        int ans=0;
        for(int i=0; i< s.size(); i++)
        {
            int curr=cmask[i];
            if(fi[curr]!=2) ans=max(ans,i-fi[curr]);
            for(int j=0;j<10; j++)
            {
                if(fi[curr^(1<<j)]!=-2)
                    ans=max(ans,i-fi[curr^(1<<j)]);
            }
        }
        return ans;
    }
};