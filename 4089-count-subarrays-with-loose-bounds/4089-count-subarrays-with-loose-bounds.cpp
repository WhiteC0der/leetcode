class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int temp=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=minK && nums[i]<=maxK){
                temp++;
            }else{
                cout<<temp<<endl;
                ans+=1LL*(temp)*(temp+1)/2;
                temp=0;
            }
        }
        ans+=1LL*temp*(temp+1)/2;

        return ans;
    }
};