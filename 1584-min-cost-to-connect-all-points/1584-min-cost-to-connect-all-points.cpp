class Solution {
public:
    typedef pair<int,int> P;
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int,vector<P>> adj;
        priority_queue<P,vector<P>,greater<P>> q;
        int n = points.size();
        vector<bool> vis(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dis= abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,dis});
                adj[j].push_back({i,dis});
            }
        }
        q.push({0,0});
        int sum=0;
        while(!q.empty()){
            auto [dis,node]= q.top();
            q.pop();
            if(vis[node]) continue;
            sum+=dis;
            vis[node]= true;
            for(auto &ed: adj[node]){
                if(!vis[ed.first]){
                    q.push({ed.second,ed.first});
                }
            }
        }

        return sum;
    }
};