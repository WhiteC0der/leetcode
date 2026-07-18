class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mx=1;
        int mn=1000;
        for(int i=0;i<nums.size();i++){
            mx=max(mx,nums[i]);
            mn=min(mn,nums[i]);
        }

        return gcd(mx,mn);
    }
};