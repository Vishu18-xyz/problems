class Solution {
public:
    int ways(vector<int>&nums,int target, int n,vector<int> &dp){
        if(target == 0){
            return 1;
        }
        if(target<0){
            return 0;
        }

        if(dp[target] != -1){
            return dp[target];
        }

        int result = 0;

        for(int i = 0; i<n; i++){
            result += ways(nums,target-nums[i],n,dp);
        }

        return dp[target] = result;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>dp(target+1,-1);
        return ways(nums,target,n,dp);
    }
};