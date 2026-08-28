class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        unordered_set<int> s(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int st=-1;
        int end=-1;
        for(int i=lower;i<=upper;i++){
            if(s.count(i)==0){
                if(st==-1){
                    st=i;
                    end=i;
                }else{
                    end=i;
                }
            }else{
                if(st!=-1){
                    ans.push_back({st,end});
                    st=-1;
                    end=-1;
                }
            }
        }
        if(st!=-1) ans.push_back({st,end});

        return ans;
    }
};