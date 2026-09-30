class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans(seq.size());
        int dept=0;
        for(int i=0;i<seq.size();i++){
            if(seq[i]==')'){
                dept++;
                ans[i] = (dept%2)==0 ? 0 : 1;
            }else{
                ans[i] = (dept%2)==0 ? 0 : 1;
                dept--;
            }
        }

        return ans;
    }
};