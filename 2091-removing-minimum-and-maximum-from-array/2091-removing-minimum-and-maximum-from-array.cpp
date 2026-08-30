class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn=INT_MAX;
        int posmin=-1;
        int mx=INT_MIN;
        int posmax=-1;
        for(int i=0;i<nums.size();i++){
            if(mn > nums[i] ){
                mn=nums[i];
                posmin=i;
            }
            if(mx < nums[i]){
                mx=nums[i];
                posmax=i;
            }
        }
        int left = 1 + max(posmin,posmax);
        int right = nums.size() - min(posmin,posmax);
        int mix = 1 + min(posmin,posmax) + nums.size() - max(posmin,posmax); 
        
        return min({left,right,mix});
    }
};