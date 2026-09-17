class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int prev = prices[0];
        int profit = 0;

        for(int i = 0; i<n; i++){
            if(prices[i] > prev){
                profit = max(profit, prices[i]-prev);
            }
            else{
                prev = prices[i];
            }
        }
        return profit;
    }
};