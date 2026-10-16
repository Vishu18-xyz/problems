class Solution {
public:
    
vector<int> sortArrayByParityII(vector<int>& nums) {
    int n = nums.size();
    int o = 1, e = 0;

    while (o < n && e < n) {
        if (nums[o] % 2 == 0) {
            if (nums[e] % 2 != 0) {
                swap(nums[o], nums[e]);
                o += 2;
                e += 2;
            } else {
                e += 2;
            }
        } else {
            o += 2;
        }
    }

    return nums;
}

};