class Solution {
public:
    vector<int> par;
    vector<int> rank;

    int find(int x){
        if(x==par[x]){
            return x;
        }

        return par[x]=find(par[x]);
    }

    bool Union(int x,int y){
        int x_par= find(x);
        int y_par= find(y);
        if(x_par == y_par){
            return false;
        }
        if(rank[x_par]==rank[y_par]){
            par[x_par]=y_par;
            rank[y_par]++;
        }else if(rank[x_par]<rank[y_par]){
            par[x_par]=y_par;
        }else{
            par[y_par]=x_par;
        }

        return true;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<(n-1)) return -1;
        int comp=n;
        par.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++){
            par[i]=i;
        }

        for(auto& itr: connections){
            if(Union(itr[0],itr[1])) comp--;
        }

        return comp-1;
    }
};