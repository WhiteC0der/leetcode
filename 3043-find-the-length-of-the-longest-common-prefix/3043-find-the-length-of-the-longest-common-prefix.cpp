class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> st;
        int ans=0;
        for(int i=0;i<arr1.size();i++){
            string temp=to_string(arr1[i]);
            for(int j=1;j<=temp.length();j++){
                st.insert(temp.substr(0,j));
            }
        }

        for(int i=0;i<arr2.size();i++){
            string temp=to_string(arr2[i]);
            for(int j=temp.length();j>=1;j--){
                if(st.count(temp.substr(0,j))){
                    ans=max(ans,j);
                    break;
                }
            }
        }

        return ans;
    }
};