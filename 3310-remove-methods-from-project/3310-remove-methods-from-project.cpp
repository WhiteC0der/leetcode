class Solution {
public:
    void dfs(int node,vector<bool>& vis,vector<vector<int>>& adj){
        vis[node]= true;
        for(auto& ed : adj[node]){
            if(!vis[ed]) dfs(ed,vis,adj);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n,false);
        vector<bool> visK(n,false);
        for(int i=0;i<invocations.size();i++){
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }
        dfs(k,visK,adj);
        for(int i=0;i<n;i++){
            if(!visK[i] && !vis[i]){
                dfs(i,vis,adj);
            }
        }
        vector<int> ans;
        vector<int> ans1;
        for(int i=0;i<n;i++){
            ans.push_back(i);
        }
        for(int i=0;i<n;i++){
            if(visK[i]==vis[i]){
                return ans;
            }
            if(visK[i]==false && vis[i]==true){
                ans1.push_back(i);
            }
        }

        return ans1;
    }
};