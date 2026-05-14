class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted = nums;

        sort(sorted.begin(), sorted.end());
        vector<int> arr;

        for (int i = 1; i < n; i++) {
            arr.push_back(i);
        }

        arr.push_back(n - 1);
        return arr == sorted;
    }
};