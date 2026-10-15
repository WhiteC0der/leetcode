class Solution {
public:
    int sumCounts(vector<int>& nums) {
        vector<int> freq(101,0);
        int ans=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            freq.assign(101,0);
            cnt=0;
            for(int j=i;j<nums.size();j++){
                if(freq[nums[j]]==0){
                    freq[nums[j]]++;
                    cnt++;
                }
                cout<<freq[nums[i]];
                cout<<cnt<<endl;
                ans+=(cnt*cnt);
            }
        }

        return ans;
    }
};