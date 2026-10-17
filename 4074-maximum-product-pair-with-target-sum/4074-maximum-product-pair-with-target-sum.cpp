class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int ansi=-1;
        int ansj=-1;
        int mx=INT_MIN;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(nums[i] < nums[j] && (nums[i]+nums[j])==target){
                    if(nums[i]*nums[j] > mx){
                        mx=nums[i]*nums[j];
                        ansi=i;
                        ansj=j;
                    }
                }
            }
        }

        return {ansj,ansi};
    }
};