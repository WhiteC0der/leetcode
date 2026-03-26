class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 0 || n == 0 || grid[0][0] == 1) return -1;
        priority_queue<P, vector<P>, greater<P>> q;
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        res[0][0] = 0;
        q.push({0, {0, 0}});
        int diri[] = {0, 0, -1, +1, +1, -1, +1, -1};
        int dirj[] = {-1, +1, 0, 0, +1, -1, -1, +1};
        while (!q.empty()) {
            auto curr = q.top();
            int dis = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;
            q.pop();
            if(dis > res[i][j]) continue;

            for (int k = 0; k < 8; k++) {
                int newi = i + diri[k];
                int newj = j + dirj[k];
                if (newi >= 0 && newi < m && newj >= 0 && newj < n &&
                    grid[newi][newj] == 0) {
                    if (res[newi][newj] > dis + 1) {
                        res[newi][newj] = dis + 1;
                        q.push({dis + 1, {newi, newj}});
                    }
                }
            }
        }
        if(res[m-1][n-1]==INT_MAX) return -1;

        return res[m-1][n-1]+1;
    }
};