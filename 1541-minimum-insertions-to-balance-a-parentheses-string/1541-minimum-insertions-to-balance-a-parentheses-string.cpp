class Solution {
public:
    int minInsertions(string s) {
        int cnt = 0;
        int temp = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                cnt += 2;
            } else {
                if (i + 1 < s.length() && s[i + 1] == ')') {
                    if (cnt == 0)
                        temp++;
                    else {
                        cnt -= 2;
                    }
                    i += 1;
                } else {
                    if (cnt == 0) {
                        temp += 2;
                    } else {
                        temp++;
                        cnt -= 2;
                    }
                }
            }
        }

        return cnt + temp;
    }
};