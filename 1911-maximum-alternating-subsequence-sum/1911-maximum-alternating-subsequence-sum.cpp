class Solution {
public:
    typedef long long ll;
    ll t[100001][2];

    ll solve(int idx,vector<int>& nums,bool flag){
        if(idx>=nums.size()){
            return 0;
        }
        if(t[idx][flag] != -1) return t[idx][flag];
        ll skip = solve(idx+1,nums,flag);
        int val = nums[idx];
        if(flag == false){
            val = -val;
        }
        ll take = solve(idx+1,nums,!flag) + val;

        return t[idx][flag] =  max(take,skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        memset(t,-1,sizeof(t));

        return solve(0,nums,true);
    }
};