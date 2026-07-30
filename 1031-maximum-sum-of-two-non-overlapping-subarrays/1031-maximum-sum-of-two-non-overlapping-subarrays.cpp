class Solution {
public:
    int solve(int L,int M,vector<int>& prefix){
        int left =0;
        int right =0;
        int result =0;
        for(int mend=L+M-1;mend<prefix.size()-1;mend++){
            int lend=mend-M;
            int lst=lend-L+1;
            int send=mend-L;
            int sst=send-M+1;
            left = max(left, prefix[lend+1]-prefix[lst]);
            right = max(right,prefix[send+1]-prefix[sst]);
            result= max({result ,left + (prefix[mend+1] - prefix[lend+1]),right+(prefix[mend+1]-prefix[send+1])});
        }

        return result;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int L, int M) {
        int n=nums.size();
        vector<int> prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        
        return solve(L,M,prefix);
    }
};