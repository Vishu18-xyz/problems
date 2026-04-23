class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxd = 0;
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                if(colors[i] != colors[j]){
                    maxd = max(abs(i-j),maxd);
                }
            }
        }

        return maxd;
    }
};