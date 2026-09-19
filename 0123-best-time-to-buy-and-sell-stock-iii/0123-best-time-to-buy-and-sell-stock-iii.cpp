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
            return dp[index][buy][transaction] =  max(-prices[index]+maximumprofit(index+1,0,transaction,n,prices,dp),maximumprofit(index+1,1,transaction,n,prices,dp));
        }
        else{

            return dp[index][buy][transaction] =  max(prices[index]+maximumprofit(index+1,1,transaction-1,n,prices,dp),maximumprofit(index+1,0,transaction,n,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

        for(int i = n-1; i>=0;i--){
            for(int j =0; j<=1; j++){
                for(int k = 1; k<=2; k++){
                    if(j==1){
                        dp[i][j][k] = max(-prices[i]+dp[i+1][0][k],dp[i+1][1][k]);
                    }
                    else{
                        dp[i][j][k] = max(prices[i]+dp[i+1][1][k-1],dp[i+1][0][k]);
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};