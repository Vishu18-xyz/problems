class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0;
        int end = 0;
        int sum = 0;
        unordered_map<int,int> freq;
        int ans = INT_MAX;

        while(end<n){
            freq[nums[end]]++;
            if(freq[nums[end]] == 1){
                sum+=nums[end];
            }
            while(sum>=k){
               ans = min(ans,end-start+1);
               freq[nums[start]]--;
               if(freq[nums[start]] == 0){
                 sum -= nums[start];
               }
               start++;
            }
            end++;
        }
        if(ans == INT_MAX){
            return -1;
        }
        else{
            return ans;
        }
    }
};