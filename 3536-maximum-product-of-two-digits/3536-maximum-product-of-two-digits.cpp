class Solution {
public:
    int maxProduct(int n) {
        int m1=0;
        int m2=0;
        while(n!=0){
            if(m1<n%10){
                m2=m1;
                m1=n%10;
            }else if(m2<n%10){
                m2=n%10;
            }
            n/=10;
        }

        return m1*m2;
    }
};