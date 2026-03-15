class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses);
        vector<int> vis(numCourses,false);
        int count=0;
        queue<int> que;
        for(auto& e: pre){
            adj[e[1]].push_back(e[0]);
            indeg[e[0]]++;
        }
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                que.push(i);
                vis[i]=true;
                count++;
            }
        }
        while(!que.empty()){
            int curr=que.front();
            que.pop();
            for(int e: adj[curr]){
                indeg[e]--;
                if(indeg[e]==0){
                    que.push(e);
                    vis[e]=true;
                    count++;
                }
            }
        }

        return count == numCourses;
    }
};