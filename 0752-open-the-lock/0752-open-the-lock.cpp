class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadset(deadends.begin(),deadends.end());
        unordered_set<string> vis;
        queue<string> q;
        if (deadset.count("0000")) return -1;
        q.push("0000");
        vis.insert("0000");
        int level=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                string curr=q.front();
                q.pop();

                if(curr ==  target) return level;
                for(int i=0;i<curr.length();i++){
                    string temp=curr;
                    temp[i]= (((temp[i]-'0')+1)%10) + '0';
                    if(!vis.count(temp) && !deadset.count(temp)){
                        q.push(temp);
                        vis.insert(temp);
                    }
                }

                for(int i=0;i<curr.length();i++){
                    string temp=curr;
                    temp[i]= (((temp[i]-'0')-1 + 10)%10) + '0';
                    if(!vis.count(temp) && !deadset.count(temp)){
                        q.push(temp);
                        vis.insert(temp);
                    }
                }
            }
            level++;
        }

        return -1;
    }
};