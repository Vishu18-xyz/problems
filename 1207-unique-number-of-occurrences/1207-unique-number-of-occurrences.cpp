class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();

        vector<int>occurences(1001,0);

        unordered_map<int,int> freq;
        unordered_set<int>s;

        for(int i = 0; i<n; i++){
            freq[arr[i]]++;
        }

        for(auto x : freq){
           s.insert(x.second);
        }

        return freq.size() == s.size();
    }
};