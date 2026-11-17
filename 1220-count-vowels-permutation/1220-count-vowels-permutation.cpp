class Solution {
public:
    int mod = 1e9 + 7;

    int solve(int n, int prev, vector<vector<int>>& dp) {

        if(n == 0) {
            return 1;
        }

        if(dp[n][prev] != -1) {
            return dp[n][prev];
        }

        int ans = 0;

        for(int i = 0; i < 5; i++) {

            if((prev == 0 && i == 1) ||
               (prev == 1 && (i == 0 || i == 2)) ||
               (prev == 2 && (i == 0 || i == 1 || i == 3 || i == 4)) ||
               (prev == 3 && (i == 2 || i == 4)) ||
               (prev == 4 && i == 0)) {

                ans = (ans + solve(n-1, i, dp)) % mod;
            }
        }

        return dp[n][prev] = ans;
    }

    int countVowelPermutation(int n) {

        vector<vector<int>> dp(n+1, vector<int>(5, -1));

        int ans = 0;

        for(int i = 0; i < 5; i++) {
            ans = (ans + solve(n-1, i, dp)) % mod;
        }

        return ans;
    }
};