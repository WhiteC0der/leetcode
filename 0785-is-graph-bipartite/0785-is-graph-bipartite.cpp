class Solution {
public:
    bool dfs(int ver,vector<vector<int>>& graph,vector<int>& color,int currcol){
        color[ver]=currcol;
        for(auto& e: graph[ver]){
            if(color[e]==-1){
                if(!dfs(e,graph,color,1-currcol)) return false;
            }
            if(color[e]==currcol){
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                if(!dfs(i,graph,color,0)) return false;
            }
        }

        return true;
    }
};