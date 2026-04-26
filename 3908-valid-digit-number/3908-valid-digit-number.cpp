class Solution {
public:
    bool validDigit(int n, int x) {
        bool ans = false;
        while(n >9){
            if(n%10 == x) ans= true;
            n/=10;
        }

        return (ans && n!=x);
    }
};