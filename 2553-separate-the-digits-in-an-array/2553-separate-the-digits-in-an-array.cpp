class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for(int i = 0; i<nums.size(); i++){
            int num = nums[i];

            vector<int> dig;

            while(num != 0){
                int digit = num%10;
                dig.push_back(digit);
                num = num/10;
            }
            reverse(dig.begin(),dig.end());
            for(int i = 0; i<dig.size(); i++){
                ans.push_back(dig[i]);
            }
        }

        return ans;
    }
};