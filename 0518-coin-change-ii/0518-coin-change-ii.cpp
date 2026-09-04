class Solution {
public:

    int coinsum ( vector<int>&coins, int amount , int n , int index,vector<vector<int>> &dp){
        if(amount == 0){
            return 1;
        }
        if(index == n || amount<0){
            return 0;
        }

        if(dp[index][amount] != -1){
            return dp[index][amount];
        }

        return dp[index][amount] = coinsum(coins, amount, n, index +1,dp) + coinsum(coins, amount-coins[index], n , index,dp);
    }
int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));

        return coinsum(coins,amount,coins.size(),0,dp);
    }
};