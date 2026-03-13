class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> que;
       for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) { que.push({i, 0}); grid[i][0]=0;}
            if (grid[i][n-1] == 1) { que.push({i, n-1}); grid[i][n-1]=0; }
        }
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1) { que.push({0, j}); grid[0][j]=0;}
            if (grid[m-1][j] == 1) { que.push({m-1, j});grid[m-1][j]=0; }
        }

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!que.empty()){
            int i=que.front().first;
            int j=que.front().second;
            que.pop();
            for(auto& d: dirs){
                int newi=i+d[0];
                int newj=j+d[1];
                if(newi>=0 && newj>=0 && newi<m && newj<n && grid[newi][newj]==1){
                    grid[newi][newj]=0;
                    que.push({newi,newj});
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) ans++;
            }
        }

        return ans;
    }
};