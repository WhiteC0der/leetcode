class Solution {
public:
    const int mod= 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        long long odd = 0, even = 0;
        long long ans = 0;
        
        for (int x : arr) {
            long long newOdd, newEven;

            if (x % 2) {
                newOdd = even + 1;
                newEven = odd;
            }
            else {
                newOdd = odd;
                newEven = even + 1;
            }

            odd = newOdd;
            even = newEven;

            ans = (ans + odd) % mod;
        }

        return ans;
    }
};