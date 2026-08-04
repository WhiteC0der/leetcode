class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> freq(101,0);
        vector<int> ans;
        int mn = 101;
        int mx = 0 ;
        for(int i=0;i<nums.size();i++){
            mn=min(mn,nums[i]);
            mx=max(mx,nums[i]);
            freq[nums[i]]=1;
        }

        for(int i=mn;i<=mx;i++){
            if(freq[i]==0) ans.push_back(i);
        }

        return ans;
    }
};