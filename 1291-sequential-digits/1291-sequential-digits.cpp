class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> arr;
        vector<int> ans;
        for(int i=1;i<=9;i++){
            int temp = 0 ;
            for(int j=i;j<=9;j++){
                temp=temp*10+j;
                arr.push_back(temp);
            }
        }

        for(int i=0;i<arr.size();i++){
            if(arr[i]>=low && arr[i]<=high){
                ans.push_back(arr[i]);
            }
        }

        sort(ans.begin(),ans.end());


        return ans;
    }
};