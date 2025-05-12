using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        const int MAXV = 100000;

        vector<long long> prefixRow(n, 0), prefixCol(m, 0);
        static int minRow[MAXV + 1], maxRow[MAXV + 1];
        static int minCol[MAXV + 1], maxCol[MAXV + 1];
        fill(minRow, minRow + MAXV + 1, -1);
        fill(maxRow, maxRow + MAXV + 1, -1);
        fill(minCol, minCol + MAXV + 1, -1);
        fill(maxCol, maxCol + MAXV + 1, -1);

        long long totalSum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int v = grid[i][j];
                prefixRow[i] += v;
                prefixCol[j] += v;
                totalSum += v;
                if (minRow[v] == -1) {
                    minRow[v] = maxRow[v] = i;
                    minCol[v] = maxCol[v] = j;
                } else {
                    minRow[v] = min(minRow[v], i);
                    maxRow[v] = max(maxRow[v], i);
                    minCol[v] = min(minCol[v], j);
                    maxCol[v] = max(maxCol[v], j);
                }
            }
        }

        // horizontal cuts
        long long upperSum = 0;
        for (int i = 0; i < n - 1; ++i) {
            upperSum += prefixRow[i];
            long long lowerSum = totalSum - upperSum;
            if (upperSum == lowerSum)
                return true;

            if (upperSum > lowerSum) {
                long long diff = upperSum - lowerSum;
                if (diff <= MAXV && minRow[diff] != -1) {
                    if (i == 0 || m == 1) {
                        if (diff == grid[0][0] || diff == grid[0][m - 1])
                            return true;
                    } else if (minRow[diff] <= i) {
                        return true;
                    }
                }
            } else {
                long long diff = lowerSum - upperSum;
                if (diff <= MAXV && maxRow[diff] != -1) {
                    if (i == n - 2 || m == 1) {
                        if (diff == grid[i + 1][0] ||
                            diff == grid[i + 1][m - 1])
                            return true;
                    } else if (maxRow[diff] > i) {
                        return true;
                    }
                }
            }
        }

        // vertical cuts
        long long leftSum = 0;
        for (int j = 0; j < m - 1; ++j) {
            leftSum += prefixCol[j];
            long long rightSum = totalSum - leftSum;
            if (leftSum == rightSum)
                return true;

            if (leftSum > rightSum) {
                long long diff = leftSum - rightSum;
                if (diff <= MAXV && minCol[diff] != -1) {
                    if (j == 0 || n == 1) {
                        if (diff == grid[0][0] || diff == grid[n - 1][0])
                            return true;
                    } else if (minCol[diff] <= j) {
                        return true;
                    }
                }
            } else {
                long long diff = rightSum - leftSum;
                if (diff <= MAXV && maxCol[diff] != -1) {
                    if (j == m - 2 || n == 1) {
                        if (diff == grid[0][j + 1] ||
                            diff == grid[n - 1][j + 1])
                            return true;
                    } else if (maxCol[diff] > j) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
