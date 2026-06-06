class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int,int> m;
        m[0] = 1;
        int prefix = 0; 
        int count = 0;

        for(int  i = 0; i<n;  i++){
            prefix += nums[i];

            if(m.count(prefix-goal)){
                count += m[prefix - goal];
            }
            m[prefix] ++;
        }

        return count;
    }
};