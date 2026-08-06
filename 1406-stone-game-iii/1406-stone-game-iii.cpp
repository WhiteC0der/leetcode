class Solution {
public:
    int n;
    int dp[50001][2];
    int solve(int idx,int turn,vector<int>& prefix){
        if(idx>=n){
            return 0;
        }
        if(dp[idx][turn]!=-1) return dp[idx][turn];
        int mx = INT_MIN; 
        int mn=INT_MAX;
        for(int i=1;i<=3 && idx +i<=n ;i++){
            if(turn  == 1){
                mx = max(mx , prefix[idx+i]-prefix[idx] + solve(idx+i,0,prefix));
            }else{
                mn= min(mn, solve(idx+i,1,prefix));
            }
        }

        return dp[idx][turn] = turn  == 1 ? mx : mn;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        memset(dp,-1,sizeof(dp));
        vector<int> prefix(n+1,0);
        int sum = accumulate(stoneValue.begin(),stoneValue.end(),0);
        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+stoneValue[i-1];
        }
        int alice = solve(0,1,prefix);
        int bob  = sum - alice;
        
        if(alice > bob) return "Alice";
        if(alice < bob) return "Bob";
        return "Tie";
    }
};