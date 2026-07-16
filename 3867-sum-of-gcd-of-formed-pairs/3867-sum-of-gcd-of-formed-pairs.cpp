class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx=INT_MIN;
        int n=nums.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            nums[i]=gcd(mx,nums[i]);
        }
        sort(nums.begin(),nums.end());
        int st=0;
        int end=n-1;
        while(st<end){
            ans+=gcd(nums[st],nums[end]);
            st++;
            end--;
        }

        return ans;
    }
};