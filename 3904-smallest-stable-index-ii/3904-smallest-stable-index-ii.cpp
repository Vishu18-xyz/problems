class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n  = nums.size();
        int ans = -1;
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);

        prefix[0] = nums[0];

        for(int i = 1; i<n; i++){
            prefix[i] = max(prefix[i-1],nums[i]);
        }

        suffix[n-1] = nums[n-1];

        for(int i = n-2; i>=0; i--){
            suffix[i] = min(nums[i],suffix[i+1]);
        }

        for(int i = 0; i<n; i++){
            if(prefix[i] - suffix[i] <= k){
                ans = i;
                break;
            }
        }

        return ans;
        
    }
};