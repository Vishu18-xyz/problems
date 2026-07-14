class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();

        int size = n;
        int ans = 0;
        
        unordered_map<int,int> freq;
        priority_queue<pair<int,int>> pq;

        for(int i = 0; i<n; i++){
            freq[arr[i]]++;
        }

        for(auto it = freq.begin(); it != freq.end(); it++){
            pq.push({it->second,it->first});
        }

        while(size > n/2){
            int top = pq.top().second;
            int occur = pq.top().first;
            pq.pop();
            size = size-occur;
            ans++;
        }

        return ans;
        
    }
};