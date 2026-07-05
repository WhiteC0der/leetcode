class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int ans=0;
        int mdr=0;
        vector<int> rg(nums.size());
        for(int i=0;i<nums.size();i++){
            string str= to_string(nums[i]);
            int mn = INT_MAX;
            int mx=INT_MIN;
            for(int j=0;j<str.length();j++){
                mn = min(mn,str[j]-'0');
                mx= max(mx,str[j]-'0');
            }
            rg[i]=mx-mn;
            mdr=max(mdr,rg[i]);
        }

        for(int i=0;i<nums.size();i++){
            if(rg[i] == mdr) ans+=nums[i];
        }

        return ans;
    }
};