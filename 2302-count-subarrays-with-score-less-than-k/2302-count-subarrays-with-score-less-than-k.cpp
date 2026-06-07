class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long prefix = 0;
        long long count = 0;
        long long start = 0;
        long long end = 0;

        while(end < n){
            prefix = prefix + nums[end];
            long long score = prefix*(end-start+1);

            while(score >= k && start <= end){
                prefix -= nums[start];
                start++;
                score = prefix*(end-start+1);
            }
            count += (end-start)+1;
            end++;
        }

        return count;
        
    }
};