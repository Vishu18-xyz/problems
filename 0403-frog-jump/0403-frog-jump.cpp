
class Solution {
public:

    int dp[2001][2001];

    bool solve(vector<int>& stones, int i, int k) {

        if (i == stones.size() - 1)
            return true;

        if (dp[i][k] != -1)
            return dp[i][k];

        for (int j = i + 1; j < stones.size(); j++) {
            int jump = stones[j] - stones[i];

            if (jump >= k - 1 && jump <= k + 1) {
                if (solve(stones, j, jump))
                    return dp[i][k] = 1;
            }
        }

        return dp[i][k] = 0;
    }

    bool canCross(vector<int>& stones) {
        if (stones.size() > 1 && stones[1] != 1)
            return false;

        for (int i = 0; i < 2001; i++) {
            for (int j = 0; j < 2001; j++) {
                dp[i][j] = -1;
            }
        }

        return solve(stones, 0, 0);
    }
};

