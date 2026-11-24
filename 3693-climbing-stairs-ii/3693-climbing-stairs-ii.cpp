
class Solution {
public:
    int solve(int i, vector<int>& costs,vector<int> &dp){

        if (i == 0) {
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int ans = INT_MAX;

        for (int jump = 1; jump <= 3; jump++) {
            if (i-jump >= 0) {
                int prev = solve(i - jump, costs,dp);

                int curr = prev+costs[i-1]+jump * jump;

                ans = min(ans, curr);
            }
        }
        return dp[i] = ans;
    }

    int climbStairs(int n, vector<int>& costs){
        vector<int> dp(n+1,-1);
        return solve(n, costs,dp);
    }
};
