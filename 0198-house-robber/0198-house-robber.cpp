class Solution {
public:

    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(3,0);

        dp[1] = nums[0];
        dp[2] = max(nums[0],nums[1]);

        for(int i = 2; i<n; i++){
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = max(nums[i]+dp[0],dp[1]);
        }

        return dp[2];
    }
};