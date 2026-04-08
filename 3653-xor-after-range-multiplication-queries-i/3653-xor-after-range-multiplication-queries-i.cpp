class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        int mod = 1e9+7;
        for(int i=0;i<q.size();i++){
            int idx=q[i][0];
            while(idx<=q[i][1]){
                nums[idx]=(1LL *nums[idx]*q[i][3]) % mod;
                idx+=q[i][2];
            }
        }
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            ans= (ans ^ nums[i]);
        }

        return ans;
    }
};