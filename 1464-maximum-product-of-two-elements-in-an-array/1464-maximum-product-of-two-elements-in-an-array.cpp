class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int>p;
        int n = nums.size();

        for(int i = 0 ; i<n; i++){
            p.push(nums[i]);
        }
        int max1 = p.top();
        p.pop();
        int max2 = p.top();
        p.pop();

        return (max1-1)*(max2-1);
    }
};