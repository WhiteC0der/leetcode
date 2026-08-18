class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==n) return *max_element(nums.begin(),nums.end());
        unordered_map<int,int> mpp;
        for(int x : nums) {
            mpp[x]++;
        }
        if(k==1){
            int ans =-1;
            for(auto& ch : mpp){
                if(ch.second==1) ans=max(ans,ch.first);
            }
            return ans;
        }
        if(mpp[nums.front()] > 1  && mpp[nums.back()] > 1) return -1;
        if(mpp[nums.front()] >1) return nums.back();
        if(mpp[nums.back()] >1) return nums.front();

        return max(nums.front(),nums.back());
    }
};