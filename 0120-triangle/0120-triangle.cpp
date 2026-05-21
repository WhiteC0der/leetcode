class Solution {
public:
    int dp[201][201];
    int solve(int i,int j,vector<vector<int>>& triangle){
        if(i==triangle.size()-1){
            return triangle[i][j];
        }

        if(i>=triangle.size() || j>=triangle[i].size()){
            return INT_MAX;
        }

        if(dp[i][j]!=1e5){
            return dp[i][j];
        }

        return dp[i][j] = triangle[i][j]+min(solve(i+1,j,triangle),solve(i+1,j+1,triangle));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = 0; i < 201; i++) {
    for(int j = 0; j < 201; j++) {
        dp[i][j] = 100000;
    }
}
        return solve(0,0,triangle);
    }
};