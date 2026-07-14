class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b) {
                if (a[0] == b[0])
                    return a[1] > b[1]; 
                return a[0] < b[0];       
            });

        int n = intervals.size();
        int count = 0; 
        int maxend = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][1] <= maxend) {
                count++;
            } else {
                maxend = intervals[i][1];
            }
        }

        return n-count;
    }
};