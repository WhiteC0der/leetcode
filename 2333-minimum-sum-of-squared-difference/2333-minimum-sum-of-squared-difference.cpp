class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {  
        long long ans=0;
        vector<int> temp(100001);
        int n=nums1.size();
        int K=k1+k2;
        for(int i=0;i<n;i++){
            int val =  abs(nums1[i]-nums2[i]);
            temp[val]++;
        }

        for(int i=1e5;i>0 && K>0;i--){
            int cnt = min(K,temp[i]);
            temp[i]-=cnt;
            temp[i-1]+=cnt;
            K-=cnt;
        }

        for(int i=0;i<=1e5;i++){
            ans+=1LL*i*i*temp[i];
        }

        return ans;
    }
};