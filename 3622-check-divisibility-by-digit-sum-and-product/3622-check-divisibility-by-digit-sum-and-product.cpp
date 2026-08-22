class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int prod=1;
        int temp=n;
        while(temp>0){
            int d=temp%10;
            sum+=d;
            prod*=d;
            temp/=10;
        }
        if(n%(sum+prod)) return false;
        return true;
    }
};