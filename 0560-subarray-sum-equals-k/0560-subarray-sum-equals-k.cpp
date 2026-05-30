class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n+1,0);
        int count = 0;

        for(int i = 0; i<n; i++){
            prefix[i+1] = prefix[i] + nums[i]; 
        }
        for(int i = 0; i<n; i++){
            int sum = 0;
            for( int j = i+1; j<=n; j++){
                if(prefix[j] - prefix[i] == k){
                    count++;
                }
            }
        }

        return count;
    }
};