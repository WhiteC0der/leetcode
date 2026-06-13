class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(int i=0;i<words.size();i++){
            int temp=0;
            for(int j=0;j<words[i].length();j++){
                temp+=weights[words[i][j]-'a'];
            }
            ans.push_back((char) ('z'- ((temp%26))));
        }

        return ans;
    }
};