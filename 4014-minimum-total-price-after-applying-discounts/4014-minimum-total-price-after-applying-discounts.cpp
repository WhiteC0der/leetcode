class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n=prices.size();
        int m=discounts.size();
        double ans=0;
        sort(prices.begin(),prices.end(),greater<int>());
        sort(discounts.begin(),discounts.end(),greater<int>());
        int i=0;
        int j=0;
        while(i<n&&j<m){
            ans = ans + (1.0 * prices[i]*(100-discounts[j]))/100;
            i++;
            j++;
        }
      
        while(i<n){
            ans+=prices[i++];
        } 

        return ans;
    }
};