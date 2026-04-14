class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankset(bank.begin(),bank.end());
        queue<string> q;
        unordered_set<string> vis;
        q.push(startGene);
        vis.insert(startGene);
        int level=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                string gen=q.front();
                if(gen == endGene) return level;
                q.pop();
                for(auto &ch: "ACGT"){
                    for(int i=0;i<gen.length();i++){
                        string neigh=gen;
                        neigh[i]=ch;
                        if(!vis.count(neigh) && bankset.count(neigh)){
                            q.push(neigh);
                            vis.insert(neigh);
                        }
                    }
                }
            }
            
            level++;
        }

        return -1;
    }
};