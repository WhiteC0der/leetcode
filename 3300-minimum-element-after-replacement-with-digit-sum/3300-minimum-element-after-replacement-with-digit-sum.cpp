class Solution {
public:
    int digsum(int num){
        int sum=0;
        while(num>0){
            sum+=(num%10);
            num/=10;
        }

        return sum;
    }
    int minElement(vector<int>& nums) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            ans=min(ans,digsum(nums[i]));
        }

        return ans;
    }
};