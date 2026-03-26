class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(m==0 || n==0 || grid[0][0]==1) return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=1;
        int count=0;
        int diri[]={0,0,-1,+1,+1,-1,+1,-1};
        int dirj[]={-1,+1,0,0,+1,-1,-1,+1};
        while(!q.empty()){
            int size=q.size();
            count++;
            while(size--){
                auto &curr= q.front();
                int i=curr.first;
                int j=curr.second;
                
                q.pop();

                if(i==m-1 && j==n-1){
                    return count;
                }

                for(int k=0;k<8;k++){
                    int newi=i+diri[k]; 
                    int newj=j+dirj[k];
                    if(newi>=0 && newi<m &&newj>=0 && newj<n && grid[newi][newj]==0){
                        grid[newi][newj]=1;
                        q.push({newi,newj});
                    } 
                }
                
            }
            
        }

        return -1;
    }
};