class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int,vector<int>,greater<int>> ranh;
        for(int i=0; i< n ;i++)
        {
            ranh.push(i);
        }
        priority_queue<pair<long long ,int>,vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        vector<int> count(n);
        for(int i=0; i< meetings.size(); i++)
        {
            int start=meetings[i][0];
            int end= meetings[i][1];

            while(!pq.empty() && start>=pq.top().first)
            {
                ranh.push(pq.top().second);
                pq.pop();
            }

            if(ranh.size())
            {
                int room = ranh.top(); ranh.pop();
                count[room]++;
                pq.push({end, room});
            }
            else
            {
                pair<long long,int> curr=pq.top();pq.pop();
                pq.push({1LL*end-start+curr.first,curr.second});
                count[curr.second]++;
            }
        }
        int ans=0;
        int t=0;
        for(int i=0; i< count.size(); i++)
        {
            if(count[i]>t)
            {
                t=count[i];
                ans=i;
            }
            //cout<<count[i]<<" ";
        }
        return ans;
    }
};