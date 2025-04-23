class Solution {
public:
    int numberOfArrays(vector<int>& d, int lower, int upper) {
        long long ans=0;
        long long maxx=0;
        long long minn=0;
        long long c=0;
        for(int i=0; i<d.size(); i++)
        {
            c+=d[i];
            maxx=max(c,maxx);
            minn=min(c,minn);
        }
        long long a=upper-lower;
        long long b=maxx-minn;
        if(a<b) return 0;
        return a-b+1;
    }
};
