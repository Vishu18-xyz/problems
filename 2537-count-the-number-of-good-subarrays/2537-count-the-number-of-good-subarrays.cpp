class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;

        int l = 0;
        int r = 0;
        long long pairs = 0;
        long long ans = 0;

        while(r<n){
           int num = nums[r];
           pairs += freq[num];
           freq[num]++;

           while(pairs >= k){
              ans+=n-r;
              freq[nums[l]]--;
              pairs -= freq[nums[l]];
              l++;
           }
           r++;
        }

        return ans;
    }
};