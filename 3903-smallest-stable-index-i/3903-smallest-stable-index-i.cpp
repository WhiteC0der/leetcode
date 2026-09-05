class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> mx(nums.size());
        vector<int> mn(nums.size());
        int maxe=INT_MIN;
        int mine=INT_MAX;
        for(int i=0;i<nums.size();i++){
            maxe=max(nums[i],maxe);
            mx[i]=maxe;
        }
        for(int i=nums.size()-1;i>=0;i--){
            mine=min(nums[i],mine);
            mn[i]=mine;
        }

        for(int i=0;i<nums.size();i++){
            if(mx[i]-mn[i] <=k) return i;
        }

        return -1;
    }
};