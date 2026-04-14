class Solution {
public:
    struct lamda{
        bool operator()(pair<char,int> a,pair<char,int> b){
            if(a.second < b.second ){
                return true;
            }            
        return false;
        }
    };
    string frequencySort(string s) {
        unordered_map<char,int> mpp;
        priority_queue<pair<char,int>,vector<pair<char,int>>,lamda> pq; 
        for(auto& ch: s){
            mpp[ch]++;
        }
        for(auto& itr: mpp){
            pq.push({itr.first,itr.second});
        }
        string res="";
        while(!pq.empty()){
            pair<char,int> p=pq.top();
            res+=string(p.second,p.first);
            pq.pop();
        }
        return res;
    }
};