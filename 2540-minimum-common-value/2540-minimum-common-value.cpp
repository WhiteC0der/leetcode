class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
        for(int i=0;i<nums2.size();i++){
            st.insert(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            if(st.count(nums1[i])) return nums1[i];
        }

        return -1;
    }
};