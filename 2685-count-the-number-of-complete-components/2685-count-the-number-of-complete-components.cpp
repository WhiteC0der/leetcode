class Solution {
public:
    void dfs(int idx,vector<vector<int>> &adj,vector<bool> &vis,vector<int> &temp){
        vis[idx]=true;
        temp.push_back(idx);
        for(auto &neg : adj[idx]){
            if(!vis[neg]){
                dfs(neg,adj,vis,temp);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        int ans=0;
        vector<bool> vis(n,false);
        for(auto &ed: edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }

        vector<int> temp;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                temp.clear();
                dfs(i,adj,vis,temp);
                int j;
                for(j=0;j<temp.size();j++){
                    if(adj[temp[j]].size()!=temp.size()-1){
                        break;
                    }
                }
                if(j==temp.size()) ans++;
            }
        }

        return ans;
    }
};