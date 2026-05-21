class Solution {
public:
    int minPairSum(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int n = nums.size();

        int left = 0;
        int right = n-1;

        int maxp = 0;

        while(left<right){
            int pair = nums[left]+nums[right];
            maxp = max(pair,maxp);
            left++;
            right--; 
        }

        return maxp;
    }
};