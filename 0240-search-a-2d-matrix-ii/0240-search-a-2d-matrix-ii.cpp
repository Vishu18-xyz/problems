class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int  n =  matrix.size();
        int m = matrix[0].size();

        for(int i = 0; i<n; i++){
            int start = 0;
            int end = m-1;

            while(start<=end){

                int mid =  start + (end-start)/2;

                if(matrix[i][mid] == target){
                    return 1;
                }
                else if(matrix[i][mid] > target){
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }
        }
        return 0;
    }
};