class Solution {
public:
    bool check(vector<int>& nums) {
        bool flag=true;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[(i+1)%nums.size()]){
                if(!flag) return false;
                flag=false;
            }
        }

        return true;
    }
};