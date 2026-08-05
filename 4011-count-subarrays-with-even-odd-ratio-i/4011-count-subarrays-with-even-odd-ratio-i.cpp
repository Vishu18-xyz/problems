class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
         int n = nums.size();

        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2)
                pref[i + 1] = pref[i] + a;
            else
                pref[i + 1] = pref[i] - b;
        }

        long long ans = 0;

        for (int i = 0; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (pref[j] >= pref[i])
                    ans++;
            }
        }

        return ans;
    }
};