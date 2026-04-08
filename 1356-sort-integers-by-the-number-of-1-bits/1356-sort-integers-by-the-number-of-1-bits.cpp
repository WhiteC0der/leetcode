class Solution {
public:
    // static int count(int n){
    //     int cnt=0;
    //     while(n!=0){
    //         cnt++;
    //         n=n&n-1;
    //     }

    //     return cnt;
    // }

    static bool cmp(int a,int b){
        int ac=__builtin_popcount(a);
        int bc=__builtin_popcount(b);
        if(ac==bc){
            return a<b;
        }

        return ac < bc;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);

        return arr;
    }
};