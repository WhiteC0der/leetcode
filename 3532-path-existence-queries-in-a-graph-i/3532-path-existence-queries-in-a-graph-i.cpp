class Solution {
public:
    vector<int> par;
    vector<int> rank;
    int find(int idx){
        if(idx == par[idx]){
            return idx;
        }

        return par[idx] = find(par[idx]);
    }

    void Union(int a,int b){
        int par_a =find(a);
        int par_b=find(b);
        if(par_a == par_b) return;
        if(rank[par_a] > rank[par_b]){
            par[par_b]=par_a;
        }else if(rank[par_a] < rank[par_b]){
            par[par_a] = par_b;
        }else{
            par[par_a]=par_b;
            rank[par_b]++;
        }

        return ;
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        par.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) par[i]=i;
        for(int i=1;i<n;i++){
                if(abs(nums[i]-nums[i-1])<=maxDiff){
                    Union(i,i-1);
                }
        }
        vector<bool> ans(queries.size(),false);
        for(int i=0;i<queries.size();i++){
            if(par[queries[i][0]] == par[queries[i][1]]) ans[i]=true;
        }

        return ans;
    }
};