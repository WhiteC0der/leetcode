class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n= nums.size();
        int st=0;
        int end=n-1;
        int mid;
        while(st<=end){
            mid= st +(end-st)/2;
            if( mid>0 && mid < n-1 && nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                break;
            }else if(nums[mid] < nums[mid+1]){
                st=mid+1;
            }else{
                end = mid-1;
            }
        } 
        long long sum=0;
        long long sum1=0;
        for(int i=0;i<=mid;i++){
            sum+=nums[i];
        }
        for(int i=mid;i<n;i++){
            sum1+=nums[i];
        }

        if(sum > sum1 ) return 0;
        else if( sum <sum1) return 1;
        return -1;
    }
};