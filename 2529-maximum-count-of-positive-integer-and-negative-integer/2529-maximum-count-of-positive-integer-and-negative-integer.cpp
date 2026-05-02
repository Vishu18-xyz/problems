class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;

        int neg  = 0;
        int pos = 0;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] < 0){
                neg++;
            }
            else if(nums[i] == 0){
                continue;
            }
            else{
                pos++;
            }
        }

        return max(pos,neg);
    }
};