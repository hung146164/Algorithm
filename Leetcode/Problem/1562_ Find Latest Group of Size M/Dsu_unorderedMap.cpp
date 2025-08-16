class Solution {
public:
    static const int N=1e5+1;
    int parent[N],len[N];
    void process(int n)
    {
        for(int i=0; i< n; i++)
        {
            parent[i]=i;
            len[i]=1;
        }
    }
    int find(int n)
    {
        if(parent[n]==n)
        {
            return n;
        }
        return parent[n]=find(parent[n]);
    }
    void join(int a,int b)
    {
        int pa=find(a);
        int pb= find(b);
        if(pa==pb) return;
        if(len[pb]>len[pa])
        {
            swap(pa,pb);
        }
        len[pa]+=len[pb];
        parent[pb]=pa;
    }
    int findLatestStep(vector<int>& arr, int m) {
        int n=arr.size();
        process(n);
        vector<int> nums(n,0);
        int ans=-1;
        unordered_map<int,int> ms;
        for(int i=0; i< n; i++)
        {
            int curr=arr[i]-1;
            if(curr-1>=0 && nums[curr-1]==1)
            {
                ms[len[find(curr-1)]]--;
                join(curr,curr-1);
            }
            if(curr+1<n && nums[curr+1]==1)
            {
                ms[len[find(curr+1)]]--;
                join(curr,curr+1);
            }
            ms[len[find(curr)]]++;
            nums[curr]=1;

            if(ms[m]>0)
            {
              ans=i+1;
              //cout<<i<<' '<<ms[m]<<'\n';
            }

        }
        return ans;
    }
};