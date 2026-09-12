class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>> mpp;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
        }
        for(auto& [key,value]: mpp){
            if(value.size() == 3 && value[1]-value[0] == value[2]-value[1]) ans++; 
        }

        return ans;
    }
};