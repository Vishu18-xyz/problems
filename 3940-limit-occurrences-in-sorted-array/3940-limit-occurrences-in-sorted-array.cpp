class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {

        vector<int> mp(1000, 0), ans;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            mp[nums[i]]++;
            if(mp[nums[i]] <= k) ans.push_back(nums[i]);
        }
        return ans;
    }
};