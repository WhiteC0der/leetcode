class Solution {
public:
    int dp[501][501];
    int minDistance(string word1, string word2) {
        memset(dp,0,sizeof(dp));
        int m=word1.length();
        int n=word2.length();

        for(int i=0;i<=m ;i++){
            dp[i][0]=i;
        }

        for(int j=0;j<=n ;j++){
            dp[0][j]=j;
        }

        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=1 + min({
                        dp[i][j-1],
                        dp[i-1][j],
                        dp[i-1][j-1]
                    });
                }
            }
        }

        return dp[m][n]; 
    }
};