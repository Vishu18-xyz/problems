class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m  =matrix[0].size();
        vector<int> rowmin(n);
        vector<int> colmax(m);

        for(int i = 0; i<n; i++){
            int minrow = INT_MAX;
           for(int j = 0; j<m; j++){
             minrow = min(minrow, matrix[i][j]);
           }

           rowmin[i] = minrow;
        }

        for(int i = 0; i<m; i++){
            int maxcol = INT_MIN;
           for(int j = 0; j<n; j++){
            maxcol = max(maxcol, matrix[j][i]);
           }

           colmax[i] = maxcol;
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == rowmin[i] && matrix[i][j] == colmax[j]){
                ans.push_back(matrix[i][j]);
            }
        }
    }
    return ans;
    }
    
};