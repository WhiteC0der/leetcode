class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x;
        int y;
        int ans=INT_MAX;
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(i==j) continue;
                int temp=0;
                for(int l=0;l<nums.size();l++){
                    int inc=0;
                    int dec=0;
                    int chk=nums[l] % k;
                    if(l%2==0){
                        inc= (i-chk+k)%k;
                        dec= (chk-i+k)%k;
                        temp+=min(inc,dec);
                    }else{
                        inc= (j-chk+k)%k;
                        dec= (chk-j+k)%k;

                        temp+=min(inc,dec);
                    }
                }
                ans=min(ans,temp);
            }
        }

        return ans;
    }
};