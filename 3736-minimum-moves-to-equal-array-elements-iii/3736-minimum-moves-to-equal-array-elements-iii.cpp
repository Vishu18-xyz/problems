class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int moves = 0;
        int max = INT_MIN;

        for(int i = 0; i<n; i++){
            if(nums[i] > max){
                max = nums[i];
            }
        }

        for(int i = 0; i<n; i++){
           int diff = abs(nums[i] - max);
           moves+=diff; 
        }

        return moves;
    }
};