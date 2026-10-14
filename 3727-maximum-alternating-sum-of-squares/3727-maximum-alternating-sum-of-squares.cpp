class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans=0;
        auto cmp = [&](int a,int b){
            return abs(a)>abs(b);
        };
        sort(nums.begin(),nums.end(),cmp);
        int st=0;
        int end=nums.size()-1;
        while(st<end){
            ans+=(nums[st]*nums[st]);
            ans-=(nums[end]*nums[end]);
            st++;
            end--;
        }
        if(st==end) ans+=(nums[st]*nums[st]);

        return ans;
    }
};