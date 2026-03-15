class Solution {
public:
    char findKthBit(int n, int k) {
        string s="0";
        for(int i=1;i<n;i++){
            s+="1";
            int j=s.length()-2;
            while(j>=0){
                if(s[j]=='0')s+="1";
                else s+="0";
                j--;
            }
        }

        return s[k-1];
    }
};