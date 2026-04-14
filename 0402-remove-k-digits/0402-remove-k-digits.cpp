class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stk;
        for(auto &ch: num){
            while(!stk.empty() && k>0 && stk.top()-'0'> ch-'0'){
                stk.pop();
                k--;
            }
            stk.push(ch); 
        }
        
        if(stk.empty()) return "0";

        while(k>0){
            stk.pop();
            k--;
        }
        string res="";
        
        while(!stk.empty()){
            res+=stk.top();
            stk.pop();
        }

        while(res.size()!=0&&res.back()=='0'){
            res.pop_back();
        }

        if(res.size()==0) return "0";
        reverse(res.begin(),res.end());
        return res;


    }
};