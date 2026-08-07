class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> seen;

        int n = nums.size();

        for(int i = 0; i<n; i++){
            seen.insert(nums[i]);
        }

        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int i = 0; i<n; i++){
            if(nums[i] > maxi){
                maxi = nums[i];
            }
            if(nums[i] < mini){
                mini = nums[i];
            }
        }

        vector<int> ans;

        for (int i = mini; i <= maxi; i++) {
            if (!seen.count(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};