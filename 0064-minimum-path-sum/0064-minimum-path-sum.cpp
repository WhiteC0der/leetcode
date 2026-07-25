class Solution {
public:
    int m;
    int n;
    int dp[201][201];
    int solve(int i,int j,vector<vector<int>>& grid){
        if(i==0 && j==0){
            return grid[i][j];
        }
        if(i<0 || j<0){
            return INT_MAX;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j] = grid[i][j]+min(solve(i-1,j,grid),solve(i,j-1,grid));
    }
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(m-1,n-1,grid);
    }
};