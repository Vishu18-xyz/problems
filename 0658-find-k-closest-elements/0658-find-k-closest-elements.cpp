class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int n = arr.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> p;

        for(int i = 0; i<n; i++){
            p.push({abs(arr[i]-x),arr[i]});
        }

        for(int i = 0; i<k; i++){
            int diff = p.top().second;

            p.pop();
            ans.push_back(diff);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
    
};