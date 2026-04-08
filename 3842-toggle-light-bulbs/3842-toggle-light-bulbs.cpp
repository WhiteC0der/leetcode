class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        set<int> st;
        for(auto& bulb: bulbs){
            if(st.count(bulb)){
                st.erase(bulb);
            }else{
                st.insert(bulb);
            }
        }
        vector<int> ans;
        for(auto& s: st){
            ans.push_back(s);
        }

        return ans;
    }
};