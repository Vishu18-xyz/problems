class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> leftsum(nums.size(),0);
        vector<int> rightsum(nums.size(),0);
        vector<int> ans(nums.size(), 0);

        leftsum[0] = 0;

        for(int i = 1; i<nums.size(); i++){
            leftsum[i]= leftsum[i-1]+nums[i-1];
        }

        rightsum[nums.size()-1] = 0;

        for(int i=nums.size()-2; i>=0; i--){
            rightsum[i] = rightsum[i+1] + nums[i+1];
        }

        for(int index = 0; index<nums.size(); index++){
            ans[index] = abs(leftsum[index] - rightsum[index]);
        }

        return ans;
    }
};