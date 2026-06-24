class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> nums = arr;
        sort(nums.begin(), nums.end());

        unordered_map<int, int> mp;
        int rank = 1;
        for(int num : nums) {
            if(mp.find(num) == mp.end()) {
                mp[num] = rank++;
            }
        }

        vector<int> ans;
        for(int x : arr) {
            ans.push_back(mp[x]);
        }

        return ans;
    }
};