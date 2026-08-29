class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> ans=nums;
        sort(ans.begin(),ans.end()); // O(nlogn)
        unordered_map<int,int> mpp;
        unordered_map<int,list<int>> mppo;
        int group=0;
        mppo[group].push_back(ans[0]);
        for(int i=1;i<ans.size();i++){ // O(n)
            if(abs(ans[i-1]-ans[i])>limit){
                group++;
            }   
            mppo[group].push_back(ans[i]);
            mpp[ans[i]]=group;
        } 
        for(int i=0;i<nums.size();i++){ // O(n)
            nums[i] = mppo[mpp[nums[i]]].front();
            mppo[mpp[nums[i]]].pop_front();//O(1)
        }

        return nums;
    }
};