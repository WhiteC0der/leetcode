class Solution {
public:
    int find(int x,vector<int>& freq){
        int i=freq.size()-1;
        while(i>=0){
            if(freq[i]<x){
                x-=freq[i];
            }else{
                return -i;
            } 
            i--;
        }

        return 0;
    }
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int st=0;
        int end=0;
        vector<int> freq(51,0);
        vector<int> ans;

        while(end<nums.size()){
            if(nums[end]<0) freq[-nums[end]]++;
            if(end-st+1 <k){
                end++;
            }else if(end-st+1 == k){
                ans.push_back(find(x,freq));
                if(nums[st]<0) freq[-nums[st]]--;
                st++;
                end++;
            }
        }

        return ans;
    }
};