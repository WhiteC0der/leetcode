class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s="";
        vector<int> ans;
        for(string ch: chunks){
            s+=ch;
        }
        unordered_map<string,int> mpp;
        string st="";
        for(int i=0;i<s.length();i++){
            if(islower(s[i])){
                st+=s[i];
            }else if(s[i]=='-' && i-1>=0 && i+1 <s.length() && islower(s[i-1]) && islower(s[i+1])){
                st+=s[i];
            }else{
                if(!st.empty()) mpp[st]++;
                st="";
            }
        }

         if (!st.empty()) {
            mpp[st]++;
        }

        for(int i=0;i<queries.size();i++){
            ans.push_back(mpp[queries[i]]);
        }

        return ans;
    }
};