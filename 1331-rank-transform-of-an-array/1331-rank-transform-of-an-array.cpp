class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr ;
        int n=arr.size();
        sort(temp.begin(),temp.end());
        unordered_map<int,int> mpp;
        int rank =1;
        for(int i=0;i<n;i++){
            if(!mpp.count(temp[i])){
                mpp[temp[i]]=rank;
                rank++;
            } 
        }

        for(int i=0;i<n;i++){
            arr[i]=mpp[arr[i]];
        }

        return arr;
    }
};