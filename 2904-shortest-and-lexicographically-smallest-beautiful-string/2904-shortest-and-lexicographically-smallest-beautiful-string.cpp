class Solution {
public:
    string check(string a,string& b){
        for(int i=0;i<a.length();i++){
            if(a[i]!=b[i]){
                if(a[i]=='1') return b;
                else return a;
            }
        }

        return a;
    }
    string shortestBeautifulSubstring(string s, int k) {
        int ans=INT_MAX;
        int st=0;
        int end=0;
        int count=0;
        string str="";
        while(end<s.length()){
            if(s[end]=='1') count++;
            while(count>=k){       
                if(ans > end-st+1){
                    ans=end-st+1;
                    str=s.substr(st,end-st+1);
                }else if(ans == end-st+1){
                    str=check(s.substr(st,end-st+1),str);
                }
       
                if(s[st]=='1') count--;
                st++;
            }
       
           
            end++;
        }

        return str;
    }
};