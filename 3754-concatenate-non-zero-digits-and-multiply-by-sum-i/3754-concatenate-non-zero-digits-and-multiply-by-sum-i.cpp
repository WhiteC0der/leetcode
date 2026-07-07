class Solution {
public:
    long long sumAndMultiply(int n) {
        int num=0;
        int sum=0;
        while(n!=0){
            int d=n%10;
            if(d!=0) num=num*10+d;
            sum+=d;
            n/=10;
        }
         while(num!=0){
            int d=num%10;
            n=n*10+d;
            num/=10;
        }

        return 1LL * n *sum;
    }
};