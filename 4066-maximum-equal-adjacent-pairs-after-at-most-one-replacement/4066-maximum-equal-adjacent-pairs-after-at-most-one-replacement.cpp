class Solution {
public:
    struct pair_hash {
    size_t operator()(const pair<int,int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};
    int maxEqualAdjacentPairs(vector<int>& nums) {
        unordered_map<pair<int,int>,int,pair_hash> mpp;
        int ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) ans++;
            else{
                mpp[{nums[i-1],nums[i]}]++;
            }
        }
        int mx=0;
        for(auto&[key,val] : mpp){
            int temp=val;
            if(mpp.find({key.second,key.first})!=mpp.end()){
                temp+=mpp[{key.second,key.first}];
            }
            mx=max(mx,temp);
        }

        return ans+mx;
    }
};