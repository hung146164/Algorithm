class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        vector<long long> row,col;
        int val=0;
        long long sum=0;
        for(int i=0; i< grid.size(); i++)
        {

            for(int j=0; j< grid[0].size(); j++)
            {
                sum+=grid[i][j];
            }
            row.push_back(sum);
        }

        sum=0;
          for(int i=0; i< grid[0].size(); i++)
        {

            for(int j=0; j< grid.size(); j++)
            {
                sum+=grid[j][i];
            }
            col.push_back(sum);
        }
        long long ans1=row[row.size()-1]/2;
        if(row[row.size()-1]%2==0)
        {
            for(int i=0; i< row.size(); i++)
            {
                if(row[i]==ans1) return true;
            }
        }
        long long ans2=col[col.size()-1]/2;
        if(col[col.size()-1]%2==0)
        {
            for(int i=0; i< col.size(); i++)
            {
                if(col[i]==ans2) return true;
            }
        }
        return false;

    }
};
