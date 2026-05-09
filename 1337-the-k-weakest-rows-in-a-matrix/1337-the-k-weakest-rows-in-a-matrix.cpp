class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> h;

        for(int i = 0; i<n; i++){
            int soldier = 0;
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 1){
                    soldier++;
                }
            }
            h.push({soldier,i});
        }
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(h.top().second);
            h.pop();
        }
        return ans;
    }
};