class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        priority_queue<pair<int,int>> p;

        for(int i = 0; i<n; i++){
            freq[nums[i]]++;
        }

        for(auto it = freq.begin(); it != freq.end(); it++){
            p.push({it->second,it->first});
        }

        vector<int> ans;

        for(int i =0; i<k; i++){
            int maxfreq = p.top().second;
            p.pop();
            ans.push_back(maxfreq);
        }

        return ans;
    }
};