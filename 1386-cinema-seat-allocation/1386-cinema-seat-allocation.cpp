class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        set<pair<int,int>> st;
        set<int> track;
        for(auto& ch : reservedSeats){
            st.insert({ch[0],ch[1]});
            track.insert(ch[0]);
        }
        int ans=0;
        for(int i : track){
            if(st.count({i,2})==0 && st.count({i,3})==0 && st.count({i,4})==0 && st.count({i,5})==0){
                st.insert({i,2});
                st.insert({i,3});
                st.insert({i,4});
                st.insert({i,5});
                ans++;
            }
            if(st.count({i,4})==0 && st.count({i,5})==0 && st.count({i,6})==0 && st.count({i,7})==0){
                st.insert({i,4});
                st.insert({i,5});
                st.insert({i,6});
                st.insert({i,7});
                ans++;
            }
            if(st.count({i,6})==0 && st.count({i,7})==0 && st.count({i,8})==0 && st.count({i,9})==0){
                st.insert({i,6});
                st.insert({i,7});
                st.insert({i,8});
                st.insert({i,9});
                ans++;
            }
        }

        return (n*2) - (track.size()*2) + ans;
    }
};