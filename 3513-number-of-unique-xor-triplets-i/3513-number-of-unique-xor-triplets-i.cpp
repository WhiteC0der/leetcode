class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size()==1) return 1;
        else if(nums.size()==2) return 2;
        
        return pow(2,(int)(log2(nums.size())+1));
    }
};
