class Solution {
public:
    int m;
    int n;
    int dp[201][201];
    int solve(int i,int j,vector<vector<int>>& grid){
        if(i==m-1 && j==n-1){
            return grid[i][j];
        }
        if(i<0 || j<0 || i>=m || j>=n){
            return INT_MAX;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j] = grid[i][j]+ min(solve(i+1,j,grid),solve(i,j+1,grid));
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        m=grid.size();
        n=grid[0].size();
        return solve(0,0,grid);
    }
};