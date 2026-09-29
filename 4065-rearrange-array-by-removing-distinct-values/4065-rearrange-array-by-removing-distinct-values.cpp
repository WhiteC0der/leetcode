class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        int freq[101]={0};
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        bool flag=true;
        while(flag){
            flag=false;
            for(int i=0;i<=100;i++){
                if(freq[i]>0){
                    ans.push_back(i);
                    freq[i]--;
                    flag=true;
                }
            }
        }

        return ans;
    }
};