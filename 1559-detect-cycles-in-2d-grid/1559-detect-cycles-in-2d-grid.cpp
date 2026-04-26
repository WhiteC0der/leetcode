class Solution {
public:
    bool dfs(int i,int j,int pr,int pc,vector<vector<bool>> &vis,vector<vector<char>>& grid){
        vis[i][j]=true;
        int dir[4][2]={
            {1,0},{-1,0},{0,-1},{0,1}
        };
        for(int k=0;k<4;k++){
            int newi=i+dir[k][0];
            int newj=j+dir[k][1];
            if(newi>=0 && newi<grid.size()&&newj>=0 && newj<grid[0].size() && grid[newi][newj]==grid[i][j]){
                if(!vis[newi][newj]){
                    if(dfs(newi,newj,i,j,vis,grid)) return true;
                }else if(newi!=pr && newj!=pc ){
                   return true;
                }
            }
        }

        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool> (n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]){
                    if(dfs(i,j,-1,-1,vis,grid)) return true;
                }
            }
        }

        return false;
    }
};