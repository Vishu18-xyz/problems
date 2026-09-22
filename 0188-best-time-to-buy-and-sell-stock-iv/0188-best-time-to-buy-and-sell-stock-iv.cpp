class Solution {
public:
    int maximumprofit(int index, int buy, int transaction , int n, vector<int> prices,vector<vector<vector<int>>> &dp){

        if(index == n || transaction == 0){
            return 0;
        }

        if(dp[index][buy][transaction] != -1){
            return dp[index][buy][transaction];
        }


        if(buy){
            return dp[index][buy][transaction] = max(-prices[index]+maximumprofit(index+1,0,transaction,n,prices,dp),maximumprofit(index+1,1,transaction,n,prices,dp));
        }
        else{
            return dp[index][buy][transaction] = max(prices[index]+maximumprofit(index+1,1,transaction-1,n,prices,dp),maximumprofit(index+1,0,transaction,n,prices,dp));
        }
    }
    int maxProfit(int k,vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));

        return maximumprofit(0,1,k,n,prices,dp);
    }
};