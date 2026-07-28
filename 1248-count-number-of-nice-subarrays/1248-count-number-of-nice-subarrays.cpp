class Solution {
public:
    int atmost(vector<int>& nums, int goal) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        int sum = 0;
        int count = 0;

        while (r < n) {
            sum += nums[r] % 2;
            if (goal < 0)
                return 0;
            while (sum > goal) {
                sum -= nums[l] % 2;
                l++;
            }

            count += (r - l + 1);
            r++;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};