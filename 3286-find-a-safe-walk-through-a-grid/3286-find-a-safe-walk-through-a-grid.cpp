class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> res(n,vector<int> (m,INT_MAX));
        deque<pair<int,int>> dq;
        dq.push_front({0,0});
        if(grid[0][0]==0) res[0][0]=0;
        else res[0][0]=1;
        vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
        while(!dq.empty()){
            auto [i,j] =dq.front();
            dq.pop_front();
            for(auto& dr: dir){
                int ni=i+dr[0];
                int nj=j+dr[1];
                if(ni>=0 && ni<n && nj>=0 && nj<m){
                    if(res[ni][nj] > res[i][j]+grid[ni][j]){
                        res[ni][nj] = res[i][j]+grid[ni][nj];
                        if(grid[ni][nj]==0){
                            dq.push_front({ni,nj});
                        }else{
                            dq.push_back({ni,nj});
                        }
                    }
                }
            }
            
        }

        return (health - res[n-1][m-1])>=1 ;
    }
};