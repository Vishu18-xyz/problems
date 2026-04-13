class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int maxradius = 0;
        int n = houses.size();
        int m = heaters.size();

        for(int i = 0; i<n; i++){
            int mindist = INT_MAX;
            for(int j = 0; j<m; j++){
               int dist = abs(houses[i]-heaters[j]);
                mindist = min(mindist,dist);
            }

            maxradius = max(maxradius,mindist);
        }

        return maxradius;
    }
};