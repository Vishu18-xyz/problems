class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int longest = 0;
        int count = 0;
        int n = nums.size();
        int first = 0;
        int second = 0;

        unordered_map<int,int> freq;

        while(second<n){
           int num = nums[second];

           freq[num]++;

           while(freq[num] > k){
               freq[nums[first]]--;

                if(freq[num] == 0){
                   freq.erase(num);
               }
               first++;
               count--;
           }
           count++;
           second++;
           longest = max(count,longest);
        }
        return longest;
    }
};