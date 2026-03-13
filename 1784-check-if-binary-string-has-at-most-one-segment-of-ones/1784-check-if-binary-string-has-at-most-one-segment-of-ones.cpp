class Solution {
public:
    bool checkOnesSegment(string s) {
        int i=0;
        int n=s.length();
        while(i<n && s[i]=='1') i++;
        while(i<n && s[i]=='0') i++;

        return i==n ? true : false;
    }
};