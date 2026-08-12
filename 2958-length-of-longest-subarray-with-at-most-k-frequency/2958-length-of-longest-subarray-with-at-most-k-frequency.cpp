class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int st=0;
        int end=0;
        int n=nums.size();
        unordered_map<int,int> mpp;
        int ans=0;
        while(end<n){
            mpp[nums[end]]++;
            while(mpp[nums[end]]>k){
                mpp[nums[st]]--;
                if(mpp[nums[st]]==0) mpp.erase(mpp[nums[st]]);
                st++;
            }
            ans=max(ans,end-st+1);
            end++;
        }

        return ans;
    }
};