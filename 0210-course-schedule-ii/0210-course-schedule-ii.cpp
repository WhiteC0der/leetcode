class Solution {
public:
    bool dfs(int V,vector<vector<int>>& adj,vector<bool>& vis,vector<bool>& inrec,stack<int>& stk){
        vis[V]=true;
        inrec[V]=true;
        for(auto& e: adj[V]){
            if(!vis[e]){
                if(dfs(e,adj,vis,inrec,stk)) return true;
            }else if(inrec[e]){
                return true;
            }
        }
        inrec[V]=false;
        stk.push(V);

        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> adj(numCourses);
        vector<bool> vis(numCourses);
        vector<bool> inrec(numCourses);
        vector<int> ans;
        stack<int> stk;

        for(auto& e: pre){
            adj[e[1]].push_back(e[0]);
        }

        for(int i=0;i<numCourses;i++){
            if(!vis[i] && dfs(i,adj,vis,inrec,stk)){
                return {};
            }
        }

        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }

        return ans;
    }
};