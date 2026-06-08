class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int zeroes = 0;
        int start  = 0;
        int end = 0; 
        int count = 0; 

        while(end<n){
            if(nums[end] == 0){
                zeroes++;
            }
            while(zeroes>k && end<n){
                if(nums[start] == 0){
                    zeroes--;
                }
                start++;
            }
            count = max(count,end-start+1);
            end++;
        }

        return count;
    }
};