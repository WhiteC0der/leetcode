class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int left=0;
        int right=0;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        for(int i=0;i<n;i++){
            right=sum-left-nums[i];
            ans[i]=abs(left-right);
            left+=nums[i];
        }

        return ans;
    }
};