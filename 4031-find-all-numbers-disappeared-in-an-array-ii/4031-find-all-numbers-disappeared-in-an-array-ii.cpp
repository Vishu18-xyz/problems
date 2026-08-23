class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        unordered_map<int,int> mp;
        vector<int> miss;

        for(int i = 0; i<n ; i++){
            mp[nums[i]]++;
        }

        for(int i = lower; i<=upper; i++){
            if(mp.find(i) != mp.end()){
                continue;
            }
            else{
                miss.push_back(i);
            }
        }

        vector<vector<int>> ans;

        int i = 0;

        while (i < miss.size()) {
            int start = miss[i];

            while (i + 1 < miss.size() && miss[i] + 1 == miss[i + 1]) {
                i++;
            }

            int end = miss[i];

            ans.push_back({start, end});
            i++;
        }

        return ans;

    }
};