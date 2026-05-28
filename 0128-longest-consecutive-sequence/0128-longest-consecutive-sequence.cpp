class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

    if (nums.size() == 0) {
        return 0;
    }

    int current = 1;
    int longest = 1;

    sort(nums.begin(), nums.end());

    for (int i = 1; i < nums.size(); i++) {

        if (nums[i] == nums[i - 1]) 
            continue;

        if (nums[i] == nums[i - 1] + 1) {
            current++;
        } 
        else {
            longest = max(longest, current);
            current = 1;
        }
    }
      return max(longest,current);
    }
};