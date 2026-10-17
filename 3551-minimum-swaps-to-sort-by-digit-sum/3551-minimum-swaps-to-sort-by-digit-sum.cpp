class Solution {
public:
    int digitSum(int x){
        int sum=0;
        while(x!=0){
            sum+=(x%10);
            x/=10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int ans=0;
        vector<int> temp(nums.begin(),nums.end());
        unordered_map<int,int> mpp;
        auto cmp = [&](int a,int b){
            int vala=digitSum(a);
            int valb=digitSum(b);
            if(vala == valb){
                return a < b;
            }

            return vala < valb;
        };

        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]=i;
        }

        sort(temp.begin(),temp.end(),cmp);
        
        for(int i=0;i<nums.size();i++){
            int tar = temp[i];
            int val = nums[i];
            if(tar== val) continue;

            int idx =mpp[tar];
            mpp[tar] = i;
            mpp[nums[i]] =idx;
            nums[idx]=nums[i];
            nums[i] = tar;
            ans++;
        }

        return ans;
    }
};