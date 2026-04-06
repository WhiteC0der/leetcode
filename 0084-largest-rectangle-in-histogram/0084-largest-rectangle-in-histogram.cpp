class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> right(n, 0);
        stack<int> stk;
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[i] <= heights[stk.top()]) {
                stk.pop();
            }
            right[i] = stk.empty() ? n  : stk.top();
            stk.push(i);
        }
        while (!stk.empty()) {
            stk.pop();
        }
        vector<int> left(n, 0);
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[i] <= heights[stk.top()]) {
                stk.pop();
            }
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
        int maxArea = -1;
        for (int i = 0; i < n; i++) {
            int area = heights[i] * (right[i] - left[i] - 1);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};