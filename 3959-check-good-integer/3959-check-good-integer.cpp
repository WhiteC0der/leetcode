class Solution {
public:
    bool checkGoodInteger(int n) {
        int sum=0;
        int sqsum=0;
        while(n!=0){
            sum+=(n%10);
            sqsum+=((n%10)*(n%10));
            n/=10;
        }

        return (sqsum-sum)>=50; 
    }
};