class Solution {
public:
    long long dfs(int i,int j,vector<vector<int>>& grid){
        long long neighval = grid[i][j];
        grid[i][j]=0;
        int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        for(int k=0;k<4;k++){
            int newi=i+dir[k][0];
            int newj=j+dir[k][1];
            if(newi>=0 && newj >=0 && newi<grid.size() && newj<grid[0].size() && grid[newi][newj]!=0){
                neighval+=dfs(newi,newj,grid);
            }
        }

        return neighval;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=0){
                    long long val = dfs(i,j,grid);
                    if(val%k ==0) ans++;
                }
            }
        }

        return ans;
    }
};