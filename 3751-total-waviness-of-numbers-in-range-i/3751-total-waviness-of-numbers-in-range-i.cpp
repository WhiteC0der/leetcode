class Solution {
public:
    int countdig(int num){
        if(num<100) return 0;
        int count=0;
        int a,b,c;
        c=num%10;
        num/=10;
        b=num%10;
        num/=10;

        while(num>0){
            a=num%10;
            if((b>a && b>c) || (b<a && b<c)){
                count++;
            }
            c=b;
            b=a;
            num/=10;
        }

        return count;
    }
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int i=num1;i<=num2;i++){
            ans+=countdig(i);
        }

        return ans;
    }
};