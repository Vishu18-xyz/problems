class Solution {
public:
    
    int mincost(int n,vector<int> cost, vector<int>& dp){

        if(n==0){
            return 0;
        }

        if(n==1){
            return 0;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        return dp[n] = min(mincost(n-1,cost,dp)+cost[n-1],mincost(n-2,cost,dp)+cost[n-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);

        return mincost(n,cost,dp);
    }
};