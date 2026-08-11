class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=0,profit=0;
        int m = INT_MIN;
        for(int i=0;i<prices.size();i++){
            profit=prices[i]-prices[buy];
            m=max(m,profit);
            if(prices[buy]>prices[i]){
                buy=i;
            }
        }
        return m;  
    }
};