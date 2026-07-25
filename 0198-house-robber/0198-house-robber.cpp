class Solution {
public:

    int moneyrob(int n, vector<int> nums,vector<int> & dp){
        
        if(n==0){
            return dp[n] = nums[0];
        }

        if(n==1){
            return dp[n] = max(nums[0],nums[1]);
        }

        if(dp[n] != -1){
            return max(nums[n]+dp[n-2],dp[n-1]);
        }


        return dp[n] = max(nums[n]+moneyrob(n-2,nums,dp),moneyrob(n-1,nums,dp));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n,-1);

        return moneyrob(n-1,nums,dp);
    }
};