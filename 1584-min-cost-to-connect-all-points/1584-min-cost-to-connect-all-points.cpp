class Solution {
public:
    vector<int> par;
    vector<int> rank;
    
    int find(int a){
        if(par[a]==a){
            return a;
        }
        
        return par[a]=find(par[a]);
    }
    
    void Union(int a,int b){
        int par_a=find(a);
        int par_b=find(b);
        if(par_a != par_b){
              if(rank[par_a] == rank[par_b]){
            par[par_b] = par_a;
            rank[par_a]++;
        }
        else if(rank[par_a] > rank[par_b]){
            par[par_b] = par_a;
        }
        else{
            par[par_a] = par_b;
        }
        }
    }
  
    static bool compr(vector<int> &a,vector<int> &b){
        return a[2] < b[2];
    }
    
    int Kruskals(vector<vector<int>>& edges){
        int sum=0;
        for(auto &ed: edges){
            int u=ed[0];
            int v=ed[1];
            int wt=ed[2];
            if(find(u)!=find(v)){
                sum+=wt;
                Union(u,v);
            }
        }
        
        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        par.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) par[i]=i;
        vector<vector<int>> adj;
        vector<bool> vis(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dis= abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                adj.push_back({i,j,dis});
            }
        }
        
        auto compr = [&](vector<int> &a,vector<int> &b){
            return a[2] < b[2];
        };
        
        sort(adj.begin(),adj.end(),compr);


        return Kruskals(adj);
    }
};