class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int ans=INT_MAX;
        int m=ls.size();
        int n=ws.size();
        int minl=INT_MAX;
        int minw=INT_MAX;
        for(int i=0;i<m;i++){
            minl=min(minl,ls[i]+ld[i]);
        }

        for(int i=0;i<n;i++){
            minw=min(minw,ws[i]+wd[i]);
            ans= min(ans, max(minl,ws[i])+wd[i]);
        }

        for (int i = 0; i < m; i++)
            ans = min(ans, max(ls[i], minw) + ld[i]);

        return ans;
    }
};