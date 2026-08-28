class Solution {
public:
    void solve(int num,unordered_map<int,int> &mpp){
        while(num%2==0){
            mpp[2]++;
            num/=2;
        }
        for(int i=3;i*i<=num;i=i+2){
            while(num%i==0){
                mpp[i]++;
                num/=i;
            }
        }
        if(num>2) mpp[num]++;
    }
    void solvest(int num,unordered_map<int,int> &mpp){
        while(num%2==0){
            mpp[2]--;
            num/=2;
            if(mpp[2]==0) mpp.erase(2);
        }
        for(int i=3;i*i<=num;i=i+2){
            while(num%i==0){
                mpp[i]--;
                num/=i;
            if(mpp[i]==0) mpp.erase(i); 
            }
        }
        if(num>2){
            mpp[num]--;
            if(mpp[num]==0) mpp.erase(num); 
        } 
        
    }
    int longestSubarray(vector<int>& nums, int k) {
        int st=0;
        int end=0;
        int ans=0;
        unordered_map<int,int> mpp;
        while(end<nums.size()){
            solve(nums[end],mpp);
            while(mpp.size() > k){
                solvest(nums[st],mpp);
                st++;
            }
            ans=max(ans,end-st+1);
            end++;
        }

        return ans;
    }
};