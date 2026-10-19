class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1;

        for (int st = 0; st < n; st++) {
            int sum = 0;
            int rem = ((nums[st] % k) + k) % k;

            for (int end = st; end < n; end++) {
                int curr = ((nums[end] % k) + k) % k;

                if (curr != rem) {
                    break;
                }

                sum += nums[end];

                if (sum % k == rem) {
                    ans = max(ans, end - st + 1);
                }
            }
        }

        return ans;
    }
};