
class Solution {
public:

    int dp[1001][4][1002][2];

    int solve(vector<int>& rating, int i, int count,
              int prev, int type) {

        if(count == 3) {
            return 1;
        }

        if(i >= rating.size()) {
            return 0;
        }

        if(dp[i][count][prev+1][type] != -1) {
            return dp[i][count][prev+1][type];
        }

        int skip = solve(rating, i+1, count, prev, type);

        int take = 0;
        
        if(prev == -1 ||
           (type == 0 && rating[i] > rating[prev]) ||
           (type == 1 && rating[i] < rating[prev])) {

            take = solve(rating, i+1, count+1, i, type);
        }

        return dp[i][count][prev+1][type] = take + skip;
    }

    int numTeams(vector<int>& rating) {

        memset(dp, -1, sizeof(dp));

        int increasing = solve(rating, 0, 0, -1, 0);

        int decreasing = solve(rating, 0, 0, -1, 1);

        return increasing + decreasing;
    }
};

