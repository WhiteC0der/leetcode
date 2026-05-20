class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> ans;
        vector<int> mpp(n+1,0);
        vector<int> mpp1(n+1,0);
        
        for(int i=0;i<n;i++){
            mpp[A[i]]++;
            mpp1[B[i]]++;
            int count=0;
            for(int i=0;i<=n;i++){
                if(mpp[i]!=0 && mpp[i]==mpp1[i]){
                    count++;
                }
            }        
            ans.push_back(count);
        }

        return ans;
    }
};