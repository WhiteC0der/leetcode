class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            double x=0;
            double y=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]%2==1){
                    y++;
                }else{
                    x++;
                }
                if((y>0) && (x/y) <= (1.0*a/b)) ans++;
            }
        }

        return ans;
    }
};