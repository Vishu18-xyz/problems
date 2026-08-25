class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        set<int> s;

        for(int i = 0; i<n; i++){
            s.insert(nums[i]);
        }

        int num = k;
        while(s.count(num)){
            num += k;
        }

        return num;
    }
};