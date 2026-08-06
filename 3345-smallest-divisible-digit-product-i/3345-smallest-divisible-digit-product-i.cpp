class Solution {
public:
    int prod(int n){
        int pd=1;
        while(n!=0){
            pd*=(n%10);
            n/=10;
        }

        return pd;
    }
    int smallestNumber(int n, int t) {
        while(prod(n)%t!=0){
            n++;
        }

        return n;
    }
};