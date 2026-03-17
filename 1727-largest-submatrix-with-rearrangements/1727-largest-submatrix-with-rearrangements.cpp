class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int ans=0;
        vector<vector<int>> adj(m,vector<int> (n));
        
        for(int j=0;j<n;j++){
            int sum=0;
            for(int i=0;i<m;i++){
                if(mat[i][j]==1) sum++;
                else sum=0;
                adj[i][j]=sum;
            }
        }

        for(int i=0;i<m;i++){
            sort(adj[i].begin(),adj[i].end());
            int j=n-1;
             for (int j = 0; j < n; j++) {
                int height = adj[i][j];
                int width = n - j;
                ans = max(ans, height * width);
            }
        }

        return ans;
    }
};