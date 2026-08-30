class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int count=0;
        unordered_set<int>seen,invalid;
        for (int i=0;i<nums.size();i++) {
            if (i==0||nums[i]!=nums[i-1]) {
                if(seen.count(nums[i])){
                    invalid.insert(nums[i]);
                }
                seen.insert(nums[i]);
            }
        }
        return seen.size()-invalid.size();
    }
};