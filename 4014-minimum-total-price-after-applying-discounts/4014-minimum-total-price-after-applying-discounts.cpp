class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());

        int i = 0;
        int n = prices.size();
        int m = discounts.size();
        double ans = 0;

        while (i < n && i < m) {
            ans += prices[i]*(100.0-discounts[i]) / 100.0;
            i++;
        }

        while (i < n) {
            ans += prices[i];
            i++;
        }

        return ans;
    }
};