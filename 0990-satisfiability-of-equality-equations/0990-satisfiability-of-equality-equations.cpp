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

    void Union(int x,int y){
        int x_par= find(x);
        int y_par= find(y);
        if(x_par == y_par){
            return ;
        }
        if(rank[x_par]==rank[y_par]){
            par[x_par]=y_par;
            rank[y_par]++;
        }else if(rank[x_par]<rank[y_par]){
            par[x_par]=y_par;
        }else{
            par[y_par]=x_par;
        }
    }


    bool equationsPossible(vector<string>& equations) {
        par.resize(26);
        rank.resize(26,0);
        for(int i=0;i<26;i++){
            par[i]=i;
        }
        for(auto& st : equations){
            if(st[1]=='='){
                Union(st[0]-'a',st[3]-'a');
            }
        }
        for(auto& st : equations){
            if(st[1]=='!'){
                int first= find(st[0]-'a');
                int second= find(st[3]-'a');
                if(first==second) return false;
            }
        }

        return true;
    }
};