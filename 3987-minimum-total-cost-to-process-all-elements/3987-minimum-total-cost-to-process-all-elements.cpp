class Solution {
public:
    const int mod=1e9+7;
    int minimumCost(vector<int>& nums, int k) {
        long long res=k;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(res>=nums[i]){
                res-=nums[i];
            }else{
                long long temp =(nums[i] - res + k - 1) / k;
                res = res+(k*temp)-nums[i];
                ans+=temp;
            }
        }

        long long total = (1LL * (ans % mod )* ((ans + 1)% mod)) / 2;
        return total % mod;
    }
};