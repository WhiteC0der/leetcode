class Solution {
public:
 int dp[101][101];
    int solve(int i,int j,int m,int n,vector<vector<int>>& grid){
        if( i<0 || i>= m || j<0 || j>=n||grid[i][j]==1){
            return 0;
        }
        if(i==m-1 && j==n-1){
            return 1;
        }


        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j] = solve(i+1,j,m,n,grid) + solve(i,j+1,m,n,grid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,obstacleGrid.size(),obstacleGrid[0].size(),obstacleGrid);
    }
};