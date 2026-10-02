class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> freq;

        int ans = -1;
        int maxFreq = 0;

        for (int num : nums) {
            if (num % 2 != 0) continue;

            int count = ++freq[num];

            if (count > maxFreq || (count == maxFreq && num < ans)) {
                maxFreq = count;
                ans = num;
            }
        }

        return ans;
    }
};