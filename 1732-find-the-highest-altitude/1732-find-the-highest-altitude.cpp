class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int>altitude(n+1,0);

        for(int i=1; i<=n; i++){
            altitude[i] = altitude[i-1] + gain[i-1];
        }

        int maxalt = INT_MIN;

        for(int i= 0; i<n+1; i++){
            if(altitude[i] > maxalt){
                maxalt = altitude[i];
            }
        }

        return maxalt;
    }
};