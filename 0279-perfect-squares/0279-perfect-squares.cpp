class Solution {
public:

    int solve(int n,int size,vector<vector<int>> &dp){
        if(n==0){
            return 0;
        }
        if(size==0 || n<0){
            return 1e6;
        }

        if(dp[size][n] != -1){
            return dp[size][n];
        }

        int square = size*size;

        return dp[size][n] =  min(1+solve(n-square,size,dp),solve(n,size-1,dp));
    }

    int numSquares(int n) {
        int size = sqrt(n);
        vector<vector<int>> dp(size+1,vector<int>(n+1,1e6));

        for(int i = 0; i<=size; i++){
            dp[i][0] = 0;
        }

        for(int i = 1; i<=size; i++){
            int square = i*i;
            for(int j = 1; j<=n; j++){
                if(j-square>=0){
                    dp[i][j] = min(dp[i-1][j],1+dp[i][j-square]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[size][n];
    }
};