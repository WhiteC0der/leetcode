class Solution {
public:
    int dp[1001][1001];
    
    int solve(int n,int m,string& s, string& t){
        if(n==0 || m==0){
            return m==0 ? 1 : 0; 
        }
        
        if(dp[n][m]!=-1) return dp[n][m];
        
        int take=0;
        if(s[n-1]==t[m-1]){
            take = solve(n-1,m-1,s,t);
        } 

        return dp[n][m] = take + solve(n-1,m,s,t);
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        int n=s.length();
        int m=t.length();

        return solve(n,m,s,t);
    }
};