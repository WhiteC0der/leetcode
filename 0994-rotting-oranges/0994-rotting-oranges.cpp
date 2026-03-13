class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<pair<int,int>,int>> que;
        vector<vector<bool>> vis(m,vector<bool> (n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    que.push({{i,j},0});
                }
            }
        }
        while(!que.empty()){
            auto curr=que.front();
            que.pop();
            int i=curr.first.first;
            int j=curr.first.second;
            int time=curr.second;
            ans=max(ans,time);
            if(i-1>=0 && grid[i-1][j]==1 && !vis[i-1][j]){
                que.push({{i-1,j},time+1});
                vis[i-1][j]=true;
            }
            if(i+1<m && grid[i+1][j]==1 && !vis[i+1][j]){
                que.push({{i+1,j},time+1});
                vis[i+1][j]=true;
            }
            if(j-1>=0 && grid[i][j-1]==1 && !vis[i][j-1]){
                que.push({{i,j-1},time+1});
                vis[i][j-1]=true;
            }
            if(j+1<n && grid[i][j+1]==1 && !vis[i][j+1]){
                que.push({{i,j+1},time+1});
                vis[i][j+1]=true;
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    return -1;
                }
            }
        }

        return ans;
    }
};