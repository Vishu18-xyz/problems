class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        int startValue = 0;
        int minPreSum = 0;
        for(int i=0; i<n; i++) {
            startValue += nums[i];
            minPreSum = min(minPreSum, startValue);
        }
        return 1-minPreSum;
    }
};