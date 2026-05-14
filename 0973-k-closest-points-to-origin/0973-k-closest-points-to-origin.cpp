class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> p;

        for(int i = 0; i<n; i++){
            int dist = (points[i][0]*points[i][0]) + (points[i][1]*points[i][1]);
            p.push({dist,points[i]});
        }

        vector<vector<int>> ans;

        for(int i = 0; i<k; i++){
            ans.push_back(p.top().second);
            p.pop();
        }

        return ans;
    }
};