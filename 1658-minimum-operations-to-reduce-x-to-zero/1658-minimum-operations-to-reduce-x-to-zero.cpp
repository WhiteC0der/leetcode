class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int target = sum-x;
        int st=0;
        int end=0;
        int maxlen=-1;
        int curr=0;
        if(x > sum) return -1;
        if(sum == x) return nums.size();
        while(end<nums.size()){
            curr+=nums[end];
            while(curr >  target){
                curr-=nums[st];
                st++;
            }
            if(curr==target){
                maxlen=max(maxlen,end-st+1);
            }
            end++;
        }

        return  maxlen== -1 ? -1 : nums.size()-maxlen;
    }
};