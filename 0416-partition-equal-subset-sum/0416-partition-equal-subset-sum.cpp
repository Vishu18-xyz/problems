class Solution {
public:

    bool findsubset(int n , int target, vector<int> &nums,vector<vector<int>> &dp){
        if(target == 0){
            return 1;
        }

        if(n==0 || target<0){
            return 0;
        }

        if(dp[n][target] != -1){
            return dp[n][target];
        }

        return dp[n][target] = findsubset(n-1, target,nums,dp) || findsubset(n-1,target-nums[n-1],nums,dp);
    }

    bool canPartition(vector<int>& nums) {
        int target = 0;
        int n = nums.size();

        for(int i = 0; i<n; i++){
            target += nums[i];
        }

        if(target  % 2){
            return 0;
        }

        vector<vector<int>>dp(n+1,vector<int>(target/2+1,-1));

        return findsubset(n,target/2,nums,dp);
    }
};