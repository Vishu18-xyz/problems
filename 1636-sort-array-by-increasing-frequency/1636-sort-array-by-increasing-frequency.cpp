class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        
        for(int x : nums) {
            mp[x]++;
        }
        
        vector<pair<int,int>> v;
        
        for(auto x : mp) {
            v.push_back({x.second, -x.first});
        }
        
        sort(v.begin(), v.end());
        
        vector<int> ans;
        
        for(auto x : v) {
            int freq = x.first;
            int value = -x.second;
            
            for(int i = 0; i < freq; i++) {
                ans.push_back(value);
            }
        }
        
        return ans;
    }
};