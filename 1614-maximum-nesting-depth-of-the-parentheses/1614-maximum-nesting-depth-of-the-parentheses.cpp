class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        stack<char> stk;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                stk.push('(');
                ans=max(ans,(int)stk.size());
            }else if(s[i]==')'){
                stk.pop();
            }
        }

        return ans;
    }
};