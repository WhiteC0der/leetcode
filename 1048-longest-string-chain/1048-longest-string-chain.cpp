class Solution {
public:
    int dp[1001][1001];
    int n;
    bool ispred(string& a,string& b){
        int n=a.length();
        int m=b.length();
        if(m<n || m-n!=1){
            return false;
        }
        int i=0;
        int j=0;
        while(i < n && j < m){
            if(a[i]==b[j]){
                i++;
                j++;
            }else{
                j++;
            }
        }

        return i==n;
    }
    int solve(int idx,int prev,vector<string>& words){
        if(idx==n){
            return 0;
        }

        if(prev!=-1 && dp[idx][prev]!=-1) return dp[idx][prev];
        
        int take=0;
        if(prev==-1 || ispred(words[prev],words[idx])){
            take = 1 + solve(idx+1,idx,words);
        }

        if(prev==-1) return  max(take,solve(idx+1,prev,words));

        return  dp[idx][prev] = max(take,solve(idx+1,prev,words));
    }

    static bool cmp(string& a,string& b){
        return a.length() < b.length();
    }

    int longestStrChain(vector<string>& words) {
        memset(dp,-1,sizeof(dp));
        n=words.size();
        sort(words.begin(),words.end(),cmp);

        return solve(0,-1,words);
    }
};